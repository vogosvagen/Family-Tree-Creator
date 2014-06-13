#include <iostream>
#include<math.h>
#include<string>
#include<sstream>
#include <iomanip>
using namespace std;



int main(){
	double pi = 3.1415926535897932384626433832795;
	int lim;
	cout<<"Limit? :";
	cin>>lim;
	cout<<setprecision(lim+2)<<pi<<"\n";
	return 0;
}