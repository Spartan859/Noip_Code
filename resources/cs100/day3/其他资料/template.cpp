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
//���Դ���д���� 
	int t_begin, t_end;
	t_begin = clock();  //��ȡ��������ǰϵͳʱ�� 
	//��Ҫ��ʱ�Ĵ��� 
	t_end = clock();    //��ȡ�������к�ϵͳʱ��
	cout<<(t_end-t_begin)/double(1000)<<endl;	
#endif
	return 0;
}
 
