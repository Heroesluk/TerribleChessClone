//
// Created boardY heroesluk on 17.12.22.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#define HEIGHT 800
#define WIDTH 800
#define PIECE_HEIGHT (HEIGHT/8)
#define PIECE_WIDTH (WIDTH/8)

#include "Board.h"
#include "SFML/Graphics.hpp"
#include "ColorPalette.h"
#include "UI_Button.h"

using uInt = unsigned int;


class Game {
private:
    uInt boardX;
    uInt boardY;
    ColorPalette palette;
    Board board;
    sf::Font text_font;

    sf::RenderWindow window;
    std::unordered_map<std::string,sf::Texture> textures;
    std::vector<Button> buttons;
    uInt board_render_width, board_render_height;

    int turn{0};

    std::unordered_map<std::string,sf::Texture> LoadTextures();
    std::vector<std::vector<std::string>> GetGameStateString(std::string file_path);
    void SetupUI();

    void ClickToBoardCoords(uInt mouse_x, uInt mouse_y);
    void Draw(const std::vector<std::shared_ptr<Piece>>& piece_map, sf::RenderWindow &Window);
    void DrawUI(sf::RenderWindow &Window);
    void SaveGameState();


public:
    Game();
    void GameLoop();





};

#endif //CHESS_GAME_H
