#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
lint a,b,c;
lint ex_gcd(lint a, lint b, lint& x, lint& y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	lint r = ex_gcd(b, a % b, x, y);
	lint t = x;
	x = y;
	y = t - a / b * y;
	return r;
}

bool check(lint a, lint b, lint c, lint& x, lint& y)
{
	lint r = ex_gcd(a, b, x, y);
	if(c % r)
	{
		return false;
	}
	a /= r; b /= r; c /= r;
	x *= c;
	x = ((x % b) + b ) % b;
	y = (c - a * x) / b;
	return y >= 0;
}

int main()
{
	cin>>a>>b>>c;
	lint x, y;
	if(check(a, b, c, x, y))
	{
		printf("其中一组解是:\n x = %lld, y = %lld\n", x, y);
	}
	else
	{
		printf("无解\n");
	}
	return 0;
}
