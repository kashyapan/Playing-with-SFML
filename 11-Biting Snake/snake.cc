#include "snake.h"
#include "static-functions.cc"

void moveSnake(std::list<sf::Sprite> &snake , sf::Vector2f &head) 
{
    //Moving a snake is as simple as adding a node in front and deleting node in end
    //Constant time updation    

    snake.push_front(*snake.begin()) ;
    snake.front().setPosition(head) ;
    snake.pop_back();



//    std::cout << "x = "<< head.x << " y = "<< head.y << std::endl ;
 
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

    if(variable) 
	{
        (*variable) = (*variable) + direction ;	
		
	}

}

void putFood(sf::Sprite &food , sf::Vector2u bound) 
{
	int x , y ,tem;

	x = rand() % bound.x ;
	y = rand() % bound.y ;
	 

	sf::Vector2f position(x,y);
	food.setPosition(position);
}

bool isIntersecting(sf::Vector2f x, sf::Vector2f y)
{
	std::cout << "Snake x = "<<x.x<<" y = "<<x.y<<"\n" ;
	std::cout << "Food x = "<<y.x<<" y = "<<y.y<<"\n" ;	

	return((positive(x.x - y.x) <= IMG_WIDTH) && (positive(x.y - y.y) <= IMG_WIDTH) ) ;

//	return (x == y) ;
}

bool isMatch(sf::Vector2f x, sf::Vector2f y)
{
	std::cout << "Snake x = "<<x.x<<" y = "<<x.y<<"\n" ;
	std::cout << "Food x = "<<y.x<<" y = "<<y.y<<"\n" ;	

	return((x.x == y.x)  && (x.y == y.y) ) ;

//	return (x == y) ;
}

void handleSnakeBite(std::list<sf::Sprite> &snake ,sf::Vector2f &head)
{
	std::list<sf::Sprite> :: iterator i ;

	for(i = snake.begin() ; i != snake.end() ; ++i )
	{
		if(isMatch(i->getPosition() , head ))
		{
			std::cout<<"Snakes bited" <<"\n" ;
			snake.erase(i , snake.end() );
			break ;
		}
	}
}