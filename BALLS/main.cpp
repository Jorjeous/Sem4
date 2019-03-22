
#include <SFML\Graphics.hpp>
#include "Vector2.h"
#include "Material.h"
#include <vector>


Vector2 GetDeltaP(Ball ball1, Ball ball2) {
	Vector2 d;

	d = ball1.position - ball2.position;

	if (d.length() <= ball1.radius + ball2.radius && (ball1.velocity - ball2.velocity) * d <= 0) {
		return (2 * (ball1.velocity - ball2.velocity) / (1 / ball1.mass + 1 / ball2.mass) * d.norm()) * d.norm();
	}
	else
		return Vector2(0, 0);
}

int main() {
	const int HEIGHT = 1200, WIDTH = 900;
	std::vector<Ball> balls;
	sf::RenderWindow window(sf::VideoMode(HEIGHT, WIDTH), "BALLS");
	sf::Clock clock;
	float time, Tbegin = 0;

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time t = clock.getElapsedTime();
		while (window.pollEvent(event)) 
		{
			switch (event.type) 
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::MouseButtonReleased:
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						Ball ball;
						ball.position = Vector2(event.mouseButton.x, event.mouseButton.y);
						ball.radius = rand() % 20 + 25;
						ball.mass = ball.radius / 5;
						balls.push_back(ball);
					}
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						Ball ball;
						ball.position = Vector2(event.mouseButton.x, event.mouseButton.y);
						ball.radius =  10;
						ball.mass = ball.radius;
						balls.push_back(ball);
					}
					break;
			}
		}
		window.clear(sf::Color::Black);

		time = t.asSeconds() - Tbegin;
		Tbegin = t.asSeconds();

		for (auto i = 0; i < balls.size(); ++i) {
			sf::CircleShape ball(balls[i].radius);
			ball.setFillColor(sf::Color::Color((i*211) % 255, (i * 100) % 255, (i * 10) % 255, 255)); //This is just for beauty
			ball.setOrigin(balls[i].radius, balls[i].radius);
			ball.setPosition(balls[i].position.x, balls[i].position.y);
			window.draw(ball);
			balls[i].UpdatePosition(time);

			if (balls[i].position.x - balls[i].radius <= 0 || balls[i].position.x + balls[i].radius > HEIGHT) {
				balls[i].velocity.x *= -1;
			}
			if (balls[i].position.y - balls[i].radius <= 0 || balls[i].position.y + balls[i].radius > WIDTH) {
				balls[i].velocity.y *= -1;
			}

			for (auto j = i+1; j < balls.size(); ++j) {
					Vector2 dp;
					dp = GetDeltaP(balls[i], balls[j]);
					balls[j].velocity += dp / balls[j].mass;
					balls[i].velocity += (-1) * dp / balls[i].mass;
			}
		}

		window.display();
	}
	return 0;
}
