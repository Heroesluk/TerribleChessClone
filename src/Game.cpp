#include "Game.h"
#include "cmath"
#include "iostream"
#include <typeinfo>

void Game::ClickToBoardCoords(uInt mouse_x, uInt mouse_y) {
    boardX = floor(mouse_x / PIECE_WIDTH);
    boardY = floor(mouse_y / PIECE_HEIGHT);

}

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "My window") {

    board.SetupBoardPieces();
    textures = LoadTextures();

}



void Game::Draw(const std::vector<std::shared_ptr<Piece>>& piece_map, sf::RenderWindow &Window) {
    auto[window_width,window_height] =  Window.getSize();


    ColorPalette colors(sf::Color(102, 204, 102),
                        sf::Color(255, 243, 230),
                        sf::Color(255, 43, 103),
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

            float width_scale = (float) ((float) window_width/8)/(float) texture_width;
            float height_scale = (float) ((float) window_height/8)/(float) texture_height;

            piece_sprite.setScale(width_scale,height_scale);

            int y = it->pos_y;
            int x = it->pos_x;
            piece_sprite.setPosition(x * PIECE_WIDTH, y * PIECE_WIDTH);

//            if (it->GetColor()) {
//                piece_sprite.setFillColor(colors.white_piece);
//            } else piece_sprite.setFillColor(colors.black_piece);
            Window.draw(piece_sprite);

        }
    }

    if(board.GetCurrentlyHeld()!= nullptr){
        for(auto mv: board.GetCurrentlyHeld()->LegalTakes(board.ReturnPiecesPositions())){
            sf::RectangleShape tile(sf::Vector2f(mv, mv));
            int y = mv/8;
            int x = mv%8;

            tile.setPosition((x*PIECE_WIDTH)+PIECE_WIDTH/3, (y*PIECE_HEIGHT)+PIECE_HEIGHT/3);
            Window.draw(tile);


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

                //
                ClickToBoardCoords(event.mouseButton.x, event.mouseButton.y);

                bool moved = board.MakeAction(boardX, boardY, turn % 2);
                if (moved) {
                    turn += 1;
                }


            }
        }

        window.clear();
        
        Draw(board.ReturnAllPieces(), window);

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




