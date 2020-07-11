#include<iostream>
using namespace std;
long k,m,begin;
int check(long remain) {
	long result=(___(1)____)%remain;
	if(____(2)____) {
		begin=result; return 1;
	}
	else return 0;
}
int main() {
	long i,find=0;
	cin>>k;
	m=k;
	while(____(3)____) {
		find=1; begin=0;
		for(i=0;i<k;i++)
			if(!check(____(4)____)){
				find=0;break;
			}
		m++;
	}
	cout<<____(5)____;
	return 0;
}


/*
原始的Joseph问题描述如下：有n个人围坐在一个圆桌周围，
把这n个人依次编号为1,…,n，从编号是1的人开始报数，
数到第m个人出列，然后从出列的下一个人重新开始报数，
数到第m个人又出列，……如此反复，
直到所有的人全部出列为止。
比如当n=6,m=5的时候，出列的顺序依次是5,4,6,2,3,1。
现在的问题是：假设有k个好人和k个坏人。
好人的编号从1到k，坏人的编号从k+1到2k。
我们希望求出m的最小值，使得最先出列的k个人都是坏人。
*/
