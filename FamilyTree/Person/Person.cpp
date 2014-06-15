#include"Person.h"
#include "functions.h"
#include<iostream>
#include<string>

using namespace std;

	Person::Person(){
		name="NULL";
		age=0;
		yob=0;
		alive="NULL";
	}

	Person::Person(string name,int age,int yob,bool alive){
		this->name=name;
		this->age=age;
		this->yob=yob;
		this->alive=alive;
	}

	void Person::setName(string name){
		this->name=name;
	}

	string Person::getName(){
		return this->name;
	}

	void Person::setAge(){
		this->age=2014-getYob();
	}

	int Person::getAge(){
		return this->age;
	}
	
	void Person::setYob(int yob){
		this->yob=yob;
	}

	int Person::getYob(){
		return this->yob;
	}

	void Person::setAlive(string alive){
		this->alive=alive;
	}

	string Person::getAlive(){
		return this->alive;
	}

	void Person::display(){
			cout<<getName()<<"\t"<<getYob()<<" "<<"(Age: "<<getAge()<<" )"<<"\t"<<getAlive()<<"\n";		
	}

	void display2(int n,Person *p){
		for(int i=0;i<n;i++){
			cout<<p[i].getName()<<"\t"<<p[i].getYob()<<" "<<"(Age: "<<p[i].getAge()<<" )"<<"\t"<<p[i].getAlive()<<"\n";
		}
	}

	
