#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std ;
using namespace sf ;

int main()
{
	
	RenderWindow window(VideoMode(800,600) , "Text Box" , Style::Default);
	
	Font sans ;
	Text text ;
	

	if(sans.loadFromFile("./fonts/SFCartoonist.ttf"))
	{
		
		//Font Loaded from disk
		
		text.setFont(sans);
		text.setString("Default Text");
		text.setCharacterSize(24);
		text.setColor(Color::Green);
		

		while(window.isOpen())
		{
	
			Event e ;
			while(window.pollEvent(e)) 
			{
				if(e.type == Event::Closed)
				{
					window.close();
				}
	
			}

	
			window.clear() ;
			window.draw(text);
			window.display();

		}

	}
	else
	{
		cout << "Font Loading Failed" <<"\n" ;	
	}
	

	return 0 ;
}
