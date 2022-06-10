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
    void Change_lane_easy(sf::Time &time, bool &change, int &a);
    void Change_lane_medium(sf::Time &time, bool &change, int &a);
    void Change_lane_hard(sf::Time &time, bool &change, int &a);
    sf::FloatRect Get_bounds();
    void Set_sprite(string file);
};
int Choose_element(int a);
vector<unique_ptr<Object>> Make_vector(Object ob1, Object ob2, Object ob3, Object ob4);
void Animate_lane(vector<unique_ptr<Object>> &vector, sf::Time &time, int &element, bool &is_chosen, sf::RenderWindow &window, sf::Vector2f pos, double speed, Object &tram, int &score, bool &empowered);
void Game_easy();
void Game_medium();
void Game_hard();
