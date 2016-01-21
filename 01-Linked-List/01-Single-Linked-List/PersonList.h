#include <iostream>
using namespace std;

struct Person
{
	char *name;
	char *surname;
	int age;
	Person *next;
};

class PersonList
{
public:
	Person *head;
	int recordCount;
	PersonList();
	void Insert(char *, char *, int);
	void Remove(int );
//	void Update(int, Person *);
//	int Search(char *);
	void List();
//	void MakeEmpty();
	~PersonList();
};

