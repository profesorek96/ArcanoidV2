// ArcanoidV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

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

bool collisionTest(Block& block, Ball& ball, int& count)
{
	if (!isIntersecting(block, ball))return false;
	
	block.destroy();
	count--;
	float overlapLeft{ ball.right() - block.left() };//przesuniecie bloczka
	float overlapRight{ block.left() - ball.left() };

	float overlapTop{ ball.bootom()-block.top() };
	float overlapBottom{block.bootom()-ball.top()};

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight }; //wyrazenie warunkowe
	float minOverlapY{ballFromTop ? overlapTop : overlapBottom};


	if (abs(minOverlapX) < abs(minOverlapY))
	{
		//odbijamy w poziomie przesuwanie w poziomie
		ballFromLeft ? ball.moveLeft() : ball.moveRight();
	}
	else
	{
		//przesuwnie w pionie
		ballFromTop ? ball.moveUp() : ball.moveDown();
	}

}

int main()
{

	Texture LOGO;
	if (!LOGO.loadFromFile("texture\\logo.png"))
	{

	}
	Sprite logo_s(LOGO);
	logo_s.setTexture(LOGO);
	

	Texture PLAY;
	if (!PLAY.loadFromFile("texture\\play.png"))
	{

	}
	Sprite play_s(PLAY);
	play_s.setTexture(PLAY);
	play_s.setPosition(300, 400);

	srand(time(NULL));
	Ball ball(float(rand()%800), 300);
	Paddle paddle(float(rand() % 600), 580);
	RenderWindow window{ VideoMode{800,600}, "ArcanoidV2" }; // nowy sposob inicjalizacji cpp11
	window.setFramerateLimit(60);
	Event event; //ewent przechowujace zdazenia w obrebie okna aby nie byloz frizowane

	while (!Keyboard::isKeyPressed(Keyboard::Key::P))
	{
		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
			return 0;
			break;

		}


		window.draw(logo_s);
		window.draw(play_s);
		window.display();

	}





	int count_block = 40;
	unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{ 20 };
	vector<Block> blocks;
	for (int i = 0; i < blocksY; i++)
	{
		for (int j = 0; j < blocksX; j++)
		{
			blocks.emplace_back((j+1)*(blockWidth+10),(i+2)*(blockHeight+5),blockWidth,blockHeight); /// rozni sie od push_back tym ze najpier czeka na konstrukto a pozniej dodaje
			//count_block++;
		}
	}


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

		for (auto& block : blocks) if (collisionTest(block, ball, count_block))break; //sprawdzamy kolizje pomiedzy bloczkiemz  kulka

		auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDestroyed(); }); //wyrazenie lambda
		blocks.erase(iterator,end(blocks)); //przyjmuje 2 iteratory
		

		window.draw(ball);
		window.draw(paddle);

		for (auto& block : blocks) //cpp11 autoloop iterujemy po kazdym bloku z kontenera taki foreatch
			window.draw(block);



		window.display();
		if (ball.bottom_fail)
		{
			Texture GAMEOVER;
			if (!GAMEOVER.loadFromFile("texture\\gameover.png"))
			{

			}
			Sprite gameover_s(GAMEOVER);
			gameover_s.setTexture(GAMEOVER);
			gameover_s.setPosition(170, 100);
			window.clear(Color::Black);
			window.draw(gameover_s);
			window.draw(play_s);
			window.display();

			while (!Keyboard::isKeyPressed(Keyboard::Key::P))
			{
				window.pollEvent(event);
				if (event.type == Event::Closed)
				{
					window.close();
					return 0;
					break;

				}
			}

			window.close();
			main();
			return 0;

		}



		if (count_block == 0)
		{

			Texture WIN;
			if (!WIN.loadFromFile("texture\\win.png"))
			{

			}
			Sprite win_s(WIN);
			win_s.setTexture(WIN);
			win_s.setPosition(210, 100);
			window.clear(Color::Black);
			window.draw(win_s);
			window.draw(play_s);
			window.display();

			while (!Keyboard::isKeyPressed(Keyboard::Key::P))
			{
				window.pollEvent(event);
				if (event.type == Event::Closed)
				{
					window.close();
					return 0;
					break;

				}
			}

			window.close();
			main();
			return 0;



		}

	}

    return 0;
}

