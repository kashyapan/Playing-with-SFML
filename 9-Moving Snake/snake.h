#pragma once

#include<iostream>
#include<list>
#include<SFML/Graphics.hpp>

#define IMG_HEIGHT 15 
#define IMG_WIDTH 15 
#define NEGATIVE -1
#define POSITIVE  1

void moveSnake(std::list<sf::Sprite> &snake , sf::Vector2f &head) ;
void growSnake(std::list<sf::Sprite> &snake) ;
void arrowKeyControl(sf::Vector2f &headPosition) ;


sf::Event event ;

//Direction and variable holds information about moving direction of snake
float  direction = IMG_WIDTH ;
float *variable = NULL ;