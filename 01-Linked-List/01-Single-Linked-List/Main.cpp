/*
 Single Linked List
*/

#define _CRT_SECURE_NO_WARNINGS
#include "PersonList.h"
#include <string>

void Operation();
bool Execute(int);
void AddRecord();
void DeleteRecord();
void UpdateRecord();
void SearchRecord();
void ListAllRecords();
void Exit();

PersonList pl;
Person p;

int main()
{
	int choice;
	bool cont = true;

	while (cont)
	{
		Operation();
		cin >> choice;
		cout << endl;
		cont = Execute(choice);
		getchar(); getchar();
	}

	return 0;
}

void Operation()
{
	cout << endl;
	cout << "Choose the operation:" << endl << endl;
	cout << " 1 - Add record" << endl;
	cout << " 2 - Delete record" << endl;
	cout << " 3 - Update record" << endl;
	cout << " 4 - Search record" << endl;
	cout << " 5 - List all records" << endl;
	cout << " 6 - Exit" << endl << endl;;
	cout << " Choice: ";
}

bool Execute(int choice)
{
	switch (choice)
	{
	case 1: AddRecord(); return true;
	case 2: DeleteRecord(); return true;
	case 3: UpdateRecord(); return true;
	case 4: SearchRecord(); return true;
	case 5: ListAllRecords(); return true;
	case 6: Exit(); return false;
	default: cout << " Wrong choice" << endl; return true;
	}
}

void AddRecord()
{
	string name, surname;

	cout << " Name: ";
	cin >> name;
	cout << " Surname: ";
	cin >> surname;
	cout << " Age: ";
	cin >> p.age;

	p.name = new char[name.length() + 1];
	strcpy(p.name, name.data());
	p.name[name.length()] = '\0';

	p.surname = new char[surname.length() + 1];
	strcpy(p.surname, surname.data());
	p.surname[surname.length()] = '\0';

	pl.Insert(p.name, p.surname, p.age);
	cout << " Record has been added" << endl;
}

void DeleteRecord()
{
	if (pl.recordCount == 0) return;

	ListAllRecords();

	int no;
	cout << " Order no: ";
	cin >> no;

	pl.Remove(no);
	cout << " Record has been deleted" << endl;
}

void UpdateRecord()
{
	if (pl.recordCount == 0) return;

	ListAllRecords();

	int no;
	cout << " Order no: ";
	cin >> no;

	string name, surname;
	cout << " New name: ";
	cin >> name;
	cout << " New surname: ";
	cin >> surname;
	cout << " New age: ";
	cin >> p.age;

	p.name = new char[name.length() + 1];
	strcpy(p.name, name.data());
	p.name[name.length()] = '\0';

	p.surname = new char[surname.length() + 1];
	strcpy(p.surname, surname.data());
	p.surname[surname.length()] = '\0';

	pl.Update(no, p.name, p.surname, p.age);
	cout << " Record has been updated" << endl;
}

void SearchRecord()
{
	if (pl.recordCount == 0) return;

	string name;
	cout << " Search name: ";
	cin >> name;

	p.name = new char[name.length() + 1];
	strcpy(p.name, name.data());
	p.name[name.length()] = '\0';

	if (pl.Search(p.name) == 0)
		cout << " Record not found" << endl;
}

void ListAllRecords()
{
	pl.List();
}

void Exit()
{
	cout << "Program terminated" << endl;
	return;
}
