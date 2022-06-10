#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <headers.hpp>

using namespace std;

Object::Object(string file, sf::Vector2f position){
    texture_.loadFromFile(file);
    sprite_.setTexture(texture_);
    sprite_.setPosition(position);
}

void Object::Draw(sf::RenderWindow &window){
    window.draw(sprite_);
}
void Object::Move(){
    sprite_.move(x, -y);
}
void Object::Set_position(sf::Vector2f position){
    sprite_.setPosition(position);
}
int Choose_element(int a){
    if(a <= 1){
        return 3;
    }
    if(a > 1 && a <= 4){
        return 0;
    }
    if(a > 4 && a <= 7){
        return 1;
    }
    if(a > 7 && a <= 10){
        return 2;
    }
}
sf::Vector2f Object::Get_position(){
    return sprite_.getPosition();
}
sf::FloatRect Object::Get_bounds(){
    return sprite_.getGlobalBounds();
}
void Object::Set_sprite(string file){
    texture_.loadFromFile(file);
    sprite_.setTexture(texture_);
}
vector<unique_ptr<Object>> Make_vector(Object ob1, Object ob2, Object ob3, Object ob4){
    vector<unique_ptr<Object>>obstacles;
    auto s1 = make_unique<Object>(ob1);
    auto s2 = make_unique<Object>(ob2);
    auto s3 = make_unique<Object>(ob3);
    auto s4 = make_unique<Object>(ob4);
    obstacles.emplace_back(move(s1));
    obstacles.emplace_back(move(s2));
    obstacles.emplace_back(move(s3));
    obstacles.emplace_back(move(s4));
    return obstacles;
}
void Animate_lane(vector<unique_ptr<Object>> &vector, sf::Time &time, int &element, bool &is_chosen, sf::RenderWindow &window, sf::Vector2f pos, double speed, Object &tram, int &score, bool &empowered){
    if(time.asSeconds() > speed){
       int random_number = (rand()%10) + 1;
       element = Choose_element(random_number);
       is_chosen = true;
       sf::Time zero;
       time = zero;
    }
    if(is_chosen == true){
        vector[element]->Draw(window);
        vector[element]->Move();
        //if object moved out of the window
        sf::Vector2f position = vector[element]->Get_position();
        if(position.y <= -160.0){
            vector[element]->Set_position(pos);
            is_chosen = false;
        }
        //if object hits tram
        sf::FloatRect tram_bounds = tram.Get_bounds();
        sf::FloatRect object_bounds = vector[element]->Get_bounds();
        if(object_bounds.intersects(tram_bounds)){
            if(element == 0){
                vector[element]->Set_position(pos);
                is_chosen = false;
                score = score + 1;
            }
            if(element == 1 || element == 2){
                if(empowered == false){
                    window.close();
                }
                if(empowered == true){
                    vector[element]->Set_position(pos);
                    is_chosen = false;
                }
            }
            if(element == 3){
                vector[element]->Set_position(pos);
                is_chosen = false;
                empowered = true;
            }
        }
    }
}
void Object::Set_speed(float a, float b){
    x = a;
    y = b;
}
void Object::Change_lane_easy(sf::Time &time, bool &change, int &a){
    if(time.asSeconds() > 0.25){
    if(change == true){
        if(a == 1){
            sf::Vector2f pos = sprite_.getPosition();
            if(pos.x == 240.0){
                sprite_.setPosition(sf::Vector2f(pos.x - 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 440.0){
                sprite_.setPosition(sf::Vector2f(pos.x - 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
        }
        if(a == 2){
            sf::Vector2f pos = sprite_.getPosition();
            if(pos.x == 240.0){
                sprite_.setPosition(sf::Vector2f(pos.x + 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 40.0){
                sprite_.setPosition(sf::Vector2f(pos.x + 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
        }

    }
    }
}
void Object::Change_lane_medium(sf::Time &time, bool &change, int &a){
    if(time.asSeconds() > 0.25){
    if(change == true){
        if(a == 1){
            sf::Vector2f pos = sprite_.getPosition();
            if(pos.x == 240.0){
                sprite_.setPosition(sf::Vector2f(pos.x - 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 440.0){
                sprite_.setPosition(sf::Vector2f(pos.x - 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 640.0){
                sprite_.setPosition(sf::Vector2f(pos.x - 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
        }
        if(a == 2){
            sf::Vector2f pos = sprite_.getPosition();
            if(pos.x == 40.0){
                sprite_.setPosition(sf::Vector2f(pos.x + 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 240.0){
                sprite_.setPosition(sf::Vector2f(pos.x + 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 440.0){
                sprite_.setPosition(sf::Vector2f(pos.x + 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
        }

    }
    }
}
void Object::Change_lane_hard(sf::Time &time, bool &change, int &a){
    if(time.asSeconds() > 0.25){
    if(change == true){
        if(a == 1){
            sf::Vector2f pos = sprite_.getPosition();
            if(pos.x == 240.0){
                sprite_.setPosition(sf::Vector2f(pos.x - 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 440.0){
                sprite_.setPosition(sf::Vector2f(pos.x - 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 640.0){
                sprite_.setPosition(sf::Vector2f(pos.x - 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 840.0){
                sprite_.setPosition(sf::Vector2f(pos.x - 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }

        }
        if(a == 2){
            sf::Vector2f pos = sprite_.getPosition();
            if(pos.x == 40.0){
                sprite_.setPosition(sf::Vector2f(pos.x + 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 240.0){
                sprite_.setPosition(sf::Vector2f(pos.x + 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 440.0){
                sprite_.setPosition(sf::Vector2f(pos.x + 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
            if(pos.x == 640.0){
                sprite_.setPosition(sf::Vector2f(pos.x + 200.0, pos.y));
                sf::Time zero;
                time = zero;
            }
        }

    }
    }
}
void Game_easy(){
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
            tram.Change_lane_easy(t, change_lane, direction);
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

}
void Game_medium(){
//Objects
    Object background("textures//background_medium.png", sf::Vector2f(0, 0));

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

    Object obstacle1d("textures//przystanek.png", sf::Vector2f(640.0, 800.0));
    Object obstacle2d("textures//orange.png", sf::Vector2f(640.0, 800.0));
    Object obstacle3d("textures//yellow.png", sf::Vector2f(640.0, 800.0));
    Object obstacle4d("textures//star.png", sf::Vector2f(640.0, 800.0));


    Object tram("textures//tram.png", sf::Vector2f(240.0, 100.0));

//vectors of pointers to our objects and needed out of loop variables

    //lane 1
    vector<unique_ptr<Object>> lane1 = Make_vector(obstacle1a, obstacle2a, obstacle3a, obstacle4a);
    bool is_chosen1 = false;
    int element1 = 0;
    sf::Time time;
    //this function changes the speed of objects, so the game will be harder
    for(int i = 0; i < 4; i++){
        lane1[i]->Set_speed(0, 0.15);
    }

    //lane 2
    vector<unique_ptr<Object>> lane2 = Make_vector(obstacle1b, obstacle2b, obstacle3b, obstacle4b);
    bool is_chosen2 = false;
    int element2 = 0;
    sf::Time time2;
    //this function changes the speed of objects, so the game will be harder
    for(int i = 0; i < 4; i++){
        lane1[i]->Set_speed(0, 0.15);
    }

    //lane 3
    vector<unique_ptr<Object>> lane3 = Make_vector(obstacle1c, obstacle2c, obstacle3c, obstacle4c);
    bool is_chosen3 = false;
    int element3 = 0;
    sf::Time time3;
    //this function changes the speed of objects, so the game will be harder
    for(int i = 0; i < 4; i++){
        lane1[i]->Set_speed(0, 0.15);
    }

    //lane 4
    vector<unique_ptr<Object>> lane4 = Make_vector(obstacle1d, obstacle2d, obstacle3d, obstacle4d);
    bool is_chosen4 = false;
    int element4 = 0;
    sf::Time time4;
    //this function changes the speed of objects, so the game will be harder
    for(int i = 0; i < 4; i++){
        lane1[i]->Set_speed(0, 0.15);
    }

//Set clock and open window
    sf::Clock clock;
    sf::Time t;
    sf::Time empowered_time;
    sf::Time zero;
    sf::RenderWindow window(sf::VideoMode(800.0, 800.0), "Tram Stop Catcher");
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
            tram.Change_lane_medium(t, change_lane, direction);
            tram.Move();

            //lanes
            Animate_lane(lane1, time, element1, is_chosen1, window, sf::Vector2f(40.0, 800.0), 4.5, tram, score, empowered);
            Animate_lane(lane2, time2, element2, is_chosen2, window, sf::Vector2f(240.0, 800.0), 8.5, tram, score, empowered);
            Animate_lane(lane3, time3, element3, is_chosen3, window, sf::Vector2f(440.0, 800.0), 6, tram, score, empowered);
            Animate_lane(lane4, time4, element4, is_chosen4, window, sf::Vector2f(640.0, 800.0), 5.5, tram, score, empowered);

            // end the current frame
            window.display();

            sf::Time reset = clock.restart();
            time = time + reset;
            time2 = time2 + reset;
            time3 = time3 + reset;
            time4 = time4 + reset;
            t = t + reset;
            empowered_time = empowered_time + reset;
            if(score == 15){
                window.close();
            }
        }
}
void Game_hard(){
//Objects
    Object background("textures//background_hard.png", sf::Vector2f(0, 0));

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

    Object obstacle1d("textures//przystanek.png", sf::Vector2f(640.0, 800.0));
    Object obstacle2d("textures//orange.png", sf::Vector2f(640.0, 800.0));
    Object obstacle3d("textures//yellow.png", sf::Vector2f(640.0, 800.0));
    Object obstacle4d("textures//star.png", sf::Vector2f(640.0, 800.0));

    Object obstacle1e("textures//przystanek.png", sf::Vector2f(840.0, 800.0));
    Object obstacle2e("textures//orange.png", sf::Vector2f(840.0, 800.0));
    Object obstacle3e("textures//yellow.png", sf::Vector2f(840.0, 800.0));
    Object obstacle4e("textures//star.png", sf::Vector2f(840.0, 800.0));


    Object tram("textures//tram.png", sf::Vector2f(240.0, 100.0));

//vectors of pointers to our objects and needed out of loop variables

    //lane 1
    vector<unique_ptr<Object>> lane1 = Make_vector(obstacle1a, obstacle2a, obstacle3a, obstacle4a);
    bool is_chosen1 = false;
    int element1 = 0;
    sf::Time time;
    //this function changes the speed of objects, so the game will be harder
    for(int i = 0; i < 4; i++){
        lane1[i]->Set_speed(0, 0.2);
    }

    //lane 2
    vector<unique_ptr<Object>> lane2 = Make_vector(obstacle1b, obstacle2b, obstacle3b, obstacle4b);
    bool is_chosen2 = false;
    int element2 = 0;
    sf::Time time2;
    //this function changes the speed of objects, so the game will be harder
    for(int i = 0; i < 4; i++){
        lane1[i]->Set_speed(0, 0.2);
    }

    //lane 3
    vector<unique_ptr<Object>> lane3 = Make_vector(obstacle1c, obstacle2c, obstacle3c, obstacle4c);
    bool is_chosen3 = false;
    int element3 = 0;
    sf::Time time3;
    //this function changes the speed of objects, so the game will be harder
    for(int i = 0; i < 4; i++){
        lane1[i]->Set_speed(0, 0.2);
    }

    //lane 4
    vector<unique_ptr<Object>> lane4 = Make_vector(obstacle1d, obstacle2d, obstacle3d, obstacle4d);
    bool is_chosen4 = false;
    int element4 = 0;
    sf::Time time4;
    //this function changes the speed of objects, so the game will be harder
    for(int i = 0; i < 4; i++){
        lane1[i]->Set_speed(0, 0.2);
    }

    //lane 5
    vector<unique_ptr<Object>> lane5 = Make_vector(obstacle1e, obstacle2e, obstacle3e, obstacle4e);
    bool is_chosen5 = false;
    int element5 = 0;
    sf::Time time5;
    //this function changes the speed of objects, so the game will be harder
    for(int i = 0; i < 4; i++){
        lane1[i]->Set_speed(0, 0.2);
    }

//Set clock and open window
    sf::Clock clock;
    sf::Time t;
    sf::Time empowered_time;
    sf::Time zero;
    sf::RenderWindow window(sf::VideoMode(1000.0, 800.0), "Tram Stop Catcher");
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
            tram.Change_lane_hard(t, change_lane, direction);
            tram.Move();

            //lanes
            Animate_lane(lane1, time, element1, is_chosen1, window, sf::Vector2f(40.0, 800.0), 3.5, tram, score, empowered);
            Animate_lane(lane2, time2, element2, is_chosen2, window, sf::Vector2f(240.0, 800.0), 6.5, tram, score, empowered);
            Animate_lane(lane3, time3, element3, is_chosen3, window, sf::Vector2f(440.0, 800.0), 4.5, tram, score, empowered);
            Animate_lane(lane4, time4, element4, is_chosen4, window, sf::Vector2f(640.0, 800.0), 3.5, tram, score, empowered);
            Animate_lane(lane5, time5, element5, is_chosen5, window, sf::Vector2f(840.0, 800.0), 5.5, tram, score, empowered);

            // end the current frame
            window.display();

            sf::Time reset = clock.restart();
            time = time + reset;
            time2 = time2 + reset;
            time3 = time3 + reset;
            time4 = time4 + reset;
            time5 = time5 + reset;
            t = t + reset;
            empowered_time = empowered_time + reset;
            if(score == 20){
                window.close();
            }
        }
}

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        // handle error
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Easy");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Medium");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Hard");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

    selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}
