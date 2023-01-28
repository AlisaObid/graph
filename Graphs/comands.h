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
			std::cout << "������� ������������� �������� �: ";
			std::cin >> xStart;
			std::cout << "������� �������������� �������� �: ";
			std::cin >> xEnd;
			std::cout << "������� ������������� �������� y: ";
			std::cin >> yStart;
			std::cout << "������� �������������� �������� y: ";
			std::cin >> yEnd;
			std::cout << "������� �������: ";
			std::cin >> function;
			_data = new data(xStart, yStart, xEnd, yEnd, function);
			_graph = new graph(*_data);
			_graph->draw();

		}
		static void centre()
		{
			std::cout << "������ ������:" << std::endl;
			std::cout << '\t' << "New_Data - ����������� ������ �������" << std::endl;
			std::cout << '\t' << "Max_Value_Of_Y - ����� �������� �� �" << std::endl;
			std::cout << '\t' << "Min_Value_Of_Y - ����� ������� �� �" << std::endl;
			std::cout << '\t' << "Value_Of_Y - ����� y �� �" << std::endl;
			std::cout << '\t' << "Get_Square - ���������� ������� ��� ��������" << std::endl;
			std::cout << "������� �������: ";
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
				std::cout << "������� ��������� �������� �: ";
				std::cin >> xStart;
				std::cout << "������� �������� �������� �: ";
				std::cin >> xEnd;
				std::cout << "������� ���������� ������ ����� �������: ";
				std::cin >> accuraty;
				dot maxY = function::getMax(xStart, xEnd, accuraty, _data->function);
				std::cout << "������������ �������� � ����� � �����: " << maxY.out(std::cout) << std::endl;
			}
			if (comand == "Min_Value_Of_Y")
			{
				double xStart, xEnd;
				int accuraty;
				std::cout << "������� ��������� �������� �: ";
				std::cin >> xStart;
				std::cout << "������� �������� �������� �: ";
				std::cin >> xEnd;
				std::cout << "������� ���������� ������ ����� �������: ";
				std::cin >> accuraty;
				dot minY = function::getMin(xStart, xEnd, accuraty, _data->function);
				std::cout << "����������� �������� � ����� � �����: " << minY.out(std::cout) << std::endl;
			}
			if (comand == "Value_Of_Y")
			{
				int x;
				std::cout << "������� �������� x, �� �������� ����� ����� �: ";
				std::cin >> x;
				std::cout << "�������� �: " << function::getF(x, _data->function) << std::endl;
			}
			if (comand == "Get_Square")
			{
				double xStart, xEnd;
				int accuraty;
				std::cout << "������� ��������� �������� �: ";
				std::cin >> xStart;
				std::cout << "������� �������� �������� �: ";
				std::cin >> xEnd;
				std::cout << "������� ���������� ������ ����� �������: ";
				std::cin >> accuraty;
				double square = function::getSquare(xStart, xEnd, accuraty, _data->function);
				std::cout << "������� ��� �������� ����� �����: " << square << std::endl;
			}
		}
	};
	
}

/*
New_Data - ����������� ������ �������
Max_Value_Of_Y - ����� �������� �� �
Min_Value_Of_Y - ����� ������� �� �
Get_Square - ���������� ������� ��� �������� 
*/