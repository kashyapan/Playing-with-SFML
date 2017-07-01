#pragma once

#include<iostream>
#include<list>
#include<SFML/Graphics.hpp>

#define IMG_HEIGHT 16 
#define IMG_WIDTH 16
#define NEGATIVE -1
#define POSITIVE  1

void moveSnake(std::list<sf::Sprite> &snake , sf::Vector2f &head) ;
void growSnake(std::list<sf::Sprite> &snake) ;
void arrowKeyControl(sf::Vector2f &headPosition) ;
void putFood(sf::Sprite &food , sf::Vector2u bound)  ;
bool isIntersecting(sf::Vector2f x, sf::Vector2f y);
bool isMatch(sf::Vector2f x, sf::Vector2f y) ;
void handleSnakeBite(std::list<sf::Sprite> &snake ,sf::Vector2f &head) ;
sf::Event event ;

//Direction and variable holds information about moving direction of snake
float  direction = IMG_WIDTH ;
float *variable = NULL ;