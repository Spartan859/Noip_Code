#include<iostream>
#include<string>
using namespace std;
string n;
int ans,s;
int t=1;
int main(){
	getline(cin,n);
	for(int i=0;i<n.size()-2;++i){
		if(n[i]!='-'){
				s=n[i]-48;
				ans+=s*t;
			    t++;
		}
	}
	if(n[12]-48==ans%11) cout<<"Right";
	else {
	n.erase(n.size()-1,1);
	if(ans%11!=10) cout<<n<<ans%11;
	else cout<<n<<'X';
}
return 0;
}
