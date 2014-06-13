#include<string>

#ifndef PERSON
#define PERSON

class Person{
private:
	std::string name;
	int age;
	int yob;	//year of birth
	bool alive;

public:
	Person();

	Person(std::string name,int age,int yob,bool alive);
};


#endif