#include "stdafx.h"
#include "Ball.h"


Ball::Ball(float t_x,float t_y)
{
	shape.setPosition(t_x, t_y);
	shape.setRadius(this->ballRadious);
	shape.setFillColor(Color::Cyan);
	shape.setOrigin(this->ballRadious, this->ballRadious);  //punkt wzgledem beda wszysktie rotacje domyslnie lewy gorny rog
	bottom_fail = false;
}

void Ball::draw(RenderTarget& target, RenderStates state)const //slowko const oznacza ze metoda nei bedzie zmieniac pol klasy
{
	target.draw(this->shape, state);
}

void Ball :: update()
{
	shape.move(this->velocity);
	if (this->left() < 0)
	{
		velocity.x = ballVelocity;
	}
	else if (this->right() > 800)
	{
		velocity.x = -ballVelocity;

	}

	if (this->top() < 0)
	{
		velocity.y = ballVelocity;
	}
	else if (this->bootom() > 600)
	{

		bottom_fail = true;
		//velocity.y = -ballVelocity;

	}


}

float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Ball::top() 
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Ball::bootom()
{
	return this->shape.getPosition().y + shape.getRadius();
}



void Ball::moveUp() 
{
	this->velocity.y = -ballVelocity;
}
void Ball::moveDown()
{
	this->velocity.y = ballVelocity;
}
void Ball::moveRight()
{
	this->velocity.x = ballVelocity;
}
void Ball::moveLeft()
{
	this->velocity.x = -ballVelocity;
}
Vector2f Ball::getPosition()
{
	return shape.getPosition();
}