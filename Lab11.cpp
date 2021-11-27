///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab11.cpp
// Date: 2021-11-19
// Programmers: Eric Bulson, Cesar Carrillo, Devon D'Ambrosio,
//				Nicolas Fuller, Kristen Nelms             
//
// Description:
//    Allows a user to create a number of Person objects and store them
//    in a doubly linked list and then prints out all of the objects.
//   
///////////////////////////////////////////////////////////////////////

#include "DoublyLinkedList.h"
#include "Person.h"
#include <string>
#include <iostream>
#include <iomanip>

int main()
{

	doublyLinkedList<Person> People;
	string name;
	int age = 0;

	while (name != "-1")
	{
		cout << "Enter name (-1 to stop): ";
		cin >> name;
		if (name == "-1")
		{
			cout << endl;
			break;
		}
		else
		{
			cout << "Enter age of " << name << ": ";
			cin >> age;
			Person someone(name, age);
			People.insert(someone);
		}
	}

	cout << "People:" << endl;
	People.print();

	system("pause");
	return 0;
}