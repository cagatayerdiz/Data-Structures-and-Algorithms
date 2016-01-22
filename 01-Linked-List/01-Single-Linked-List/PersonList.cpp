#include "PersonList.h"

PersonList::PersonList()
{
	head = NULL;
	recordCount = 0;
}

void PersonList::Insert(char *name, char *surname, int age)
{
	// allocation for a Person class
	Person *newNode = new Person();
	newNode->name = name;
	newNode->surname = surname;
	newNode->age = age;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
		recordCount++;
		return;
	}

	Person *traverse = head;

	while (traverse->next)
		traverse = traverse->next;

	// newNode added at the end of the list
	traverse->next = newNode;
	recordCount++;
}

void PersonList::Remove(int no)
{
	Person *tail = NULL, *traverse = head;
	int i = 1;
	
	// if head is removed
	if (no == 1)
	{
		head = head->next;
		delete traverse;
		recordCount--;
		return;
	}

	// else
	while (i < no)
	{
		tail = traverse;
		traverse = traverse->next;
		i++;
	}

	tail->next = traverse->next;
	
	delete traverse;
	recordCount--;
}

void PersonList::Update(int no, char *name, char *surname, int age) 
{
	Person *traverse = head;
	int i = 1;
	
	while (i < no){
		traverse = traverse->next;
		i++;
	}

	traverse->name = name;
	traverse->surname = surname;
	traverse->age = age;
}

int PersonList::Search(char *name)
{
	Person *traverse = head;
	int i = 1, found = 0;

	while (traverse != NULL)
	{
		if (strcmp(traverse->name, name) == 0)
		{
			cout << " Record found at index " << i << "." << endl;
			found++;
		}
		traverse = traverse->next;
		i++;
	}
	return found;
}

void PersonList::List()
{
	// for not losing head pointer
	Person *traverse = head;
	int i = 1;

	while (traverse)
	{
		cout << " " << i << ". " << traverse->name << " "
			<< traverse->surname << " " << traverse->age << endl;

		traverse = traverse->next;
		i++;
	}
}

void PersonList::MakeEmpty()
{
	Person *traverse;

	while (head != NULL) {
		traverse = head;
		head = head->next;
		delete traverse;
	}

	delete head;
}

PersonList::~PersonList()
{
	MakeEmpty();
}
