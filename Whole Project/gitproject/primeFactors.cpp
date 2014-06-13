#include<iostream>
using namespace std;

void foo(int num);

bool isprime(int num);

int main(){
	int num=24;
	foo(num);
	return 0;
}

void foo(int num){
	for(int i=2;i<num;i++){
		if(num%i==0 && isprime(i)){
			cout<<i<<" ,";
		}
	}
}

bool isprime(int num){
	for(int i=2;i<num;i++)
		if(num%i==0)
			return false;	
	return true;
}