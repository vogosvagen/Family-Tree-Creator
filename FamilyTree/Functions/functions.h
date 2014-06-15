#include<string>
#include "Person.h"
#ifndef FUNCTIONS
#define FUNCTIONS

int size(std::string fileName);

void importToClass(std::string* s,int* a,int* yob,bool* aliv);

void init(Person *p,std::string fileName);

void menu();

void add(Person *p,int &n,std::string fileName);

void save(Person *p,int n,std::string fileName);

#endif