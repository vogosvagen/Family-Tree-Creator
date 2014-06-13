#include"Person.h"
#include<string>

using namespace std;

	Person::Person(){
		name="";
		age=0;
		yob=0;
		alive=false;
	}

	Person::Person(string name,int age,int yob,bool alive){
		this->name=name;
		this->age=age;
		this->yob=yob;
		this->alive=alive;
	}

	
