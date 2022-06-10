#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <headers.hpp>
#include <cstdlib>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Tram Stop Catcher");

    sf::Texture texture_background;
        if(!texture_background.loadFromFile("background.png")) {
            std::cout << "ERROR" << std::endl;
            return 1; };

        sf::Sprite background;
            texture_background.setRepeated(true);
            background.setTexture(texture_background);
            background.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    sf::Music music;
    if(!music.openFromFile("music/music.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }
    music.play();

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Event menu_case;

        while (window.pollEvent(menu_case))
        {
            switch (menu_case.type)
            {
            case sf::Event::KeyReleased:
                switch (menu_case.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        Game_easy();
                        break;
                    case 1:
                        Game_medium();
                        break;
                    case 2:
                        Game_hard();
                        break;
                    case 3:
                        window.close();
                        break;

                    }

                    break;
                }

                break;
            case sf::Event::Closed:
                window.close();

                break;

            }
        }

        window.clear();

        window.draw(background);

        menu.draw(window);

        window.display();
    }
}
