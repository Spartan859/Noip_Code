#include<string>
#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    for(int i=0;i<str.length();++i){
    	if(str[i]>=97&&str[i]<=122)
        str[i]=str[i]-32;
        else
        continue;
}
    cout << str << endl;
    return 0;
}
