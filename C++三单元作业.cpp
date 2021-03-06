// C++三单元作业.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
class Salesman
{
private :
	static double discount;
	static double sum;
	static int n;
	int quantity;
	double price;
	double extradiscount1;
public:
	Salesman(int, double);
	static void display();
	static double average();
	static double getdiscount();
	void getn();
	void getsum();
	void extradiscount();

};
Salesman::Salesman(int q, double p)
{
	quantity = q;
	price = p;
	extradiscount1 = 0;
}
double Salesman::discount = 0;
double Salesman::sum = 0;
int Salesman::n = 0;
void Salesman::display()
{
	std::cout << "The sum is " << sum << std::endl;
	std::cout << "The average is " << average() << std::endl;
}
double Salesman::average()
{
	return sum / n;
}

double Salesman::getdiscount()
{
	std::cout << "Please input discount: " << std::endl;
	std::cin >> Salesman::discount;
	return discount;
}
void Salesman::getn()
{
	n += quantity;
}
void Salesman::getsum()
{
	sum += (quantity*price - extradiscount1);
}
void Salesman::extradiscount()
{
	int people = quantity / 10, number,i;
	double total=0;
	std::cout << "Please input the number of people who buys ten or more: " << std::endl;
	std::cin >> number;
	if (number > people)
	{
		std::cout << "There is a mistake.";
		return;
	}
	if (people == 0) return ;
	std::cout << "Please input the amount they buy" << std::endl;
	int *p = new int[10];
	for (i = 0; i < number; i++)
	{
		LOOP:
		std::cin >> p[i];
		if (p[i] <= 10)
		{
			std::cout << "There is a mistake,please input again." << std::endl;
			goto LOOP;
		}
		total += p[i];
	}
	if (total > quantity)
	{
		std::cout << "There is a mistake." << std::endl;
		return;
	}
	extradiscount1 =total * price*0.02;
}

int main()
{
	Salesman stud[3] = {
		Salesman(5,23.5),
		Salesman(12, 24.56),
		Salesman(100, 21.5) };
	Salesman::getdiscount();
	for (int i = 0; i < 3; i++)
	{
		std::cout << "For salesman " << 101 + i << ": " << std::endl;
		stud[i].extradiscount();
		stud[i].getn();
		stud[i].getsum();
	}
	Salesman::display();	
    return 0;
}

