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
void Animate_lane(vector<unique_ptr<Object>> &vector, sf::Time &time, int &element, bool &is_chosen, sf::RenderWindow &window, sf::Vector2f pos, int t, Object &tram, int &score, bool &empowered){
    if(time.asSeconds() > t){
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
void Object::Change_lane(sf::Time &time, bool &change, int &a){
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

