#include "Train.hpp"


Train::Train(){
    this->trainSize = 5;
    this->writer = *new Writer();
    this->writer.updatePeople(3);
    int xPos = 50;

    for(int i = 0; i < 10; i++){
        Passenger *p = new Passenger();
        this->passengers.push_back(p);
    }

    for(int i = 0; i < this->trainSize; i++){
        sf::RectangleShape rct = sf::RectangleShape(sf::Vector2f(120, 50));
        rct.setPosition(xPos, 50);
        xPos += 150;
        this->fullTrain.push_back(rct);
        printf("Creating cab number: %d\n", i+1);
    }
};

void Train::update(){
    for(int i = 0; i < trainSize; i++){
        if(this->fullTrain[i].getPosition().x > 1030){
            this->fullTrain[i].setPosition(50, 50);
        }else{
            this->fullTrain[i].move(25.0, 0);
        }
    }

    if(this->damageClock.getElapsedTime().asSeconds() >= 5){
        this->health -= 5;
        this->damageClock.restart();
    }
};

void Train::render(sf::RenderWindow *window){
    for(int i = 0; i < trainSize; i++){
        window->draw(this->fullTrain[i]);
    }
    this->renderText(window);
};

void Train::renderText(sf::RenderWindow *window){
    int _health[2] = {this->health, this->maxHealth};
    this->writer.renderHealth(window, _health, this->passengers.size());
};  
