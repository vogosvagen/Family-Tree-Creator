#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int size(string fileName){
	ifstream ifile;
	ifile.open(fileName);
	if(!ifile)
		return -1;
	int size=0;
	string temp;
	while(!ifile.eof()){
		ifile>>temp>>temp>>temp;
		size++;
	}
	cout<<size<<" people documented.\n";
	return size;
}

void init(Person *p,string fileName){
	ifstream ifile;
	ifile.open(fileName);
	int i=0;
	string name,alive;
	int yob;
	while(!ifile.eof()){
		ifile>>name>>yob>>alive;
		p[i].setName(name);
		p[i].setYob(yob);
		p[i].setAge();
		p[i].setAlive(alive);
		i++;
	}
}

void importToArrays(string fileName){
	ifstream ifile;
	ifile.open(fileName);
}