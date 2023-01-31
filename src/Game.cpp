#include "Game.h"
#include "cmath"
#include "iostream"
#include <typeinfo>

void Game::ClickToBoardCoords(uInt mouse_x, uInt mouse_y) {
    boardX = floor(mouse_x / PIECE_WIDTH);
    boardY = floor(mouse_y / PIECE_HEIGHT);

}

Game::Game() : window(sf::VideoMode(1500, HEIGHT), "My window") {

    board.SetupBoardPieces();
    textures = LoadTextures();


    if(!text_font.loadFromFile("arial.ttf")) {
        exit(2);
    }


    SetupUI();
    board_render_width = 800;
    board_render_width = 800;

}



void Game::Draw(const std::vector<std::shared_ptr<Piece>>& piece_map, sf::RenderWindow &Window) {
    auto[window_width,window_height] =  Window.getSize();

    ColorPalette colors(sf::Color(102, 204, 102),
                        sf::Color(255, 243, 230),
                        sf::Color(255, 0, 103),
                        sf::Color(38, 38, 38));

    sf::RectangleShape tile(sf::Vector2f(PIECE_WIDTH, PIECE_HEIGHT));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            tile.setPosition(i * PIECE_WIDTH, j * PIECE_HEIGHT);

            if (i % 2 + j % 2 == 1) { tile.setFillColor(colors.white_tile); }
            else tile.setFillColor(colors.black_tile);
            Window.draw(tile);

        }


    }


    std::string file_type = ".png";
    auto knight = textures["KnightW"];

    auto[texture_width, texture_height] = knight.getSize();
    float width_scale = (float)100 /(float) texture_width;
    float height_scale = (float)100/ (float)texture_height;

    for (auto &it: piece_map) {
        if (it != nullptr) {
            //sf::RectangleShape piece_sprite(sf::Vector2f(PIECE_WIDTH, PIECE_HEIGHT));
            sf::Sprite piece_sprite;
            auto pc = it->GetPieceName()+ "W";
            if(it->GetColor()){
                piece_sprite.setTexture(textures[it->GetPieceName() + "B"]);
            }
            else{
                piece_sprite.setTexture(textures[it->GetPieceName() + "W"]);
            }
            piece_sprite.setScale(width_scale,height_scale);

            auto y = (float) it->pos_y;
            auto x = (float) it->pos_x;
            piece_sprite.setPosition(x * PIECE_WIDTH, y * PIECE_WIDTH);
            Window.draw(piece_sprite);

        }
    }
    //if holding a piece, highlight all possible moves
    sf::RectangleShape pos_move(sf::Vector2f(30, 30));
    pos_move.setFillColor(colors.white_piece);


    if(board.GetCurrentlyHeld()!= nullptr){
        auto takes = board.GetCurrentlyHeld()->LegalTakes(board.ReturnPiecesPositions());
        auto moves = board.GetCurrentlyHeld()->LegalMoves(board.ReturnPiecesPositions());
        takes.insert(takes.end(),moves.begin(),moves.end());

        for(auto mv: takes){
            int y = mv/8;
            int x = mv%8;

            pos_move.setPosition((x*PIECE_WIDTH)+PIECE_WIDTH/3, (y*PIECE_HEIGHT)+PIECE_HEIGHT/3);
            Window.draw(pos_move);


        }
    }

}

void Game::GameLoop() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonPressed) {
                auto x = event.mouseButton.x;
                auto y = event.mouseButton.y;
                if(x<800){
                    ClickToBoardCoords(x,y);
                    bool moved = board.MakeAction(boardX, boardY, turn % 2);
                    if (moved) {
                        turn += 1;
                    }
                }
                else{
                    for(auto btn: buttons){
                        if(btn.CheckIfClicked(x,y)){

                        }
                    }
                }


            }
        }

        window.clear();
        
        Draw(board.ReturnAllPieces(), window);
        DrawUI(window);

        window.display();
    }


}

std::unordered_map<std::string, sf::Texture> Game::LoadTextures() {

    std::unordered_map<std::string,sf::Texture> textures;

    sf::Texture knight;
    if (!knight.loadFromFile("Knight.png")) {
        exit(2);
    }
    sf::Texture king;
    if (!king.loadFromFile("King.png")) {
        std::cout << 'huj';
        exit(2);
    }

    sf::Texture rook;
    if (!rook.loadFromFile("Rook.png")) {
        exit(2);
    }

    sf::Texture queen;
    if (!queen.loadFromFile("Queen.png")) {
        exit(2);
    }

    sf::Texture pawn;
    if (!pawn.loadFromFile("Pawn.png")) {
        exit(2);
    }
    sf::Texture bishop;
    if (!bishop.loadFromFile("Bishop.png")) {
        exit(2);
    }


    sf::Texture knightB;
    if (!knightB.loadFromFile("KnightB.png")) {
        exit(2);
    }
    sf::Texture kingB;
    if (!kingB.loadFromFile("KingB.png")) {
        exit(2);
    }

    sf::Texture rookB;
    if (!rookB.loadFromFile("RookB.png")) {
        exit(2);
    }

    sf::Texture queenB;
    if (!queenB.loadFromFile("QueenB.png")) {
        exit(2);
    }

    sf::Texture pawnB;
    if (!pawnB.loadFromFile("PawnB.png")) {
        exit(2);
    }
    sf::Texture bishopB;
    if (!bishopB.loadFromFile("BishopB.png")) {
        exit(2);
    }





    textures["KnightW"] = knight;
    textures["KingW"] = king;
    textures["RookW"] = rook;
    textures["BishopW"] = bishop;
    textures["QueenW"] = queen;
    textures["PawnW"] = pawn;

    textures["KnightB"] = knightB;
    textures["KingB"] = kingB;
    textures["RookB"] = rookB;
    textures["BishopB"] = bishopB;
    textures["QueenB"] = queenB;
    textures["PawnB"] = pawnB;

    return textures;



}

void Game::DrawUI(sf::RenderWindow &Window) {


    uInt offset = 800;
    sf::RectangleShape menu_back;
    menu_back.setSize(sf::Vector2f(800,800));
    menu_back.setFillColor(sf::Color(255,0,0));
    menu_back.setPosition(offset,0);
    Window.draw(menu_back);





    for(auto button: buttons){
        sf::Text text = button.ReturnText();
        text.setFont(text_font);
        sf::RectangleShape btn1 = button.ReturnButton();

        Window.draw(btn1);
        Window.draw(text);

    }







}

void Game::SetupUI() {
    Button b1(800, 300, 100,50, "Dziala",1);
    Button b2(800, 500, 100,50, "Drugi",2);
    Button b3(800, 700, 100,50, "Trzeci",3);

    buttons.push_back(b1);
    buttons.push_back(b2);
    buttons.push_back(b3);




}




