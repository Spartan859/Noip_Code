#include<stdio.h>
#include<string.h>
int n, mod;
typedef struct
{
	int i, j;
	int a[32][32];
	void init()
	{
		memset(a, 0, sizeof(a));
	}
	void unit()
	{
		memset(a, 0, sizeof(a));
		for(i=1;i<=n;i++)
			a[i][i] = 1;
	}
}Matrix;
Matrix Jz;
Matrix Powto(Matrix p, int k);
Matrix Jjcf(Matrix p1, Matrix p2);

Matrix Powto(Matrix p, int k)
{
	Matrix bg, E;
	E.unit();
	if(k==0)
		return E;
	if(k==1)
		return p;
	bg = Powto(p, k>>1);
	bg = Jjcf(bg, bg);
	if((k&1)==1)
		bg = Jjcf(bg, p);
	return bg;
}
 
Matrix Jjcf(Matrix p1, Matrix p2)
{
	Matrix pe;
	int i, j, k;
	memset(pe.a, 0, sizeof(pe.a));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
				pe.a[i][j] = (pe.a[i][j]+p1.a[i][k]*p2.a[k][j])%mod;
		}
	}
	return pe;
}

int main()
{
	int k, p, q, i, ans, net[25];
	char str[25], j;
	while(scanf("%d%d%d", &k, &n, &mod)!=EOF)
	{
		Jz.init();
		scanf("%s", str+1);
		memset(net, 0, sizeof(net));
		p = 0, q = 1, net[1] = 0;
		while(q<=n)
		{
			if(p==0 || str[p]==str[q])
			{
				p++, q++;
				if(str[p]==str[q])
					net[q] = net[p];
				else
					net[q] = p;
			}
			else
				p = net[p];
		}
		Jz.a[1][1] = 9, Jz.a[1][2] = 1;
		for(i=1;i<=n-1;i++)
		{
			for(j='0';j<='9';j++)
			{
				p = i+1;
				while(str[p]!=j && p!=0)
					p = net[p];
				Jz.a[i+1][p+1]++;
			}
		}
		Jz = Powto(Jz, k);
		ans = 0;
		for(i=1;i<=n;i++)
			ans = (ans+Jz.a[1][i])%mod;
		printf("%d\n", ans);
	}
	return 0;
}
