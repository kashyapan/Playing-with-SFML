#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>

#define NEGATIVE -1
#define POSITIVE  1

using namespace sf ;
using namespace std; 

int positive(int x)
{
	if(x > 0)
		return x ;
	
	return -x ;
}

int negative(int x)
{
	if(x > 0)
		return -x ;
	
	return x ;
}

int setDir(int magnitude ,int direction)
{
	if(direction > 0)
		return positive(magnitude) ;
	
	return negative(magnitude) ;
}



int main()
{
	//HouseKeeping
	int rad = 10 ;
	int x = 0 , y = 0 , direction = 1 ;
	int *variable = &x;
	
	Clock C ; 
	Time time = C.getElapsedTime() ;

	RenderWindow window(VideoMode(100 , 200), "Snake") ;

	Event e ;

	CircleShape circle(rad) ;
	circle.setFillColor(Color::Red) ;
	

	while(window.isOpen())
	{

		while(window.pollEvent(e))
		{
			if(e.type == Event::Closed)
			{
				window.close() ;
			}
			
			if(e.type == Event::KeyPressed)
			{

				if(e.key.code == Keyboard::Right)
				{
					variable = &x ;
					direction = setDir( direction , POSITIVE ) ;
				}
				
				if(e.key.code == Keyboard::Left)
				{
					variable = &x ;
					direction = setDir( direction , NEGATIVE ) ;				
				}
				
				//Negative Axis. Y axis is upside down
				if(e.key.code == Keyboard::Up)
				{
					variable = &y ;
					direction = setDir( direction , NEGATIVE ) ;
				}
				
				if(e.key.code == Keyboard::Down)
				{
					variable = &y ;
					direction = setDir( direction , POSITIVE ) ;
				}

			}
			
		}

		time = C.getElapsedTime() ;
		//Move ball every 200 Milliseconds
		if(time.asMilliseconds() % 200 == 0)
		{
							
				(*variable) = (*variable) + direction ;

				//Check if ball is out of window size
				x = x % window.getSize().x ;
				y = y % window.getSize().y ;

				//Debugging		
				cout << "x "<<x<<" y "<<y<<endl ;
				cout << "Window size "<<window.getSize().x<<" * "<<window.getSize().y <<endl ;
		}

		circle.setPosition(x,y) ;
		window.clear() ;
		window.draw(circle);
		window.display();

	}	
	
	
	return 0 ;
}
