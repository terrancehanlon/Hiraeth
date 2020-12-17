#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Writer.hpp"
#include "Passenger.hpp"

class Train {

    private:
        sf::RectangleShape trainShape;
        std::vector<sf::RectangleShape> fullTrain;
        std::vector<Passenger*> passengers;
        Writer writer;
        float writerCords[2] = {10, 10};
        int trainSize = 5;
        int health = 100;
        int maxHealth = 100;

    public:
        Train();
        
        sf::Clock damageClock;
        float lastDamaged = 0;
        void update();
        void render(sf::RenderWindow *window);
        void renderText(sf::RenderWindow *window);
        
};

#endif