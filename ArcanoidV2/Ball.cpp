#include "stdafx.h"
#include "Ball.h"


Ball::Ball(float t_x,float t_y)
{
	shape.setPosition(t_x, t_y);
	shape.setRadius(this->ballRadious);
	shape.setFillColor(Color::White);
	shape.setOrigin(this->ballRadious, this->ballRadious);  //punkt wzgledem beda wszysktie rotacje domyslnie lewy gorny rog
}

void Ball::draw(RenderTarget& target, RenderStates state)const //slowko const oznacza ze metoda nei bedzie zmieniac pol klasy
{
	target.draw(this->shape, state);
}

void Ball :: update()
{
	shape.move(this->velocity);
}

float Ball::left()
{

}

float Ball::right()
{

}

float Ball::top() 
{

}

float Ball::bootom()
{

}