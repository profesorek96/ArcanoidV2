// ArcanoidV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"

using namespace sf;
using namespace std;









int main()
{
	Ball ball(400, 300);
	RenderWindow window{ VideoMode{800,600}, "ArcanoidV2" }; // nowy sposob inicjalizacji cpp11
	window.setFramerateLimit(60);
	Event event; //ewent przechowujace zdazenia w obrebie okna aby nie byloz frizowane
	while (true) 
	{
		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		ball.update();
		
		window.draw(ball);
		window.display();

	}

    return 0;
}

