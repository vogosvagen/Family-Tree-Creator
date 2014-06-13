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

void init(int n,std::string* s,int* a,int* yob,bool* aliv){
	s=new std::string[n];
	a=new int[n];
	yob=new int[n];
	aliv=new bool[n];
}

void importToArrays(string fileName){
	ifstream ifile;
	ifile.open(fileName);
}