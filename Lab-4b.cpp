#include <iostream>

using namespace std;
struct Student
{
	char Name[64];
	char Surname[64];
	int age;
	int number;
};
struct Ball
{
	Student s;
	float ball;
};
int main(int argc, char* argv[]) {
	Ball *p;
	int n;
	float max = 0;
	float min = 100;
	cout << "Number of students: ";
	cin >> n;
	p = new Ball[n];
	for (int i = 0; i < n; i++) {
		cin.clear();
		cout << "Student # " << i + 1 << endl;
		cin.clear();
		cout << "The student`s Name: ";
		cin >> p[i].s.Name;
		cin.clear();
		cout << "The student`s Surname: ";
		cin >> p[i].s.Surname;
		cin.clear();
		cout << "The student`s age ";
		cin >> p[i].s.age;
		cin.clear();
		cout << "Number of school: ";
		cin >> p[i].s.number;
		cout << "The student`s ball: ";
		cin >> p[i].ball;
	}
	for (int i = 0; i < n; i++) {
	    cout << "Name: " << p[i].s.Name << " " << "Surname: " << p[i].s.Surname << " ";
	    cout  << "Age: " << p[i].s.age << " " << "Number of school: " << p[i].s.number << " " << "Ball: " << p[i].ball << endl;
		if (p[i].ball > max) max = p[i].ball;
		if (p[i].ball < min) min = p[i].ball;
	}
	cout << "Maximum ball: " << max << endl;
	cout << "Minimum ball: " << min << endl;
	free(p);
	system("pause");
	return 0;
}
