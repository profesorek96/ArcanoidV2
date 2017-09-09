#include "stdafx.h"
#include "Paddle.h"


Paddle::Paddle(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	//shape.setSize(Vector2f(20, 20)); stary standard
	//shape.setSize({ 20,20 }); // to co wyzej tylko ze standardu c11
	shape.setSize({this->paddleWidth,this->paddleHeight});
	shape.setFillColor(Color::Green);
	shape.setOrigin(paddleWidth/ 2.f,paddleHeight/2.f); //ustawia origin na srodku

}

void Paddle::draw(RenderTarget& target, RenderStates state)const //slowko const oznacza ze metoda nei bedzie zmieniac pol klasy
{
	target.draw(this->shape, state);
}

void Paddle::update()
{
	this->shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
	{
		velocity.x = -paddleVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800)
	{
		velocity.x = paddleVelocity;
	}
	else
	{
		velocity.x = 0;
	}
}

float Paddle::left()
{
	return this->shape.getPosition().x - shape.getSize().x/2.f;
}

float Paddle::right()
{
	return this->shape.getPosition().x + shape.getSize().x/2.f;
}

float Paddle::top()
{
	return this->shape.getPosition().y - shape.getSize().y/2.f;
}

float Paddle::bootom()
{
	return this->shape.getPosition().y + shape.getSize().y/2.f;
}
Vector2f Paddle::getPosition()
{
	return shape.getPosition();
}