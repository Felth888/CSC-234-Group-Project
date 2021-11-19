///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab10.cpp
// Date: 2021-11-11
// Programmer: Eric Bulson            
//
// Description:
//    Allows a user to create up to 100 Person objects and store them
//    in an array. It then sorts the objects by age and outputs all
//    objects.
//   
///////////////////////////////////////////////////////////////////////

#include "DoublyLinkedList.h"
#include "Person.h"
#include <string>
#include <iostream>
#include <iomanip>

void bubbleSort(Person[], int size);

int main()
{
	int size = 0, age = 0;
	std::string name = "";
	Person people[100];

	for (size; size < 100; size++)
	{
		std::cout << "Enter name (-1 to stop): ";
		std::cin >> name;

		if (name == "-1")
			break;

		std::cout << "Enter age of " << name << ": ";
		std::cin >> age;

		people[size] = Person(name, age);
	}

	bubbleSort(people, size);

	std::cout << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << people[i];

	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function: bubbleSort                                      
//                                                                   
// Description:
//    uses the bubble sort method to sort an array of Person objects
//    by age.
//
// Parameters:            
//    item : Item object being compared               
//                                                       
// Returns:  
//    bool : returns true if the item's name is greater than the name of
//			 the compared item, else returns false               
//                                            
///////////////////////////////////////////////////////////////////////
void bubbleSort(Person people[], int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int index = 0; index < (size - i); index++)
		{
			if (people[index] > people[index + 1])
			{
				Person temp = people[index];
				people[index] = people[index + 1];
				people[index + 1] = temp;
			}
		}
	}
}