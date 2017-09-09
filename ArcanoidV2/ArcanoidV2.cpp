// ArcanoidV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"

using namespace sf;
using namespace std;






template <class T1, class T2> bool isIntersecting(T1& A, T2& B) // klasa szablonwa sprawdzajca czy 2 ksztalty sie przecinaja
{
	return A.right() >= B.left() && A.left() <= B.right() && A.bootom() >= B.top() && A.top() <= B.bootom();
}

bool collisionTest(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball))return false;
	
	ball.moveUp();

	if (ball.getPosition().x < paddle.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paddle.getPosition().x)
	{
		ball.moveRight();
	}


}


int main()
{
	Ball ball(400, 300);
	Paddle paddle(400, 550);
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
		paddle.update();
		collisionTest(paddle, ball);

		window.draw(ball);
		window.draw(paddle);
		window.display();

	}

    return 0;
}

