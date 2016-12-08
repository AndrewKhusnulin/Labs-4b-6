#include <iostream>
using namespace std;
int sum(int a, int b) 
{
	return a + b;
}
int sub(int a, int b) 
{
	return a - b;
}
int multiply(int a, int b) 
{
		return a*b;	
}
int main(int argc, char *argv[]) 
{
	setlocale(LC_ALL, "rus");
	int a, b;
	if (!sscanf_s(argv[1], "%d", &a))

	{
		cout << "Отсутствует параметр 1" << endl;;
		system("pause");
		return 1;
	}
	if (!sscanf_s(argv[2], "%d", &b))
	{
		cout << "Отсутствует параметр 2" << endl;;
		system("pause");
		return 1;
	}
	cout << "Сумма: " << sum(a, b) << endl;
	cout << "Разность :" << sub(a, b) << endl;
	cout << "Произведение :" << multiply(a, b) << endl;
	system("pause");
	return 0;
}
