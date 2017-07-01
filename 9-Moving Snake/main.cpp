#include "snake.cc"
/*
    ** Usage of cout is for debugging info only
    ** Snake is intialized at 50 , 50 with one block
    ** Global Vaiables direction and variable are used to direct snake

    about *variable

    at any time variable holds either value of x or y 
    the value in variable depends on last arrow key pressed
    variable gets change at arrowKeyControl function

    Each time snake moves IMG_WIDTH distance (size of one block)

*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600) , "Snake Game");

    sf::Vector2f headPosition(50,50) ;
    sf::Texture snakeTexture ;

    if(!snakeTexture.loadFromFile("./images/red.png"))
    {
        std::cout << "Loading Image Failed" <<"\n" ;
    }

    //Using list STL to represent a snake 
    std::list<sf::Sprite> snake ;
    std::list<sf::Sprite> :: iterator i ;

    //Initializing Snake with one block at position "headheadPosition"
    snake.push_back(sf::Sprite(snakeTexture));
    snake.front().setPosition(headPosition);


    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            //Close if Close button is clicked
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            //If Keyboard key is pressed following cases are handled
            if(event.type == sf::Event::KeyPressed )
            {
                std::cout <<"key pressed "<<event.key.code<<"\n" ;

                //Space key increases size of snake by 1
                if(event.key.code == sf::Keyboard::Space)
                {
                    growSnake(snake);
                }
                
                //This function handles what happens when arrow keys are pressed
                //Handles navigation
                // Arrow Keys handle directions.
                // Modify Only Position of head
                arrowKeyControl(headPosition) ;

                //move snake in current direction irrespective what happens
                //Current direction is specified by Globals (direction and varible)                
                moveSnake(snake , headPosition);
            }
        }

        window.clear(sf::Color::Blue);

        //Draw all boxes iteratively
        for(i = snake.begin(); i != snake.end() ; ++i )
           window.draw(*i) ;        
        
        window.display();
    }


    return 0 ;
}