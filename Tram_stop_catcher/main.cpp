#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <headers.hpp>
#include <cstdlib>

using namespace std;

int main()
{
//    Moving_object tram(5);
//    tram.setPosition(sf::Vector2f(240.0, 100.0));
//    Moving_object::Moving_object(int a) : Object("textures//placeholder.png"){
//    }
//    void Moving_object::Set_direction(sf::Vector2f direction){
//        velocity = direction * speed;
//    }
//    void Moving_object::Move(){
//        sprite_.move(velocity.x, velocity.y);
//    }
//    tram.Set_direction(direction);
//    tram.Move();
//    tram.Draw(window);
    //Input handling
//    sf::Vector2f direction = {0.0f, 0.0f};
//    if(event.type == event.KeyPressed){
//        if(event.key.code == sf::Keyboard::Up){
//            direction.y -= 1.0f;
//        }
//        if(event.key.code == sf::Keyboard::Down){
//            direction.y += 1.0f;
//        }
//        if(event.key.code == sf::Keyboard::Right){
//            direction.x += 1.0f;
//        }
//        if(event.key.code == sf::Keyboard::Left){
//            direction.x -= 1.0f;
//        }
//    }
//    class Moving_object : public Object{
//    protected:
//        float speed = 0.05;
//        sf::Vector2f velocity = {0.0f, 0.05f};
//    public:
//        Moving_object(int);
//        void Set_direction(sf::Vector2f);
//        void Move();
//    };

    //Objects
    Object background("textures//background_easy.png", sf::Vector2f(0, 0));
    Object obstacle1("textures//placeholder.png", sf::Vector2f(40.0, 800.0));
    Object obstacle2("textures//placeholder2.png", sf::Vector2f(40.0, 800.0));

    //vector of pointers to our objects
    vector<unique_ptr<Object>>obstacles;
    auto s1 = make_unique<Object>(obstacle1);
    auto s2 = make_unique<Object>(obstacle2);
    obstacles.emplace_back(move(s1));
    obstacles.emplace_back(move(s2));

    //Set clock and open window
    sf::Clock clock;
    sf::Time time;
    sf::Time zero;
    bool is_chosen = false;
    int element;
    sf::Vector2f position;
    sf::RenderWindow window(sf::VideoMode(600.0, 800.0), "Tram Stop Catcher");

    //While Window is Open
    while (window.isOpen()) {

        //random number generator
        int a = (rand()%10) + 1;
        //int b = (rand()%10) + 1;//

            //Closing window
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here
            background.Draw(window);

            if(time.asSeconds() > 7){
               element = Choose_element(a);
               is_chosen = true;
               time = zero;
            }
            if(is_chosen == true){
                cout << element << endl;
                obstacles[element]->Draw(window);
                obstacles[element]->Move();
                position = obstacles[element]->Get_position();
                if(position.y <= -160.0){
                    obstacles[element]->Set_position(sf::Vector2f(40.0, 800.0));
                    is_chosen = false;
                }
            }

            // end the current frame
            window.display();
            time = time + clock.restart();
        }

        return 0;

}
