#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct student
{
	char name[32];
	char surname[32];
	char date[9];
	int points;
};
struct list
{
	student stud;
	list *pNext;
};
void addFirst(list *& pF, list *p)
{
	p->pNext = pF;
	pF = p;
}
list *delFirst(list *&pF)
{
	if (pF == 0) return 0;
	list *p = pF;
	pF = pF->pNext;
	return p;
}
bool add(list *&pF, list *pZad, list *p)
{
	if (pZad == pF)
	{
		p->pNext = pF;
		pF = p;
		return true;
	}
	list *pPred = pF;
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false;
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
}
list *del(list*& pF, list *p)
{
	if (pF == 0) return 0;
	if (pF == p)
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		list *pPred = pF;
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0) return 0;
		pPred->pNext = p->pNext;
		return p;
	}
	while (delFirst(pF));
}
int main(int argc, char* argv[])
{
	list *pF = 0;
	list *p;
	char ch;
	do
	{
		p = (list *)malloc(sizeof(list));
		printf("\nName: ");
		fflush(stdin);
		gets_s(p->stud.name, 31);
		printf("Surname: ");
		fflush(stdin);
		gets_s(p->stud.surname, 31);
		printf("Date: ");
		fflush(stdin);
		gets_s(p->stud.date, 8);
		printf("Points: ");
		fflush(stdin);
		cin >> p->stud.points;	
		addFirst(pF, p);
		printf("Press 'y' or 'Y' to continue or press any other key to exit ");
		ch = _getche();
		cin.get();
		cin.clear();
		cout << endl;
	} while (ch == 'y' || ch == 'Y');
	for (list *pi = pF; pi; pi = pi->pNext)
		cout << pi->stud.name << " " << pi->stud.surname << " " << pi->stud.date << " " << pi->stud.points << endl;
	for (list *pi = pF; pi->pNext;)
	{
		double min = pi->stud.points;
		list *pmin = pi;
		for (list *pj = pi->pNext;pj; pj = pj->pNext)
			if (pj->stud.points < min)
			{
				min = pj->stud.points;
				pmin = pj;
			}
		if (pi != pmin)
		{
			del(pF, pmin);
			add(pF, pi, pmin);
		}
		else pi = pi->pNext;
	}
	cout << endl;
	cout << "Sorted: " << endl;
	for (list *pi = pF; pi; pi = pi->pNext)
		cout << pi->stud.name << " " << pi->stud.surname << " " << pi->stud.date << " " << pi->stud.points << endl;
	system("pause");
	return 0;
}
