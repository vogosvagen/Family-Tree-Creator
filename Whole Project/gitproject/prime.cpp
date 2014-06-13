#include<iostream>
using namespace std;

int main(){
	for(int i=0;i<15;i++){
		for(int j=1;j<=i;j++){
			if((j!=i && j!=1) && i%j==0){
				cout<<i<<" is not prime\n";
				break;
			}else if(i==j){
				cout<<i<<" is prime.\n";
			}
		}
	}

	return 0;
}