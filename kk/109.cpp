#include<bits/stdc++.h>
using namespace std;
stack<char> st;
map<char, int> pri;
map<char, char> con;
string s;
void inst_pri() {
	string ch;
	cin >> ch;
	for (int i = 0; i < ch.size(); i++) {
		if (i % 2 == 0) pri[ch[i]] = (i+2)/2;//如果为左括号，设置优先级
		else {
			con[ch[i]] = ch[i - 1]; pri[ch[i]] = -1;
		}
	}
}
bool solve() {
	for (int i = 0; i <s.size(); i++) {
		if (pri[s[i]] != -1)//left
		    if(st.empty()) {
			    //cout<<i<<"  code1"<<endl;
				st.push(s[i]);
			}
			else if(pri[s[i]]>pri[st.top()]){
			    //cout<<i<<"  code2"<<endl;
				st.push(s[i]);
			}
			else{
				//cout<<i<<"  code3"<<endl;
		        return 0;
			}
		else{
			if(st.empty()){
				//cout<<i<<"  code4"<<endl;
		        return 0;
			}
			else if (con[s[i]] == st.top()) {
			    //cout<<i<<"  code5"<<endl;
		        st.pop();
		    }
		    else {
			    //cout<<i<<"  code6"<<endl;
		        return 0;
	    	}
		}
	}
	return 1;
}
int main(){
	inst_pri();
	cin >> s;
    if(solve()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	system("pause");
	return 0;
}
