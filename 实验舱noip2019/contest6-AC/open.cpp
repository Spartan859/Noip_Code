#include <bits/stdc++.h>
#define rep(x,n) for(int x=0;x<int(n);++x)
#define dbg(x) cerr<<#x<<" = "<<x<<endl
//#define _ <<" , "<<
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef pair<int,int> pt;

const int maxn = 2005, mod = 1e9 + 7;
int N;
int A[maxn],B[maxn];
int L[maxn][maxn];
int C[maxn][maxn];
int bin[maxn][maxn];
int factorial[maxn];

void prepare(int N) {
	//链 
	for(int i=0;i<=N;i++) L[i][0] = 1;
	for(int i=2;i<=N;i++) {
    	for(int j=1;j<=i/2;j++) {
    		L[i][j] = L[i-2][j-1] + L[i-1][j];
      		if(L[i][j] >= mod) L[i][j] -= mod;
    	}
  	}
    //环上点1和点i之间的边选不选 
  	for(int i=0;i<=N;i++) C[i][0] = 1;
  	for(int i=2;i<=N;i++) {
    	for(int j=1;j<=i/2;j++) {
      		C[i][j] = L[i][j] + L[i-2][j-1];
      		if(C[i][j] >= mod) C[i][j] -= mod;
    	}
  	}
  	for(int i=0;i<=N;i++) {
    	bin[i][0] = bin[i][i] = 1;
    	for(int j=1;j<i;j++) {
      		bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
      		if(bin[i][j] >= mod) bin[i][j] -= mod;
    	}
  	}
    //阶乘 
	factorial[0] = 1;
	for(int i=1;i<=N;i++) factorial[i] = (long long)factorial[i-1] * i % mod;
}

vector<int> compute(vector<int> cycle) {
	vector<int> x(N+1,0);
	x[0] = 1;
  	rep(i,cycle.size()) {
    	for(int j=N;j>=0;j--) if(x[j]) {
    		for(int k=1;k<=cycle[i]/2;k++) if(j+k<=N) {
    			x[j+k] += (long long)x[j] * C[cycle[i]][k] % mod;
        		if(x[j+k] >= mod) x[j+k] -= mod;
      		}
    	}
  	}
  	return x;
}

int solve() {
  // generate cycles
  	vector<bool> visited(N,false);
  	vector<int> cycle;
  	for(int i=0;i<N;i++) if(!visited[i]) {
    	int sz=0,at=i;
    	while(!visited[at]) {
      		visited[at]=true;
      		sz+=2;
      		at=B[A[at]];
    	}
    	cycle.push_back(sz);
  	}
  	vector<int> x = compute(cycle);
  	vector<int> F(N+1,0);
  	for(int n=N;n>=0;n--) {
    	F[n] = (long long)x[n] * factorial[N-n] % mod;
    	for(int i=n+1;i<=N;i++) {
      		F[n] -= (long long)bin[i][n] * F[i] % mod;
      		if(F[n] < 0) F[n] += mod;
    	}
  	}
  	return F[0];
}

int main() {
  	prepare(maxn);
  	if(true) cin.sync_with_stdio(false);
  	int T;
  	for(cin>>T;T;T--){
    	cin>>N;
    	rep(i,N) {
      		int a; cin>>a;
      		A[i] = a-1;
    	}
    	rep(i,N) {
      		int b; cin>>b;
      		B[b-1] = i;
    	}
    	printf("%d\n",solve());
  	}
  	
  	return 0;
}
