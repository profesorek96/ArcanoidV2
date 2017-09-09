#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Block : public sf::Drawable
{
public:
	Block(float t_X,float t_Y, float t_Width, float t_Height);
	Block() = delete;
	~Block() = default;

	void update();

	Vector2f getPosition();


	float left();
	float right();
	float top();
	float bootom();

	bool isDestroyed();
	void destroy();
	Vector2f getSize();

private:
	void draw(RenderTarget& target, RenderStates state) const override; //funkcja stala nadpisujemy metode wirtualna z interfeju Drawable
	RectangleShape shape;
	bool destroyed{ false };





};

