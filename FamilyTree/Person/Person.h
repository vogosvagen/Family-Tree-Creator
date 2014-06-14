#include<string>
#ifndef PERSON
#define PERSON

class Person{
private:
	std::string name;
	int age;
	int yob;	//year of birth
	std::string alive;

public:
	Person();

	Person(std::string name,int age,int yob,bool alive);

	void setName(std::string name);

	std::string getName();

	void setAge();

	int getAge();
	
	void setYob(int yob);

	int getYob();

	void setAlive(std::string alive);

	std::string getAlive();

	void display();

	friend void display2(int n,Person *p);
};


#endif