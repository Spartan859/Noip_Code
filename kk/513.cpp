#include<bits/stdc++.h>//����ͷ�ļ���
#define iyt multimap<int,pair<int,int> >::iterator//�궨������������Ե�ʱ���ã�������û��...
using namespace std;
multimap<int,pair<int,int> > mkp;//��ϣ����Ԫ���׶�Ԫ����ǲ��Ǻ�ϡ�а���
int main()
{
    int n,m,time,sum=0;;//������һ���ֺš�
    cin>>n>>m>>time;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int a;
            cin>>a;
            if(a) mkp.insert(make_pair(a*-1,make_pair(i,j)));//��ϣ���룬��-1����Ϊ��ϣ��С�������򣬹�ϣ�еĶ�Ԫ���һ��Ϊx���꣬�ڶ���y�ꡣ
        }
    }
    int last=mkp.begin()->first,last2=0;//last��last2��������ʱ�䵽�˻ز�ȥʱ�жϵġ�
    time-=mkp.begin()->second.first+1;//time��¼ʣ��ʱ�䡣
    int i=mkp.begin()->second.first,j=mkp.begin()->second.second;//i��j��¼�������ꡣ
    while(time-i>=0&&!mkp.empty())//ѭ��������ϸ˵�ˡ�
    {
        if(last2) time=time-abs(mkp.begin()->second.second-j)-abs(mkp.begin()->second.first-i)-1;//��������ʱ��time���¡�
        sum=sum+last*-1;//sum�ۼӡ�
        i=mkp.begin()->second.first;//i����
        j=mkp.begin()->second.second;//j���¡�
        mkp.erase(mkp.begin());//ɾ����������һ��λ��
        last2=last;//last2����last���¡�
        last=mkp.begin()->first;
    }
//��Ҫ������˵���飬����һ���жϺ���Ҫ��
//����һ���жϺ���Ҫ��
//����һ���жϺ���Ҫ��
    if(!mkp.empty()||time-i<0)cout<<sum-last2*-1<<endl;
   else  cout<<sum<<endl;//������Ϊȡ�⻨��ʱ��ֱ�����sum������ˣ����ü���
    return 0;
}
