#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>

using namespace sf ;
using namespace std; 


int main()
{
	//HouseKeeping
	int rad = 10 ;
	int x = 0 , y = 0 ;
	
	RenderWindow window(VideoMode(400 , 400), "My Shapes") ;
	RenderWindow alertBox(VideoMode(400,100) , "Read it to use" ,Style::Close);	
	
	Event e ;

	Font sans ;
	Text t ;
	sans.loadFromFile("./fonts/SFCartoonist.ttf") ;
	t.setFont(sans);	
	t.setString("Use Arrow Keys to move , + and - to grow/shrink ball");
	t.setCharacterSize(20) ;
	t.setColor(Color::Red);

	//Instruction Box
	while(alertBox.isOpen())
	{
		while(alertBox.pollEvent(e))
		{
			if(e.type == Event::Closed)
			{
				alertBox.close() ;
			}
		}
		alertBox.clear();
		alertBox.draw(t);
		alertBox.display();	
	}	


	//Only After Instruction Box is closed main box will open
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
					x++ ;
				}
				if(e.key.code == Keyboard::Left)
				{
					x-- ;
				}
				if(e.key.code == Keyboard::Up)
				{
					y-- ;
				}
				if(e.key.code == Keyboard::Down)
				{
					y++ ;
				}
				if(e.key.code == Keyboard::Add)
				{
					rad++ ;
				}
				if(e.key.code == Keyboard::Subtract)
				{
					rad-- ;
				}				
																
			}
			
		}
			
		circle.setPosition(x,y) ;
		circle.setRadius(rad);
				
		window.clear() ;
		window.draw(circle);
		window.display();

	}	
	

	
		
	return 0 ;
}
