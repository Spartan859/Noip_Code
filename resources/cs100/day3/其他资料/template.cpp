#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime> 
using namespace std;
#define DEBUG

int main() {
	freopen("xx.in", "r", stdin);
	freopen("xx.out", "w", stdout);
#ifdef DEBUG
//调试代码写在这 
	int t_begin, t_end;
	t_begin = clock();  //获取程序运行前系统时间 
	//需要计时的代码 
	t_end = clock();    //获取程序运行后系统时间
	cout<<(t_end-t_begin)/double(1000)<<endl;	
#endif
	return 0;
}
 
