#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
string month,day,md,year,date,date1,date2;
int m,d,count;
int main(){
int tot[12]={31,29,31,30,31,30,31,31,30,31,30,31};	
	cin>>date1>>date2;
	for(m=1;m<=12;m++) {
		stringstream ss1;
		ss1<<m; ss1>>month;
		if (m<=9) month="0"+month;
		for(d=1;d<=tot[m-1];d++) {
			stringstream ss2;
			ss2<<d; ss2>>day;
			if (d<=9) day="0"+day;
			md=month+day;
			year=md;
			reverse(year.begin(),year.end());
			date=year+md;
			if (date>=date1 && date<=date2) count++;
		}
	}	
	cout<<count<<endl;
	return 0;
}


