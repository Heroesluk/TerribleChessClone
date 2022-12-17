#include <SFML/Graphics.hpp>
#include "iostream"
//4x4 grid
#include "vector"









int main()
{

    sf::RenderWindow window(sf::VideoMode(800,600), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}