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
void Reset_position(){

}
