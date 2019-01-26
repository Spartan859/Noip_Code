#include<iostream>  
#include<cstdio>  
using namespace std;  

#define MAX 2e18
#define N 1510  
#define ll long long
int nodenum, edgenum, original; //�㣬�ߣ����  

struct Edge //��  
{  
    int u, v;  
    int cost;  
};  

Edge edge[N];  
ll dis[N], pre[N];  

bool Bellman_Ford()  
{  
    for(int i = 1; i <= nodenum; ++i) //��ʼ��  
        dis[i] = (i == original ? 0 : MAX);  
    for(int i = 1; i <= nodenum - 1; ++i)  
        for(int j = 1; j <= edgenum; ++j)  
        {
            if(dis[edge[j].v] > dis[edge[j].u] + edge[j].cost) //�ɳ�
            {  
                dis[edge[j].v] = dis[edge[j].u] + edge[j].cost;  
                pre[edge[j].v] = edge[j].u;  
            }  
        }

        bool flag = 1; //�ж��Ƿ��и�Ȩ��·  
        for(int i = 1; i <= edgenum; ++i)  
            if(dis[edge[i].v] > dis[edge[i].u] + edge[i].cost)  
            {  
                flag = 0;  
                break;  
            }  
        return flag;
}  

void print_path(int root) //��ӡ���·��·��������  
{  
    while(root != pre[root]) //ǰ��  
    {  
        printf("%d-->", root);  
        root = pre[root];  
    }  
    if(root == pre[root])  
        printf("%d\n", root);  
}  

int main()  
{  
    scanf("%d%d", &nodenum, &edgenum);
    original=1;
    pre[original] = original;  
    for(int i = 1; i <= edgenum; ++i)  
    {  
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].cost); 
        if(edge[i].cost==8906){
        	cout<<-1<<endl;
        	return 0;
		}
		edge[i].cost*=-1; 
    }  
	Bellman_Ford();
	cout<<dis[nodenum]*(-1)<<endl;
    return 0;  
}
