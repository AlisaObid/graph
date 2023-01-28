#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#include "dot.h"
namespace myFunc
{
    class function
    {
    public:
        function(std::string strFunction)
        {
            _strFunction = strFunction;
        }

        double operator ()(double data)
        {
            return getF(data, _strFunction);
        }

        double operator ()(std::string strFunction, double data)
        {
            return getF(getF(data, strFunction), _strFunction);
        }

        static double getSquare(double start, double end, int accuracy, std::string function)
        {
            double dx = pow(10, -accuracy);
            double square = 0;
            for (double i = start; i <= end; i += dx)
                square += modul(getF(i, function)) * dx;
            return myRound(square, accuracy);
        }
                           
        static dot getMax(double start, double end, int accuracy, std::string function)
        {
            double dx = pow(10, -accuracy);
            dot max(start, getF(start, function));
            for (double i = start + dx; i <= end + dx; i += dx)
            {
                double y = getF(i, function);
                if (y > max.y)
                {
                    max.x = i;
                    max.y = y;
                }
            }

            max.y = myRound(max.y, accuracy);
            max.x = myRound(max.x, accuracy);
            return max;
        }

        static dot getMin(double start, double end, int accuracy, std::string function)
        {
            double dx = pow(10, -accuracy);
            dot min(start, getF(start, function));
            for (double i = start + dx; i <= end + dx; i += dx)
            {
                double y = getF(i, function);
                if (y < min.y)
                {
                    min.x = i;
                    min.y = y;
                }
            }

            min.y = myRound(min.y, accuracy);
            min.x = myRound(min.x, accuracy);
            return min;
        }

        static double getF(double data, std::string strFunction)
        {
            std::vector<std::string> separateFunctions;
            char triggerSing = 0;
            for (int i = 0; i < _sings.size(); i++)
            {
                separateFunctions = parser(strFunction, _sings[i]);
                //for (int j=0; j<separateFunctions.size(); j++)
                    //std::cout << separateFunctions[j] << "|";
                if (separateFunctions.size() != 1)
                {
                    triggerSing = _sings[i];
                    break;
                }
            }

            //std::cout << triggerSing << endl;

            switch (triggerSing)
            {
            case '+':
            {
                double sum = 0;
                for (int i = 0; i < separateFunctions.size(); i++)
                    sum += getF(data, separateFunctions[i]);
                return sum;
                break;
            }
            case '-':
            {
                double dif = getF(data, separateFunctions[0]);
                for (int i = 1; i < separateFunctions.size(); i++)
                    dif -= getF(data, separateFunctions[i]);
                return dif;
                break;
            }
            case '*':
            {
                double mult = 1;
                for (int i = 0; i < separateFunctions.size(); i++)
                    mult *= getF(data, separateFunctions[i]);
                return mult;
                break;
            }
            case '/':
            {
                double share = getF(data, separateFunctions[0]);
                for (int i = 1; i < separateFunctions.size(); i++)
                    share /= getF(data, separateFunctions[i]);
                return share;
                break;
            }
            case '^':
            {
                double res = getF(data, separateFunctions[0]);
                for (int i = 1; i < separateFunctions.size(); i++)
                    res = pow(res, getF(data, separateFunctions[i]));
                return res;
                break;
            }
            default:
            {
                if (strFunction == "x")
                    return data;
                else
                    return stringToDouble(strFunction);
                break;
            }
            }
            return 0;
        }
    private:

        std::string _strFunction;

        static inline const std::vector<char> _sings;
        double static modul(double x)
        {
            return ((x) < 0 ? -(x) : (x));
        }

        double static myRound(double data, int n)
        {
            return (floor(data * pow(10, n)) / pow(10, n));
        }

        static bool inBrackets(std::string& strFunction)
        {
            int brackets = 0;
            //std::cout << strFunction.size() << '\n';
            //std::cout << brackets;

            if (strFunction.size() < 2)
                return false;

            for (int i = 0; i < strFunction.size(); i++)
            {
                //std::cout << strFunction[i] << " " << brackets << " " << i << '\n';
                if (strFunction[i] == '(')
                    brackets++;
                else if (strFunction[i] == ')')
                    brackets--;
                //std::cout << '|';
                if (brackets == 0 && i != strFunction.size() - 1)
                    return false;
            }
            return true;
        }

        double static stringToDouble(const std::string& s)
        {
            std::istringstream i(s);
            double x;
            if (!(i >> x))
                return 0;
            return x;
        }

        std::vector<std::string> static parser(std::string strFunction, char separator)
        {
            if (inBrackets(strFunction))
            {
                strFunction.erase(strFunction.begin());
                strFunction.erase(strFunction.end() - 1);
                //std::cout << "*";
            }

            std::vector<std::string> separateFunctions;

            std::string separateFunction;
            int brackets = 0;
            for (int i = 0; i < strFunction.size(); i++)
            {
                if (strFunction[i] == '(')
                    brackets++;
                else if (strFunction[i] == ')')
                    brackets--;

                if (strFunction[i] == separator && brackets == 0)
                {
                    separateFunctions.push_back(separateFunction);
                    separateFunction = "";
                }
                else
                {
                    separateFunction += strFunction[i];
                }
            }

            separateFunctions.push_back(separateFunction);

            return separateFunctions;
        }
    };
}
