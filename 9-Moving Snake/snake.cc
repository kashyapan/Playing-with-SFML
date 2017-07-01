#include "snake.h"
#include "static-functions.cc"

void moveSnake(std::list<sf::Sprite> &snake , sf::Vector2f &head) 
{
    //Moving a snake is as simple as adding a node in front and deleting node in end
    //Constant time updation    

    snake.push_front(*snake.begin()) ;
    snake.front().setPosition(head) ;
    snake.pop_back();

    if(variable)
        (*variable) = (*variable) + direction ;

    std::cout << "x = "<< head.x << " y = "<< head.y << std::endl ;
 
}

void growSnake(std::list<sf::Sprite> &snake)
{
    //Adding a node to list and Fixing position
    sf::Vector2f temp  ;
    temp = snake.back().getPosition() ;
    temp.x -= IMG_WIDTH ;
    snake.push_back(*snake.begin());
    snake.back().setPosition(temp);
    std::cout<<"Snake is "<<snake.size()<<std::endl ;

}


void arrowKeyControl(sf::Vector2f &headPosition)
{

//    std::cout <<"In Function "<<event.key.code<<"\n" ;


    if(event.key.code == sf::Keyboard::Right)
	{
		variable = &headPosition.x ;
		direction = setDir( direction , POSITIVE ) ;
	}
				
	if(event.key.code == sf::Keyboard::Left)
	{
		variable = &headPosition.x ;
		direction = setDir( direction , NEGATIVE ) ;				
	}
				
	//Negative Axis. Y axis is upside down
	if(event.key.code == sf::Keyboard::Up)
	{
		variable = &headPosition.y ;
		direction = setDir( direction , NEGATIVE ) ;
	}
				
	if(event.key.code == sf::Keyboard::Down)
	{
		variable = &headPosition.y ;
		direction = setDir( direction , POSITIVE ) ;
	}

}
