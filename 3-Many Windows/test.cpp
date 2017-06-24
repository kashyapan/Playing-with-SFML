#include <SFML/Window.hpp>
using namespace sf ;

int main()
{
	//Standard main Window with all buttons
	Window mainWindow(VideoMode(800,600) , "Main Window" , Style::Default);

	//Alert Box with Only Close Button
	Window alertWindow(VideoMode(200,100) , "Alert Box" , Style::Close);
	
	
	//Keep everyting running as long as main window is not closed
	
	while(mainWindow.isOpen())
	{
	
		Event e ;
		
		while(mainWindow.pollEvent(e))
		{
			if(e.type == Event::Closed)
			{
				mainWindow.close();
			}
		}
		

		while(alertWindow.pollEvent(e))
		{
			if(e.type == Event::Closed)
			{
				alertWindow.close();
			}
		}
	}
			
	
	
	return 0 ;
}
