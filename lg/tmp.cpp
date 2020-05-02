#include<bits/stdc++.h>//万能头文件 
using namespace std;//使用标准命名空间
//前两句不需要理解，照着打上去就行
int n,k;//定义变量
int scores[10005];//定义数组来储存输入的成绩 
int main(){//主函数
	cin>>n>>k;//输入两个题目里给的变量，注意>>方向向右
	for(int i=1;i<=n;i++) //循环：i=1，执行一次下面内容，i加上1等于2，再执行一次，直到i加到n最后执行一遍，结束循环。 
		cin>>scores[i];//输入成绩，编号i从1到n 
	for(int i=n;i>=n-k+1;i--)// 循环：i=n，执行一次下面内容，i--=n-1，再执行一次，直到i=n-k+1最后执行一遍，结束循环。
		cout<<scores[i]<<' ';//输出成绩，给的是从小到大，所以从大到小需要倒序输出 
	return 0;
} 
