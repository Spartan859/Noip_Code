#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const ull P=999983;
ull hash[maxn],p[maxn];
char s[maxn];
int main(int argc, char** argv) {
	p[0]=1;
	for(int i=1;i<=maxn;++i)
		p[i]=p[i-1]*P;
	while(~scanf("%s",s+1)){
		int len=strlen(s+1);
		if(len==1&&s[1]=='.') break;
		for(int i=1;i<=len;++i)
			hash[i]=hash[i-1]*P+(s[i]-'a'+1);
		vector<int> v;
		for(int i=1;i<=len;++i)
			if(len%i==0)
				v.push_back(i);
		int times=1;
		for(int i=0;i<v.size();++i){
			int flag=1;
			for(int j=v[i]*2;j<=len;j+=v[i]){
				if(hash[j]-hash[j-v[i]]*p[v[i]]!=hash[v[i]]){
					flag=0;
					break;
				}
			}
			if(flag){
				times=len/v[i];
				break;
			}
		}			
		printf("%d\n",times);
	}
	return 0;
}
