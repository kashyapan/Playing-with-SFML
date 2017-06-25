
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>

using namespace sf ;
using namespace std; 


int main()
{
	RenderWindow window(VideoMode(800,600) , "Write here Randomly" , Style::Default) ;
	
	string displayText = " ";
	
	Text text ;
	Font sans ;
	
	sans.loadFromFile("./fonts/SFCartoonist.ttf") ;

	text.setFont(sans);	
	text.setCharacterSize(24) ;
	text.setColor(Color::Green) ;
	text.setString(displayText);					
	
	while(window.isOpen())
	{

		Event e ;
		
		//Keep looking for events to occur.
		//Event Loop!
		while(window.pollEvent(e))
		{
			//Detect for pressed keys
			if(e.type == Event::KeyPressed)
			{

				//Exit if Esc is pressed
				if(e.key.code == Keyboard::Escape)
				{
					window.close() ;
				}
								
				//Delete Character by reducing str len
				if(e.key.code == Keyboard::BackSpace)
				{
					//Dont erase any more if string is empty (bug fix)
					if(!displayText.empty())
						displayText.erase(displayText.end()-1)  ;								
					
				}	
				
				//Detect Enter Key and add a new line
				if(e.key.code == Keyboard::Return)
				{
					displayText += '\n' ;			
				}
				
			}

			//Check if printable text is Pressed
				
			if( e.type == Event::TextEntered )
			{
				//Takes only ASCII Values - BackSpace
				if(e.text.unicode < 128 && e.text.unicode != 8 ){
					displayText = displayText + static_cast<char>(e.text.unicode) ;
//					cout <<static_cast<char>(e.text.unicode)<<" Added" <<endl ;						
					
				}

			}


	
		}

		
	text.setString(displayText);

	window.clear();
	window.draw(text) ;
	window.display();		

	
	}
		
	
	return 0 ;
}
