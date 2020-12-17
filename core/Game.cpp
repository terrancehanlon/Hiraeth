#include "Game.hpp"


Game::Game(){
    this->init();
    this->window = new sf::RenderWindow(sf::VideoMode(1024,1024), "Train", sf::Style::Close);
    // this->frameTime
};


void Game::init(){

    //form box1:
    sf::RectangleShape *box = new sf::RectangleShape(sf::Vector2f(800, 300));
    box->setFillColor(sf::Color::Transparent);
    box->setOutlineColor(sf::Color::Red);
    box->setOutlineThickness(3);
    box->setPosition(150, 150);

    this->shapes.push_back(box);

    this->shapes_size++;

};
void Game::update(sf::Clock *dt){
    if(dt->getElapsedTime().asSeconds() > 0.25f){
        train.update();
        dt->restart();
    }
};
void Game::render(){
    this->window->clear();
    this->train.render(this->window);
    for(int i = 0; i < this->shapes_size; i++){
        this->window->draw(*this->shapes[i]);
    }
    this->window->display();
};

void Game::run(){
    // sf::Time time = frameClock.restart();
    sf::Clock clck;
    sf::Time elapsed;
    while(this->window->isOpen()){
        this->update(&clck);
        this->render();
    }
}