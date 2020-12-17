#include "Writer.hpp"


Writer::Writer(){
    if(!this->font.loadFromFile("Assets/arial.ttf")){
        printf("error getting font\n");
    };
    this->text.setFont(this->font);
    this->text.setCharacterSize(24);
    this->text.setColor(sf::Color::White);
    this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
};


void Writer::render(sf::RenderWindow *window){
    window->draw(this->text);
};

void Writer::renderHealth(sf::RenderWindow *window, int health[], int people){
    this->text.setString(std::to_string(health[0]) + "/" 
                        + std::to_string(health[1]) + "\tPeople abord: " + std::to_string(people));
    this->text.setPosition(0,0);
    window->draw(this->text);
        for(int i = 0; i < this->numOfPeople; i++){
        printf("drawing people\n");
        window->draw(this->people.at(i)->head);
        window->draw(this->people.at(i)->body);
        window->draw(this->people.at(i)->leftArm);
        window->draw(this->people.at(i)->rightArm);
        window->draw(this->people.at(i)->rightLeg);
        window->draw(this->people.at(i)->leftLeg);

    }
};

void Writer::renderPeople(sf::RenderWindow *window, int people){
    this->text.setString(std::to_string(people));
    this->text.setPosition(sf::Vector2f(10, 150));
    window->draw(this->text);
};

void Writer::drawPassengers(int num){

};

Writer::stickfigure* Writer::createStick(){
    printf("in create stick\n");
    Writer::stickfigure *s1 = new Writer::stickfigure;
    s1->head = sf::CircleShape(15);
    s1->head.setPosition(150,150);
    s1->body = sf::RectangleShape(sf::Vector2f(5, 55));
    s1->body.setPosition(160, 155);
    s1->leftArm = sf::RectangleShape(sf::Vector2f(3,25));
    s1->leftArm.setPosition(160, 185);
    s1->leftArm.rotate(45);
    s1->rightArm = sf::RectangleShape(sf::Vector2f(3,25));
    s1->rightArm.setPosition(160,185);
    s1->rightArm.rotate(315);
    s1->leftLeg = sf::RectangleShape(sf::Vector2f(3,25));
    s1->leftLeg.setPosition(160,205);
    s1->leftLeg.rotate(325);
    s1->rightLeg = sf::RectangleShape(sf::Vector2f(3,25));
    s1->rightLeg.setPosition(160, 205);
    s1->rightLeg.rotate(35);
    return s1;
}

void Writer::updateSticks(int val){
    if(val == 3){
        // this->people.clear();
        for(int i = 0; i < 3; i++){
            this->people.push_back(this->createStick());
        }
        printf("size: %d\n", this->people.size());
        this->people.at(1)->head.move(15.0,0);
        this->people.at(1)->body.move(15.0,0);
        this->people.at(1)->leftArm.move(15.0,0);
        this->people.at(1)->rightArm.move(15.0,0);
        this->people.at(1)->leftLeg.move(15.0,0);
        this->people.at(1)->rightLeg.move(15.0,0);

        this->people.at(2)->head.move(30.0,0);
        this->people.at(2)->body.move(30.0,0);
        this->people.at(2)->leftArm.move(30.0,0);
        this->people.at(2)->rightArm.move(30.0,0);
        this->people.at(2)->leftLeg.move(30.0,0);
        this->people.at(2)->rightLeg.move(30.0,0);
    }
}
void Writer::updatePeople(int num){
    this->numOfPeople = num;

    if(numOfPeople >= 0 || numOfPeople <= 5){
        this->updateSticks(3);
    }
};