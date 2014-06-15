#include<string>
#include "Person.h"
#ifndef FUNCTIONS
#define FUNCTIONS

int size(std::string fileName);

void importToClass(std::string* s,int* a,int* yob,bool* aliv);

void init(Person *p,std::string fileName);

void menu();

Person* add(Person *p,int &n,std::string fileName);

void save(Person *p,int n,std::string fileName);

char** makeRelation(Person *p,int n,std::string fileName);

void relationTree(Person *p,int n,std::string fileName,char** relation);

int oldest(Person *p,int n);

void nextgen(Person *p,int n,char** relation,int x,int y,int &g);

char** loadRelation(int n,std::string fileName);

void printRelation(char** relation);
#endif