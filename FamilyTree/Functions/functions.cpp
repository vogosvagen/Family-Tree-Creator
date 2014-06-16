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
	cout<<"4-Relation.\n";
	cout<<"5-Relation tree.\n";
	cout<<"6-Load Relation.\n";
	cout<<"203-Eular Path. (please load relations first)\n";
}

Person* add(Person *p,int &n,string fileName){
	Person *temp=new Person[n+1];
	for(int i=0;i<n;i++){
		temp[i].setName(p[i].getName());
		temp[i].setYob(p[i].getYob());
		temp[i].setAge();
		temp[i].setAlive(p[i].getAlive());
	}
	//temp=p;
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
	cout<<"Added.\n";
	return temp;	
}

void save(Person *p,int n,string fileName){
	ofstream ofile;
	ofile.open(fileName);

	for(int i=0;i<n;i++)
		ofile<<p[i].getName()<<" "<<p[i].getYob()<<" "<<p[i].getAlive()<<"\n";
	
	cout<<"Saved.\n";
}

char** makeRelation(Person *p,int n,std::string fileName){
	char **relation;
	int **matrix;	//For General Relation
	char r='\0';
	relation=new char *[n];
	matrix=new int *[n];
	for(int i=0;i<n;i++){
		relation[i]=new char [n];
		matrix[i]=new int [n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matrix[i][j]=0;
			relation[i][j]='x';
		}
	}
	cout<<"Specify how by typing S, B, M, F, P,or N for sister, brother, mother, father, parent,and NOT RELATED\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				goto end;
			cout<<"How is "<<p[i].getName()<<" related to "<<p[j].getName()<<" ? :";
			
				
			cin>>r;
			if(r=='p' ){
				matrix[i][j]=1;
				relation[i][j]='P';
				
			}
			if(r=='n' || r=='N'){
				cout<<"here";
				matrix[i][j]=0;
				relation[i][j]='N';
			}

			else if(r=='S' || r=='s'){
				matrix[i][j]=1;
				relation[i][j]='S';
			}

			else if(r=='B' || r=='b'){
				matrix[i][j]=1;
				relation[i][j]='B';
			}

			else if(r=='M' || r=='m'){
				matrix[i][j]=1;
				relation[i][j]='M';
			}

			else if(r=='F' || r=='f'){
				matrix[i][j]=1;
				relation[i][j]='F';
				
			}

			
end:
			;
		}
		/*cout<<"Is "<<p[i].getName()<<" related to any of these? \nIf so specify how by (B: brother, S: sister, M: mother, F: father) : \n";
		display2(n,p);
		if(i==0)
			cout<<"Example: B...*press Enter*...[Person Name]\n";
		cin>>r;*/
	}


	/*cout<<"Matrix Relation: \n\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<matrix[i][j]<<" ";
		cout<<"\n";
	}*/

	return relation;
}

void relationTree(Person *p,int n,std::string fileName,char** relation){
	int g=0;
	int old=oldest(p,n);
	cout<<old;
	cout<<"\n"<<p[old].getName()<<":\n";
	for(int i=0;i<n;i++)
		if(relation[i][old]=='M' || relation[i][old]=='F'){
			cout<<"\t"<<p[i].getName()<<":";
			for(int j=0;j<n;j++){
				if(relation[i][j]=='P'){
					nextgen(p,n,relation,i,j,g);
				}
			}
			cout<<"\n";
		}
	cout<<"\n";
}

void nextgen(Person *p,int n,char** relation,int x,int y,int &g){
	if(relation[y][x]=='M'||relation[y][x]=='F'){
		cout<<"\n";
		for(int i=0;i<g;i++)
			cout<<"\t";
		cout<<"\t\t"<<p[y].getName()<<":\n";
	}
	for(int i=0;i<n;i++)
		if(relation[y][i]=='P'){
			cout<<"\t";
			g++;
			nextgen(p,n,relation,y,i,g);
		}
}

int oldest(Person *p,int n){
	int found=0;
	int max=0;
	for(int i=0;i<n;i++)
		if(p[i].getAge()>max){
			max=p[i].getAge();
			found=i;
		}
	return found;
}

char** loadRelation(int n,string fileName){
	char **relation;
	relation=new char *[n];
	for(int i=0;i<n;i++)
		relation[i]=new char[n];
	ifstream ifile;
	ifile.open(fileName);

	if(!ifile)
		return nullptr;
	int x=0;
	char *a=new char[n*n];
	while(!ifile.eof()){
		ifile>>a[x];
		x++;
	}
	x=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			relation[i][j]=a[x];
			x++;
		}
	}
	return relation;
}

void eularPath(int** matrix,int n){
	int oddv=0;
	int countodd=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<" ";
			if(matrix[i][j]==1)
				countodd++;
		}
		if(countodd%2==1)
			oddv++;
		cout<<"\n";
		countodd=0;
	}
	if(oddv==0){
		cout<<"Eular circuit excists!\n";
	}
	else if(oddv==2)
		cout<<"Eular path excists!\n";
	else
		cout<<"No Eular path Found :(\n";	
}

int** getMatrix(int n,char** relation){
	int **matrix;	//For General Relation
	matrix=new int *[n];
	for(int i=0;i<n;i++)
		matrix[i]=new int [n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			matrix[i][j]=0;
	


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(relation[i][j]=='B' || relation[i][j]=='S' || relation[i][j]=='M' || relation[i][j]=='F' || relation[i][j]=='P')
				matrix[i][j]=1;
			else
				matrix[i][j]=0;
		}
	}
	return matrix;
}
