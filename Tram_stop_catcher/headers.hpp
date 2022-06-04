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
    void Set_speed(float a, float b);
    void Change_lane(sf::Time &time, bool &change, int &a);
};
int Choose_element(int a);
vector<unique_ptr<Object>> Make_vector(Object ob1, Object ob2);
void Animate_lane(vector<unique_ptr<Object>> &vector, sf::Time &time, int &element, bool &is_chosen, sf::RenderWindow &window, sf::Vector2f pos, int t);
