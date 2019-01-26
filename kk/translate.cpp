#include<bits/stdc++.h>
using namespace std;
string mes[1000][2];
string s;
string n;
bool b=0;
int main(){
	freopen("strings.yml","r",stdin);
	freopen("ch.yml","w",stdout);
	for(int i=0;i<879;i++){
		getline(cin,s);
		for(int j=0;j<s.size();j++){
			if(s[j]==':'){
				mes[i][0]=s.substr(0,j+1);
				mes[i][1]=s.substr(j+1,s.size()-j-1);
				break;
			}
		}
	}
	freopen("en.yml","r",stdin);
	for(int i=0;i<839;i++){
		b=0;
		getline(cin,s);
		for(int j=0;j<s.size();j++)
			if(s[j]==':'){
				n=s.substr(0,j+1);
				break;
			}
		for(int k=0;k<879;k++)
		    if(mes[k][0]==n) cout<<mes[k][0]<<mes[k][1]<<endl,b=1;
		if(!b) cout<<s<<endl;
	}
	return 0;
} 
