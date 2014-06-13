#include<iostream>
using namespace std;


int main(){

	int n1=1,n2=1,lim,temp;
	cout<<"Limit: ";
	cin>>lim;
	cout<<n1<<","<<n2<<",";
	for(int i=0;i<lim;i++){
		temp=n2;
		n2=n1+n2;
		n1=temp;
		cout<<n2<<",";
	}
	return 0;

}