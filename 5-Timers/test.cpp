#include <sstream>
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace sf ;
using namespace std ;

string to_str(int data)
{
    ostringstream str ;

    str << data;
    return str.str() ;
}

int main()
{

    RenderWindow window(VideoMode(200, 200), "Timer");

	Font sans ;
	Text text ;
	
	sans.loadFromFile("./fonts/SFCartoonist.ttf") ;

	text.setFont(sans);
	text.setString("Default Text");
	text.setCharacterSize(24);
	text.setColor(Color::Green);
		
	Clock C;
	Time ep = C.getElapsedTime() ;
	
	bool timer = true ;

    while (window.isOpen())
    {
    	
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
                
            if(event.type == Event::KeyPressed)
            {
				if(timer)
				{
					timer = false ;
					text.setColor(Color::Red);
				} 
				else
				{
					timer = true ;
					text.setColor(Color::Green);
				}
				

            }
        }
        
        if(timer)
        {
      		ep = C.getElapsedTime() ;
       		//setString takes only strings as arguments. 
		//Converting asSeconds (number) to string using userdefined function to_str
		text.setString(to_str(ep.asSeconds()));
       	}
	
        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}
