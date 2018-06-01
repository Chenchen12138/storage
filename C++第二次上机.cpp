// C++第二次上机.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#define N 3
#define M 2
using namespace std;
class CStudent
{
private:
	string name;
	int number;
	double Score[N];
	static int failstudent;
public:
	CStudent();
	double GetAverage();
	static int getfailstudent();
	void display();
};
int CStudent::failstudent = 0;
CStudent::CStudent()
{
	cin >> name >> number;
	for (int i = 0; i < N; i++)
	{
		cin >> Score[i];
	}
	if (GetAverage() < 60) failstudent++;
}
double CStudent::GetAverage()
{
	double totalscore = 0.0;
	for (int i = 0; i < N; i++)
	{
		totalscore += Score[i]/N;
	}
	return totalscore;
}
int CStudent::getfailstudent()
{
	return failstudent;
}
void CStudent::display()
{
	cout << "name:" << name << endl;
	cout << "number:" << number << endl;
	for (int i = 0; i < N; i++)
	{
		cout << Score[i] << " ";
	}
	cout << endl;
	cout << "average:" << GetAverage() << endl;
}
int main()
{
	CStudent stu[M];
	stu[0].display();
	stu[1].display();
	cout <<"fail:"<< CStudent::getfailstudent() << endl;
	cin.get();
	cin.get();
}