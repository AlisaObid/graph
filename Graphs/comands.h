#include <SFML/Graphics.hpp>
#include <string>
#include "function.h"
#include "graph.h"
#include "data.h"


namespace myFunc
{
	class comands
	{
	private:
		static inline data* _data = new data ();
		static graph* _graph;
	public:

		static void getData()
		{
			setlocale(LC_ALL, "Russian");
			int xStart, xEnd, yStart, yEnd;
			std::string function;
			std::cout << "¬ведите левостороннее значение х: ";
			std::cin >> xStart;
			std::cout << "¬ведите правостороннее значение х: ";
			std::cin >> xEnd;
			std::cout << "¬ведите левостороннее значение y: ";
			std::cin >> yStart;
			std::cout << "¬ведите правостороннее значение y: ";
			std::cin >> yEnd;
			std::cout << "¬ведите функцию: ";
			std::cin >> function;
			_data = new data(xStart, yStart, xEnd, yEnd, function);
			_graph = new graph(*_data);
			_graph->draw();

		}
		static void centre()
		{
			std::cout << "—писок команд:" << std::endl;
			std::cout << '\t' << "New_Data - рассмотреть другую функцию" << std::endl;
			std::cout << '\t' << "Max_Value_Of_Y - найти максимум по у" << std::endl;
			std::cout << '\t' << "Min_Value_Of_Y - найти минимум по у" << std::endl;
			std::cout << '\t' << "Value_Of_Y - найти y по х" << std::endl;
			std::cout << '\t' << "Get_Square - определить площадь под графиком" << std::endl;
			std::cout << "¬ведите команду: ";
			std::string comand;
			std::cin >> comand;
			system("cls");
			if (comand == "New_Data")
			{
				getData();
			}
			if (comand == "Max_Value_Of_Y")
			{
				double xStart, xEnd;
				int accuraty;
				std::cout << "¬ведите начальное значение х: ";
				std::cin >> xStart;
				std::cout << "¬ведите конечное значение х: ";
				std::cin >> xEnd;
				std::cout << "¬ведите количество знаков после зап€той: ";
				std::cin >> accuraty;
				dot maxY = function::getMax(xStart, xEnd, accuraty, _data->function);
				std::cout << "ћаксимальное знаечние у будет в точке: " << maxY.out(std::cout) << std::endl;
			}
			if (comand == "Min_Value_Of_Y")
			{
				double xStart, xEnd;
				int accuraty;
				std::cout << "¬ведите начальное значение х: ";
				std::cin >> xStart;
				std::cout << "¬ведите конечное значение х: ";
				std::cin >> xEnd;
				std::cout << "¬ведите количество знаков после зап€той: ";
				std::cin >> accuraty;
				dot minY = function::getMin(xStart, xEnd, accuraty, _data->function);
				std::cout << "ћинимальное знаечние у будет в точке: " << minY.out(std::cout) << std::endl;
			}
			if (comand == "Value_Of_Y")
			{
				int x;
				std::cout << "¬ведите значение x, по которому нужно найти у: ";
				std::cin >> x;
				std::cout << "«начение у: " << function::getF(x, _data->function) << std::endl;
			}
			if (comand == "Get_Square")
			{
				double xStart, xEnd;
				int accuraty;
				std::cout << "¬ведите начальное значение х: ";
				std::cin >> xStart;
				std::cout << "¬ведите конечное значение х: ";
				std::cin >> xEnd;
				std::cout << "¬ведите количество знаков после зап€той: ";
				std::cin >> accuraty;
				double square = function::getSquare(xStart, xEnd, accuraty, _data->function);
				std::cout << "ѕлощадь под графиком будет равна: " << square << std::endl;
			}
		}
	};
	
}

/*
New_Data - рассмотреть другую функцию
Max_Value_Of_Y - найти максимум по у
Min_Value_Of_Y - найти минимум по у
Get_Square - определить площадь под графиком 
*/