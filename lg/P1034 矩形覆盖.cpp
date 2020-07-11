#include <bits/stdc++.h>
#define N 55
using namespace std;

int n, k, x[N], y[N], ans = INT_MAX >> 2;
struct mat {
	int lx, ly, rx, ry;
	bool cnt;
	void add(int x, int y) {
		if(!cnt) {
			lx = rx = x;
			ly = ry = y;
			cnt = 1;
		} else {
			if(x < lx) lx = x;
			else if(x > rx) rx = x;
			if(y > ly) ly = y;
			else if(y < ry) ry = y;
		}
	}
	bool inmat(int x, int y) const {
		return lx <= x && x <= rx && ry <= y && y <= ly;
	}
	int operator() () {
		if(!cnt) return 0;
		return (rx - lx) * (ly - ry);
	}
	bool operator* (const mat &o) {
		if(!cnt || !o.cnt) return 0;
		return o.inmat(lx, ly) || o.inmat(lx, ry) ||
			o.inmat(rx, ly) || o.inmat(rx, ry);
	}
} km[5];

bool check() {
	for(int i = 1;i <= k;i++)
		for(int j = i + 1;j <= k;j++)
			if(km[i] * km[j]) return 0;
	return 1;
}

void dfs(int i, int area) {
	if(area >= ans) return;
	if(i == n) {
		if(check())
			if(ans > area) ans = area;
		return;
	}
	mat tmp;
	for(int j = 1;j <= k;j++) {
		tmp = km[j];
		km[j].add(x[i], y[i]);
		dfs(i + 1, area - tmp() + km[j]());
		km[j] = tmp;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++)
		scanf("%d%d", x + i, y + i);
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}
