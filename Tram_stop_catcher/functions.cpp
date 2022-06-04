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
    if(a <= 5){
        return 0;
    }
    if(a > 5 && a <= 10){
        return 1;
    }
}
sf::Vector2f Object::Get_position(){
    return sprite_.getPosition();
}
vector<unique_ptr<Object>> Make_vector(Object ob1, Object ob2){
    vector<unique_ptr<Object>>obstacles;
    auto s1 = make_unique<Object>(ob1);
    auto s2 = make_unique<Object>(ob2);
    obstacles.emplace_back(move(s1));
    obstacles.emplace_back(move(s2));
    return obstacles;
}
void Animate_lane(vector<unique_ptr<Object>> &vector, sf::Time &time, int &element, bool &is_chosen, sf::RenderWindow &window, sf::Vector2f pos, int t){
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
        sf::Vector2f position = vector[element]->Get_position();
        if(position.y <= -160.0){
            vector[element]->Set_position(pos);
            is_chosen = false;
        }
    }
}


