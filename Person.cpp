#include "Person.h"
#include <iostream>
#include <iomanip>
#include <string>

///////////////////////////////////////////////////////////////////////
//
// Function: operator<<                                         
//                                                                   
// Description:
//    overrides the extraction operator for the Person class. Outputting
//    the objects name and age.
//
// Parameters:  
//    osObject  : reference to an ostream object          
//    person : reference to a Person type object              
//                                                       
// Returns:  
//    osObject : the ostream object                
//                                            
///////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& osObject, const Person& person)
{
	osObject << std::fixed;
	osObject << "Name: " << person.name << ", Age: " << person.age << std::endl;

	return osObject;
}

///////////////////////////////////////////////////////////////////////
//
// Function: Person                                        
//                                                                   
// Description:
//    creates a Person type object and initializes all variables
//
// Parameters:  
//    pName  : name value for the person        
//    pAge : age value for the person             
//                                                       
// Returns:  
//    none               
//                                            
///////////////////////////////////////////////////////////////////////
Person::Person(std::string pName, int pAge)
{
	name = pName;
	age = pAge;
}

///////////////////////////////////////////////////////////////////////
//
// Function: ~Person                                        
//                                                                   
// Description:
//    destorys a Person type object
//
// Parameters:  
//    none            
//                                                       
// Returns:  
//    none               
//                                            
///////////////////////////////////////////////////////////////////////
Person::~Person()
{

}

///////////////////////////////////////////////////////////////////////
//
// Function: getName                                        
//                                                                   
// Description:
//    retrieves the name value of a Person type object
//
// Parameters:  
//    none             
//                                                       
// Returns:  
//    name : the name value of the person               
//                                            
///////////////////////////////////////////////////////////////////////
std::string Person::getName() const
{
	return name;
}

///////////////////////////////////////////////////////////////////////
//
// Function: setName                                        
//                                                                   
// Description:
//    updates the name value of a Person type object
//
// Parameters:  
//    pName : the new value for the person's name             
//                                                       
// Returns:  
//    none              
//                                            
///////////////////////////////////////////////////////////////////////
void Person::setName(std::string pName)
{
	name = pName;
}

///////////////////////////////////////////////////////////////////////
//
// Function: getAge                                        
//                                                                   
// Description:
//    retrieves the age value of a Person type object
//
// Parameters:  
//    none             
//                                                       
// Returns:  
//    age : the age value of the person               
//                                            
///////////////////////////////////////////////////////////////////////
int Person::getAge() const
{
	return age;
}

///////////////////////////////////////////////////////////////////////
//
// Function: setAge                                        
//                                                                   
// Description:
//    updates the age value of a Person type object
//
// Parameters:  
//    pAge : the new value for the person's age             
//                                                       
// Returns:  
//    none              
//                                            
///////////////////////////////////////////////////////////////////////
void Person::setAge(int pAge)
{
	age = pAge;
}

///////////////////////////////////////////////////////////////////////
//
// Function: operator==                                         
//                                                                   
// Description:
//    overrides the equality operator for the Person class. Compares
//    a Person type objects age to another Person type objects age
//
// Parameters:           
//    person : reference to Person type object being compared             
//                                                       
// Returns:  
//    true : returns if the age of both objects is the same
//    false : returns if the age of both objects is not the same               
//                                            
///////////////////////////////////////////////////////////////////////
bool Person::operator==(const Person& person) const
{
	if (age == person.getAge())
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////
//
// Function: operator!=                                         
//                                                                   
// Description:
//    overrides the inequality operator for the Person class. Compares
//    a Person type objects age to another Person type objects age
//
// Parameters:           
//    person : reference to Person type object being compared             
//                                                       
// Returns:  
//    true : returns if the age of both objects is not the same
//    false : returns if the age of both objects is the same               
//                                            
///////////////////////////////////////////////////////////////////////
bool Person::operator!=(const Person& person) const
{
	if (age != person.getAge())
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////
//
// Function: operator<                                       
//                                                                   
// Description:
//    overrides the less than operator for the Person class. Compares
//    a Person type objects age to another Person type objects age
//
// Parameters:           
//    person : reference to Person type object being compared            
//                                                       
// Returns:  
//    true : returns if the age of the object is less than the age of
//           the object being compared
//    false : returns if the age of the object is not less than the age 
//            of the object being compared             
//                                            
///////////////////////////////////////////////////////////////////////
bool Person::operator<(const Person& person) const
{
	if (age < person.getAge())
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////
//
// Function: operator<=                                       
//                                                                   
// Description:
//    overrides the less than or equal to operator for the Person class. 
//    Compares a Person type objects age to another Person type objects 
//    age
//
// Parameters:           
//    person : reference to Person type object being compared            
//                                                       
// Returns:  
//    true : returns if the age of the object is less than or equal to 
//           the age of the object being compared
//    false : returns if the age of the object is not less than or equal
//            to the age of the object being compared             
//                                            
///////////////////////////////////////////////////////////////////////
bool Person::operator<=(const Person& person) const
{
	if (age <= person.getAge())
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////
//
// Function: operator>                                     
//                                                                   
// Description:
//    overrides the greater than operator for the Person class. 
//    Compares a Person type objects age to another Person type objects 
//    age
//
// Parameters:           
//    person : reference to Person type object being compared            
//                                                       
// Returns:  
//    true : returns if the age of the object is greater than the age 
//           of the object being compared
//    false : returns if the age of the object is not greater than the 
//            age of the object being compared             
//                                            
///////////////////////////////////////////////////////////////////////
bool Person::operator>(const Person& person) const
{
	if (age > person.getAge())
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////
//
// Function: operator>=                                       
//                                                                   
// Description:
//    overrides the greater than or equal to operator for the Person 
//    class. Compares a Person type objects age to another Person type 
//    objects age
//
// Parameters:           
//    person : reference to Person type object being compared            
//                                                       
// Returns:  
//    true : returns if the age of the object is greater than or equal 
//           to the age of the object being compared
//    false : returns if the age of the object is not greater than or 
//            equal to the age of the object being compared             
//                                            
///////////////////////////////////////////////////////////////////////
bool Person::operator>=(const Person& person) const
{
	if (age >= person.getAge())
		return true;
	else
		return false;
}


///////////////////////////////////////////////////////////////////////
//
// Function: operator=                                      
//                                                                   
// Description:
//    Overloads the assignment operator for the Person class. Copies
//    age and name values from an existing Person object to a new one
//
// Parameters:            
//    person : Person object being copied              
//                                                       
// Returns:  
//    *this : the new Person object              
//                                            
///////////////////////////////////////////////////////////////////////
const Person& Person::operator=(const Person& person)
{
	if (this != &person)
	{
		name = person.getName();
		age = person.getAge();
	}

	return *this;
}