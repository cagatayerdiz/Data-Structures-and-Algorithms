/*
 Single Linked List
*/
#define _CRT_SECURE_NO_WARNINGS
#include "PersonList.h"
#include <string>


void Operation();
void Execute(int);
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

	Operation();
	cin >> choice;
	cout << endl;
	Execute(choice);
	Execute(1);
	Execute(1);
	Execute(5);
	Execute(1);
	Execute(1);
	Execute(2);
	Execute(1);
	Execute(2);
	Execute(5);
	Execute(2);

	return 0;
}

void Operation()
{
	cout << "Choose the operation:" << endl << endl;
	cout << " 1 - Add record" << endl;
	cout << " 2 - Delete record" << endl;
	cout << " 3 - Update record" << endl;
	cout << " 4 - Search record" << endl;
	cout << " 5 - List all records" << endl;
	cout << " 6 - Exit" << endl << endl;;
	cout << " Choice: ";
}

void Execute(int choice)
{
	switch (choice)
	{
	case 1: AddRecord(); break;
	case 2: DeleteRecord(); break;
	case 3: UpdateRecord(); break;
	case 4: SearchRecord(); break;
	case 5: ListAllRecords(); break;
	case 6: Exit(); break;
	default: cout << " Wrong choice" << endl; break;
	}
	cout << endl;
}

void AddRecord() 
{
	cout << "Add Record" << endl;
	
	string name, surname;
	int age;
	
	cout << " Name: ";
	cin >> name;
	cout << " Surname: ";
	cin >> surname;
	cout << " Age: ";
	cin >> age;

	p.name = new char[name.length() + 1];
	strcpy(p.name, name.data());
	p.name[name.length()] = '\0';

	p.surname = new char[surname.length() + 1];
	strcpy(p.surname, surname.data());
	p.surname[surname.length()] = '\0';

	p.age = age;

	pl.Insert(p.name, p.surname, p.age);
	cout << " Record has been added" << endl;
}

void DeleteRecord()
{
	if (pl.recordCount == 0) return;
	
	cout << "Delete Record" << endl;

	ListAllRecords();
	
	int no;
	cout << " Order no: ";
	cin >> no;

	pl.Remove(no);
	cout << " Record has been deleted" << endl;
}

void UpdateRecord()
{
	cout << "Update Record" << endl;
}

void SearchRecord()
{
	cout << "Search Record" << endl;
}

void ListAllRecords()
{
	cout << "List All Records" << endl;
	pl.List();
}

void Exit()
{
	cout << "Program terminated" << endl;
	return;
}
