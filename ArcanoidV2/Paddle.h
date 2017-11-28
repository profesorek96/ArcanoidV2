#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;
class Paddle: public sf::Drawable
{
public:
	Paddle(float t_X, float t_Y);
	Paddle()=delete;
	~Paddle()=default;
	void update();

	Vector2f getPosition();


	float left();
	float right();
	float top();
	float bootom();
private:

	void draw(RenderTarget& target, RenderStates state) const override; //funkcja stala nadpisujemy metode wirtualna z interfeju Drawable
	RectangleShape shape;
	const float paddleWidth{ 200.0f };
	const float paddleHeight{ 20.0f };
	const float paddleVelocity{ 8.0f };
	Vector2f velocity{ paddleVelocity,0.f };

};

