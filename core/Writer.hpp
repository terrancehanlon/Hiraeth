#ifndef WRITER_HPP
#define WRITER_HPP

#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
class Writer{

    struct stickfigure{
        sf::CircleShape head;
        sf::RectangleShape body;
        sf::RectangleShape leftArm;
        sf::RectangleShape rightArm;
        sf::RectangleShape leftLeg;
        sf::RectangleShape rightLeg;
    };  

    private:
        sf::Font font;
        sf::Text text;

        std::vector<stickfigure*> people;

    public:

        Writer();
        int numOfPeople = 0;

        void write(std::string text, std::string type);
        void render(sf::RenderWindow *window);

        void renderHealth(sf::RenderWindow* window, int health[], int people);
        void renderPeople(sf::RenderWindow *window, int people);

        void drawPassengers(int num);
        void updatePeople(int num);
        void updateSticks(int val);
        Writer::stickfigure* createStick();


};


#endif