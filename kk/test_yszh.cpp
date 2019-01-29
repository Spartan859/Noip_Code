#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;
 
LL X, Y;
LL solve(LL);
 
int main(){
  cin >> X >> Y;
  cout << solve(Y) - solve(X - 1) << endl;
  return 0;
}
 
LL solve(LL N){
  if(N <= 1) return N;
  LL i, j, res = 0;
  for(i = 1; i <= N; i = j + 1){
    j = N / (N / i);
    res += (N / i) * (i + j) * (j - i + 1) / 2;
  }
  return res;
}
