#include "SFML/Graphics.hpp"


// The starting point of the project  
int main()
{
	// using r-value parameters to decrease the overhead of copying
	sf::RenderWindow window{ sf::VideoMode(640, 480), "SFML1 Program" };

	///////////////////////////////////////////// creating a rec shape
	/*sf::RectangleShape rectangle{ sf::Vector2f{128.f, 256.f} };
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(320, 240);
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);*/

	sf::Texture mushroom_texture;
	if (!mushroom_texture.loadFromFile("T_Mushroom.png"))
	{
		// texture could not be found, handle error 
	}
	sf::Sprite mushroom_sprite{ mushroom_texture };
	sf::Vector2u texture_size{ mushroom_texture.getSize() };
	mushroom_sprite.setOrigin(texture_size.x / 2, texture_size.y / 2);
	sf::Vector2f increment(0.1f, 0.1f);

	// listen to the events of this window 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				// window's close button is clicked
				window.close();
			}
		}

		// move the sprite
		// check for border bounds in X
		if (mushroom_sprite.getPosition().x + (texture_size.x / 2) > window.getSize().x && increment.x > 0 //going to the right
			|| mushroom_sprite.getPosition().x - (texture_size.x / 2) < 0 && increment.x < 0)			   //going to the left
		{
			// reverse the speed
			increment.x *= -1;
		}
		// check for border bounds in Y 
		if (mushroom_sprite.getPosition().y + (texture_size.y / 2) > window.getSize().y && increment.y > 0 //going to the right
			|| mushroom_sprite.getPosition().y - (texture_size.y / 2) < 0 && increment.y < 0)			   //going to the left
		{
			// reverse the speed
			increment.y *= -1;
		}

		mushroom_sprite.setPosition(mushroom_sprite.getPosition() + increment);

		window.clear(sf::Color(16, 16, 16, 255));
		window.draw(mushroom_sprite);
		window.display();
	}

	return 0;
}