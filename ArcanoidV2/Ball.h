#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball : public sf::Drawable
{
public:
	Ball(float t_x, float t_y);
	Ball()=delete;//kompilator nei bedzie generowal konstruktora
	~Ball()=default; // dodanie destruktora domyslnego

	void update();
	float left();
	float right();
	float top();
	float bootom();

private:
	CircleShape shape;
	const float ballRadious{ 10.0f };
	const float ballVelocity{ 3.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };
	void draw(RenderTarget& target, RenderStates state) const override; //funkcja stala nadpisujemy metode wirtualna z interfeju Drawable


};

