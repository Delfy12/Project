#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Object : public sf::Sprite{
protected:
    sf::Texture texture_;
    sf::Sprite sprite_;
    float x = 0;
    float y = 0.1;
public:
    Object(string file, sf::Vector2f position);
    void Draw(sf::RenderWindow &window);
    void Move();
    void Set_position(sf::Vector2f);
    sf::Vector2f Get_position();
};
int Choose_element(int a);
void Spawn_object(int a, int b, vector<unique_ptr<Object>>vector);

