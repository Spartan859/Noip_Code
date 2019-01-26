#include<bits/stdc++.h>//万能头文件。
#define iyt multimap<int,pair<int,int> >::iterator//宏定义迭代器，调试的时候用，现在已没用...
using namespace std;
multimap<int,pair<int,int> > mkp;//哈希（二元组套二元组的是不是很稀有啊）
int main()
{
    int n,m,time,sum=0;;//额，多打了一个分号。
    cin>>n>>m>>time;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int a;
            cin>>a;
            if(a) mkp.insert(make_pair(a*-1,make_pair(i,j)));//哈希读入，乘-1是因为哈希从小到大排序，哈希中的二元组第一个为x坐标，第二个y标。
        }
    }
    int last=mkp.begin()->first,last2=0;//last和last2是用来当时间到了回不去时判断的。
    time-=mkp.begin()->second.first+1;//time记录剩余时间。
    int i=mkp.begin()->second.first,j=mkp.begin()->second.second;//i和j记录现在坐标。
    while(time-i>=0&&!mkp.empty())//循环条件不细说了。
    {
        if(last2) time=time-abs(mkp.begin()->second.second-j)-abs(mkp.begin()->second.first-i)-1;//当做过的时候将time更新。
        sum=sum+last*-1;//sum累加。
        i=mkp.begin()->second.first;//i更新
        j=mkp.begin()->second.second;//j更新。
        mkp.erase(mkp.begin());//删除已做过的一号位。
        last2=last;//last2更新last更新。
        last=mkp.begin()->first;
    }
//重要的事情说三遍，下面一个判断很重要。
//下面一个判断很重要。
//下面一个判断很重要。
    if(!mkp.empty()||time-i<0)cout<<sum-last2*-1<<endl;
   else  cout<<sum<<endl;//当是因为取光花生时，直接输出sum便可以了，不用减。
    return 0;
}
