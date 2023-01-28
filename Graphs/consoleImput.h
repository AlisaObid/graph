#include <iostream>
#include "data.h"

namespace myFunc
{
	class consoleImput
	{
	public:
		data* getData()
		{
			std::cout << "Enter a unit segment on the x coordinate: ";
			std::cin >> _xLabel;
			std::cout << "Enter a unit segment on the y coordinate: ";
			std::cin >> _yLabel;
			std::cout << "Enter the maximum value of x on the graph: ";
			std::cin >> _xMax;
			std::cout << "Enter the maximum value of x on the graph: ";
			std::cin >> _yMax;
			std::cout << "Enter the function: ";
			std::cin >> _function;
			return new data(_xLabel, _yLabel, _xMax, _yMax, _function);
		}

	private:
		int _xLabel, _yLabel, _xMax, _yMax;
		std::string _function;
	};
}