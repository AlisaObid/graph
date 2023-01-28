#include <string>


namespace myFunc
{
	class data
	{
	public:
		static const int xLenght = 1800, yLenght = 900;
		int xStart, yStart, xEnd, yEnd;
		std::string function;
		data(int xStart, int yStart, int xEnd, int yEnd, std::string function )
		{
			this->xStart = xStart;
			this->yStart = yStart;
			this->xEnd = xEnd;
			this->yEnd = yEnd;
			this->function = function;
		}
		data()
		{
			function = "";
			xStart = 0;
			yStart = 0;
			xEnd = 0;
			yEnd = 0;
		}
	};
}