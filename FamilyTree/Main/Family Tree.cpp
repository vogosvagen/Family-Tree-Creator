#include <iostream>
#include <string>
#include <fstream>
#include "functions.h"
#include "Person.h"


using namespace std;


int main(){
	string fileName="people.txt";
	int n;
	if((n=size(fileName))==-1)
		return 0;
	Person *p=new Person[n];
	string* name;
	int* age;
	int* yob;
	bool* alive;
	init(name,age,yob,alive);

	return 0;
}