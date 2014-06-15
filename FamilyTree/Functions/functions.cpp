#include "functions.h"
#include "Person.h"
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
	ifile.close();
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
	ifile.close();
}

void importToArrays(string fileName){
	ifstream ifile;
	ifile.open(fileName);
}

void menu(){
	cout<<"Select option: \n";
	cout<<"1-Add Person.\n";
	cout<<"2-Dellete person.\n";
	cout<<"3-Save changes.\n";
}

void add(Person *p,int &n,string fileName){
	Person *temp=new Person[n+1];
	temp=p;
	string name,alive;
	int yob;
	cout<<"Name of new person: ";
	cin>>name;
	temp[n].setName(name);
	cout<<"Year of Birth: ";
	cin>>yob;
	temp[n].setYob(yob);
	temp[n].setAge();
	cout<<"Type 'Alive' or 'Dead': ";
	cin>>alive;
	if(alive=="Alive")
		temp[n].setAlive(alive);
	else if(alive=="Dead")
		temp[n].setAlive(alive);
	else
		temp[n].setAlive("Null");
	p=nullptr;
	n=n+1;
	p=new Person[n];
	p=temp;
	cout<<"Added.\n";
}

void save(Person *p,int n,string fileName){
	ofstream ofile;
	ofile.open(fileName);

	for(int i=0;i<n;i++)
		ofile<<p[i].getName()<<" "<<p[i].getYob()<<" "<<p[i].getAlive()<<"\n";
	
	cout<<"Saved.\n";
}
