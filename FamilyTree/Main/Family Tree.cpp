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
	int ch=0;
	while(ch!=-1){
		menu();
		cin>>ch;
		if(ch==-1)
			break;
		else if(ch==1){
		p=add(p,n,fileName);
		display2(n,p);
		}
		else if(ch==3){
			save(p,n,fileName);
		}
	}

	return 0;
}