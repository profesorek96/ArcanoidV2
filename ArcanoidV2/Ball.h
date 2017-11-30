#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball : public sf::Drawable
{
public:
	Ball(float t_x, float t_y);
	Ball()=delete;//kompilator nei bedzie generowal konstruktora
	~Ball()=default; // dodanie destruktora domyslnego

	bool bottom_fail;

	void update();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();



	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bootom();
	

private:
	CircleShape shape;
	const float ballRadious{ 12.0f };
	const float ballVelocity{ 6.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };
	void draw(RenderTarget& target, RenderStates state) const override; //funkcja stala nadpisujemy metode wirtualna z interfeju Drawable


};

