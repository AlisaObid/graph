#include <SFML/Graphics.hpp>
#include "data.h"
#include "function.h"

namespace myFunc
{
	class graph
	{
	private:
		sf::RenderWindow* _window;
		data _data;

		int getPosition(double lenght, double start, double end, double point)
		{
			return lenght / ((end - start) / (point - start));
		}
	public:
		graph(data data)
		{
			_data = data;
			_window = new sf::RenderWindow(sf::VideoMode(data::xLenght, data::yLenght, 1000), "SFMLworks");
		}

		sf::Vertex getDot(int x, int y)
		{
			int xPoint = getPosition(_data.xLenght, _data.xStart, _data.xEnd, x);
			int yPoint = getPosition(_data.yLenght, _data.yStart, _data.yEnd, y);
			sf::Vertex point(sf::Vector2f(xPoint, yPoint), sf::Color::Green);

			return point;
		}

		void draw()
		{
			while (_window->isOpen())
			{
				sf::Event event;
				while (_window->pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						_window->close();
				}

				for (double x = _data.xStart; x < _data.xEnd; x += 1)
				{
					sf::Vertex vertex = getDot(x, function::getF(x, _data.function));
					_window->draw(&vertex, 1, sf::Points);
				}

				_window->clear();
				_window->display();
			}
		}
	};
}