#include<bits/stdc++.h>
#define ll long long
using namespace std;
// orz laofudasuan
// modified

namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;

int T,n,tp,ansx;
int A,B,C,D;
ll X,Y;
const int mod=998244353;

int vst[10000005];

int ksme(int a,ll q){
	if(q<=10000000) if(vst[q]) return vst[q];
	if(q==0) return 1;
	if(q==1) return a;
	ll ans=0;
	ll qx=q>>1;
	ans=ksme(a,qx)%mod;
	ans=ans*ans;
	ans%=mod;
	if(q&1){
		ans*=a;
		ans%=mod;
	} 
	if(q<=10000000) vst[q]=ans;
	return ans;
}

int main () {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	gi(tp);gi(T);
	if(tp==0){
		while(T--){
			gi(n);
			ansx=ksme(2,n-1);
			if(!(n&1)) --ansx;
			if(ansx<0) ansx+=mod;
			print(ansx);
			putc('\n');
		}
	}else{
		
		gi(A);gi(B);gi(C);gi(D);
		ll nx;
		while(T--){
			X=((1ll*X*A)%mod+B)%mod+1;
			Y=((1ll*Y*C)%mod+D)%mod+1;
			nx=1ll*X*mod+Y;
			ansx=(ansx+ksme(2,nx-1))%mod;
			if(!(nx&1)) ansx=(ansx+mod-1)%mod;
			//cout<<ansx<<endl;
		}
		print(ansx);
		putc('\n');
	}
	return 0;
}
