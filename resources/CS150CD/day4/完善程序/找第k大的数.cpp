#include <iostream>
using namespace std;
int a[1000001],n,ans = -1;
void swap(int &a,int &b) {
	int c;
	c = a; a = b;	b = c;
}
int FindKth(int left, int right, int n) {
	int tmp,value,i,j;
	if (left == right) return left;
	tmp = rand()% (right - left) + left;
	swap(a[tmp],a[left]);
	value =____(1)_____
	i = left;
	j = right;
	while (i < j) {
		while (i < j && ____(2)____) j --;
		if (i < j) {a[i] = a[j]; i ++;} else break;
		while (i < j && ____(3)____) i ++;
		if (i < j) {a[j] = a[i]; j - -;} else break;
	}
	____(4)____        
	if (i < n) return FindKth(____(5)____);
	if (i > n) return ____(6)____
	return i;
}
int main() {
	int i;
	int m = 1000000;
	for (i = 1;i <= m;i ++)
		cin >> a[i];
	cin >> n;
	ans = FindKth(1,m,n);
	cout << a[ans];
    return 0;
}

