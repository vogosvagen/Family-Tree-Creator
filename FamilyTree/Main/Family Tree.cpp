#include <iostream>
#include <string>
#include <fstream>
#include "functions.h"
#include "Person.h"


using namespace std;


int main(){
	string fileName="people.txt";
	string fileName2="Relation.txt";
	int n;
	char **relation;
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
		else if(ch==4){
			relation=makeRelation(p,n,fileName);
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					cout<<relation[i][j]<<" ";
				cout<<"\n";
			}
		}
		else if(ch==5){
			relationTree(p,n,fileName,relation);
		}
		else if(ch==6){
			relation=loadRelation(n,fileName2);

		}

	}

	return 0;
}