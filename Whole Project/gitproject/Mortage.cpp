#include<iostream>
#include<string>
using namespace std;

int main(){
	int mortage=100000;
	cout<<"do pay $100,000 \nInterest? (example 23%) : ";
	int interest;
	try{
	cin>>interest;
	if (interest<1)
		throw 1;
	if(interest>100)
		throw 2;

	double monthpay=mortage * interest/100;
	cout<<"you must pay $"<<monthpay<<" per month\n";

	double total=0;
	int c=0;
	while(total<mortage){
		total+=monthpay;
		c++;
	}
	
	cout<<"It will take you "<<c<<" months to pay off your mortage\n";
	}catch(int ex){
		cout<<"Error "<<ex<<"\n";
	}
	return 0;
}