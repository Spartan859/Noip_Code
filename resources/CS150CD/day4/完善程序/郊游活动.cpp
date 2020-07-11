#include<iostream>
using namespace std;
#define MAXN 1000000
int n,B,A,M[MAXN],C[MAXN],l,r,ans,mid;
bool check(int nn) {
	int count=0, i,j;
	i = ____(1)____;
	j = 1;
	while(i<=n) {
		if(____(2)____)
			count+=C[j]-M[i];
		i++;
		j++;
	}
	return ____(3)____;
} 
void sort(int a[], int l, int r) {
	int i = l, j = r, x = a[(l + r) / 2], y;
	while (i <= j) {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			y = a[i]; a[i] = a[j]; a[j] = y;
			i++; j--;
		}
	}
	if (i < r) sort(a, i, r);
	if (l < j) sort(a, l, j);
}
int main() {
	int i;
	cin >> n >> B >> A;
	for (i = 1; i <= n; i++)
		cin >> M[i];
	for (i = 1; i <= B; i++)
		cin >> C[i];
	sort(M, 1, n);
	sort(C, 1, B);
	l = 0;
	r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		if ( ____(4)____ ) {
			ans = mid;
			l = mid + 1;
		} else
			r = ____(5)____;
	}
	cout << ans << endl;
	return 0;
}
