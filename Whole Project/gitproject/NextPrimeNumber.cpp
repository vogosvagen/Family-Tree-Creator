#include<iostream>
using namespace std;

int main(){
	char choice='\0';
	bool isprime=true;
		
		for(int i=1;;i++){
			isprime=true;
			for(int j=2;j<i;j++){
				if(i%j==0)
					isprime=false;
			}		
		if(isprime){
			cout<<i <<" is prime, cont? (y/n): ";
			cin>>choice;
			}
		if(choice=='n')
			break;
		}
	
	return 0;
}