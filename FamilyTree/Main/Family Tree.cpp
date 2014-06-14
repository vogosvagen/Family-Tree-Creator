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
	init(p,fileName);
	display2(n,p);

	return 0;
}