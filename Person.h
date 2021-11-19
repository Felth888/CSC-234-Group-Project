#ifndef PERSON_H
#include <string>
#include <iostream>

///////////////////////////////////////////////////////////////////////
//
// Class: Person                                          
//                                                                   
// Description:
//    represents a single person including their name and age        
//
//    name
//    age
//
//    Person
//    ~Person
//    getName
//    setName
//    getAge
//    setAge
//    operator<<
//    operator==
//    operator!=
//    operator<
//    operator<=
//    operator>
//    operator>=
//    operator=                                      
// 
///////////////////////////////////////////////////////////////////////
class Person
{
	friend std::ostream& operator<<(std::ostream&, const Person&);

private:
	std::string name;
	int age;

public:
	Person(std::string = "", int = 0);
	~Person();
	std::string getName() const;
	void setName(std::string);
	int getAge() const;
	void setAge(int);

	bool operator==(const Person&) const;
	bool operator!=(const Person&) const;
	bool operator<(const Person&) const;
	bool operator<=(const Person&) const;
	bool operator>(const Person&) const;
	bool operator>=(const Person&) const;
	const Person& operator=(const Person&);
};

#endif // !PERSON_H



