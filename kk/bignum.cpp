#include<bits/stdc++.h>
#define SIZE 12009
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
	void print(string ssss="noendl"){
		for(int i=len-1;i>=0;i--) cout<<s[i];
		if(len-1<0) cout<<"0";
		if(ssss=="endl") cout<<endl;
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
		clr();
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
	void subdig(int dig,bignum b){
		int i;
		for(i=0;i<b.len;i++){
			if((s[i+dig]-=b.s[i])<0){
				s[i+dig]+=10;
				s[i+dig+1]--;
			}
		}
		clr();
	}
	bool ledig(int dig,bignum b){
		int i;
		if(len+dig>b.len) return 0;
		if(len+dig<b.len) return 1;
		for(i=len-1;i>=0&&s[i]==b.s[i+dig];i--);
		return i<0||s[i]<b.s[i+dig];
	}
	void operator /= (bignum b){
		bignum q,r;q=0;r=*this;
		for(int i=len-b.len+1;i>=0;i--)
			for(;b.ledig(i,r);q.s[i]++)
				r.subdig(i,b);
		q.len=len-b.len+2;q.clr();
		//r.len=b.len;r.clr();
		*this=q;
	}
	bignum operator / (bignum b){
		bignum q,r;q=0;r=*this;
		for(int i=len-b.len+1;i>=0;i--)
			for(;b.ledig(i,r);q.s[i]++){
				r.subdig(i,b);
			}
		q.len=len-b.len+2;q.clr();
		//r.len=b.len;r.clr();
		//*this=q;
		return q;
	}
	void operator %= (bignum b){
		bignum q,r;q=0;r=*this;
		for(int i=len-b.len+1;i>=0;i--)
			for(;b.ledig(i,r);q.s[i]++)
				r.subdig(i,b);
		//q.len=b.len;q.clr();
		r.len=b.len;r.clr();
		*this=r;
	}
	bignum operator % (bignum b){
		bignum q,r;q=0;r=*this;
		for(int i=len-b.len+1;i>=0;i--)
			for(;b.ledig(i,r);q.s[i]++)
				r.subdig(i,b);
		//q.len=b.len;q.clr();
		r.len=b.len;r.clr();
		return r;
	}
	bignum operator ++ (int){
		bignum rt=*this;
		s[0]++;
		for(int i=0;i<len;i++){
			if(s[i]>=10){
				s[i]-=10;
				++s[i+1];
			}
			else break;
		}
		len++;clr();
		return rt;
	}
	bignum operator ++ (){
		s[0]++;
		for(int i=0;i<len;i++){
			if(s[i]>=10){
				s[i]-=10;
				++s[i+1];
			}
			else break;
		}
		len++;clr();
		return *this;
	}
	bignum operator -- (int){
		bignum rt=*this;
		s[0]--;
		for(int i=0;i<len;i++){
			if(s[i]<0){
				s[i]+=10;
				--s[i+1];
			}else break;
		}
		len++;clr();
		return rt;
	}
	bignum operator -- (){
		s[0]--;
		for(int i=0;i<len;i++){
			if(s[i]<0){
				s[i]+=10;
				--s[i+1];
			}else break;
		}
		len++;clr();
		return *this;
	}
};

inline bignum max_bn(bignum a,bignum b){return a>b?a:b;}
inline bignum min_bn(bignum a,bignum b){return a<b?a:b;}

int n;
bignum ans,tmp;

int main(){
	ans=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		tmp=4*i-2;
		ans*=tmp;
		tmp=i+1;
		ans/=tmp;
	}
	ans.print();
	return 0;
}
