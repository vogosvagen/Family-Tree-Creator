#include<string>
#include "Person.h"
#ifndef FUNCTIONS
#define FUNCTIONS

int size(std::string fileName);

void importToClass(std::string* s,int* a,int* yob,bool* aliv);

void init(Person *p,std::string fileName);

void menu();

#endif