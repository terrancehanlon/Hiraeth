#ifndef GAME_HPP
#define GAME_HPP

#include "../Lib/Imports.h"
#include "Train.hpp"

class Game{

    private:
        sf::RenderWindow *window;
        sf::RectangleShape rectShape;
        sf::Time frameTime;
        sf::Clock frameClock;
        Train train;

        std::vector<sf::RectangleShape*> shapes;
        int shapes_size = 0;

    public:
        Game();

        void init();
        void update(sf::Clock *dt);
        void render();
        void run();



};


#endif