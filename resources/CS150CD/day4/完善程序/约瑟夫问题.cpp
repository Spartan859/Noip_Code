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
ԭʼ��Joseph�����������£���n����Χ����һ��Բ����Χ��
����n�������α��Ϊ1,��,n���ӱ����1���˿�ʼ������
������m���˳��У�Ȼ��ӳ��е���һ�������¿�ʼ������
������m�����ֳ��У�������˷�����
ֱ�����е���ȫ������Ϊֹ��
���統n=6,m=5��ʱ�򣬳��е�˳��������5,4,6,2,3,1��
���ڵ������ǣ�������k�����˺�k�����ˡ�
���˵ı�Ŵ�1��k�����˵ı�Ŵ�k+1��2k��
����ϣ�����m����Сֵ��ʹ�����ȳ��е�k���˶��ǻ��ˡ�
*/
