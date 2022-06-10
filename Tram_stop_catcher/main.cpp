#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <headers.hpp>
#include <cstdlib>

using namespace std;

int main()
{

//Objects
    Object background("textures//background_easy.png", sf::Vector2f(0, 0));

    Object obstacle1a("textures//przystanek.png", sf::Vector2f(40.0, 800.0));
    Object obstacle2a("textures//orange.png", sf::Vector2f(40.0, 800.0));
    Object obstacle3a("textures//yellow.png", sf::Vector2f(40.0, 800.0));
    Object obstacle4a("textures//star.png", sf::Vector2f(40.0, 800.0));

    Object obstacle1b("textures//przystanek.png", sf::Vector2f(240.0, 800.0));
    Object obstacle2b("textures//orange.png", sf::Vector2f(240.0, 800.0));
    Object obstacle3b("textures//yellow.png", sf::Vector2f(240.0, 800.0));
    Object obstacle4b("textures//star.png", sf::Vector2f(240.0, 800.0));

    Object obstacle1c("textures//przystanek.png", sf::Vector2f(440.0, 800.0));
    Object obstacle2c("textures//orange.png", sf::Vector2f(440.0, 800.0));
    Object obstacle3c("textures//yellow.png", sf::Vector2f(440.0, 800.0));
    Object obstacle4c("textures//star.png", sf::Vector2f(440.0, 800.0));


    Object tram("textures//tram.png", sf::Vector2f(240.0, 100.0));

//vectors of pointers to our objects and needed out of loop variables

    //lane 1
    vector<unique_ptr<Object>> lane1 = Make_vector(obstacle1a, obstacle2a, obstacle3a, obstacle4a);
    bool is_chosen1 = false;
    int element1 = 0;
    sf::Time time;

    //lane 2
    vector<unique_ptr<Object>> lane2 = Make_vector(obstacle1b, obstacle2b, obstacle3b, obstacle4b);
    bool is_chosen2 = false;
    int element2 = 0;
    sf::Time time2;

    //lane 3
    vector<unique_ptr<Object>> lane3 = Make_vector(obstacle1c, obstacle2c, obstacle3c, obstacle4c);
    bool is_chosen3 = false;
    int element3 = 0;
    sf::Time time3;

//Set clock and open window
    sf::Clock clock;
    sf::Time t;
    sf::Time zero;
    sf::Time empowered_time;
    sf::RenderWindow window(sf::VideoMode(600.0, 800.0), "Tram Stop Catcher");
    int score = 0;
    bool empowered;
    bool is_clock_set = false;

//While Window is Open
    while (window.isOpen()) {

            //Closing window
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        // empowered
            if(empowered == true){
                if(is_clock_set == false){
                    empowered_time = zero;
                    is_clock_set = true;
                    tram.Set_sprite("textures//gamma.png");
                }
                if(empowered_time.asSeconds() > 6){
                    empowered = false;
                    is_clock_set = false;
                    tram.Set_sprite("textures//tram.png");
                }
            }
        // input handling
            float x = 0;
            float y = 0;
            bool change_lane = false;
            int direction = 0;
             if(event.type == event.KeyPressed){
                    if(event.key.code == sf::Keyboard::Up){
                        y = 0.05;
                    }
                    if(event.key.code == sf::Keyboard::Down){
                        y = -0.05;
                    }
                    if(event.key.code == sf::Keyboard::Left){
                        change_lane = true;
                        direction = 1;
                    }
                    if(event.key.code == sf::Keyboard::Right){
                        change_lane = true;
                        direction = 2;
                    }
                }


            // clear the window with black color
            window.clear(sf::Color::Black);

        // draw everything here

            //background
            background.Draw(window);

            //tram
            tram.Draw(window);
            tram.Set_speed(x, y);
            tram.Change_lane(t, change_lane, direction);
            tram.Move();

            //lanes
            Animate_lane(lane1, time, element1, is_chosen1, window, sf::Vector2f(40.0, 800.0), 7, tram, score, empowered);
            Animate_lane(lane2, time2, element2, is_chosen2, window, sf::Vector2f(240.0, 800.0), 13, tram, score, empowered);
            Animate_lane(lane3, time3, element3, is_chosen3, window, sf::Vector2f(440.0, 800.0), 9, tram, score, empowered);

            // end the current frame
            window.display();
            sf::Time reset = clock.restart();
            time = time + reset;
            time2 = time2 + reset;
            time3 = time3 + reset;
            t = t + reset;
            empowered_time = empowered_time + reset;
            if(score == 10){
                window.close();
            }
        }

        return 0;

}
