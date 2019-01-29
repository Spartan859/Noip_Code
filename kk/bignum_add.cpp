#include<bits/stdc++.h>
#define SIZE 1209
using namespace std;
struct bignum{
	int s[SIZE],len;
	bignum(){
		memset(s,0,sizeof(s));
		len=0;
	}
	void clr(){
		while(s[len-1]==0) len--;
	}
	void scan(){
		string sss;
		cin>>sss;
		len=sss.size();
		int i;
		for(i=0;i<len;i++) s[len-i-1]=sss[i]-'0';
		for(;i<SIZE;i++) s[i]=0;
	}
	void print(){
		for(int i=len-1;i>=0;i--) cout<<s[i];
		cout<<endl;
	}
	void operator += (bignum b){
		int i;
		for(i=0;i<max(len,b.len);i++){
			if((s[i]+=b.s[i])>=10){
				s[i]-=10;
				s[i+1]++;
			}
		}
		len=i+1;
		clr();
	}
	bool operator <= (bignum b){
		if(len>b.len) return 0;
		if(len<b.len) return 1;
		int i;
		for(i=len-1;i>=0&&s[i]==b.s[i];i--);
		return i<0||s[i]<b.s[i];
	}
	bool operator != (bignum b){
		if(!(*this<=b)||!(b<=*this)) return 1;
		return 0;
	}
	bool operator < (bignum b){
		if(!(b<=*this)) return 1;
		return 0;
	}
	bool operator > (bignum b){
		if(!(*this<=b)) return 1;
		return 0;
	}
	bool operator >= (bignum b){
		if(!(*this<b)) return 1;
		return 0;
	}
	void operator = (bignum b){
		len=b.len;
		memset(s,0,sizeof(s));
		for(int i=len-1;i>=0;i--) s[i]=b.s[i];
	}
	void operator = (int b){
		len=1;
		memset(s,0,sizeof(s));
		while(b){
			s[len-1]=b%10;
			len++;
			b/=10;
		}
	}
	bool operator == (bignum b){
		if(*this!=b) return 0;
		return 1;
	}
	bignum operator + (bignum b){
		bignum c=*this;
		c+=b;
		return c;
	}
	void operator -= (bignum b){
		int i;
		for(i=0;i<b.len;i++){
			if((s[i]-=b.s[i])<0){
				s[i]+=10;
				s[i+1]--;	
			}
		}
		clr();
	}
	bignum operator - (bignum b){
		bignum c=*this;
		c-=b;
		return c;
	}
	void operator *= (bignum b){
		bignum c;
		for(int i=0;i<b.len;i++)
			for(int j=0;j<b.s[i];j++)
				c.adddig(i,*this);
		*this=c;
	}
	bignum operator * (bignum b){
		bignum c;
		for(int i=0;i<b.len;i++)
			for(int j=0;j<b.s[i];j++)
				c.adddig(i,*this);
		return c;
	}
	void adddig(int dig,bignum b){
		int i;
		for(i=0;i<max(len,b.len);i++){
			if((s[i+dig]+=b.s[i])>=10){
				s[i+dig]-=10;
				s[i+dig+1]++;
			}
		}
		len=i+dig+1;
		clr();
	}
}a,b,c;
inline bignum max_bn(bignum a,bignum b){
	return a>b?a:b;
}

bignum n,ans,yi;
int m;

int main(){
	
	ans=1;yi=1;
	n.scan();
	cin>>m;
	for(int i=1;i<=m;i++){
		ans*=n;
		n-=yi;
	}
	ans.print();
	
	return 0;
}
