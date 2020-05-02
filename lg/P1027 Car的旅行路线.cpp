#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>

#define eps 0.000001

using namespace std;

struct Vector
{
    double x,y;
    Vector(int x=0,int y=0):x(x),y(y){}
    friend Vector operator+(const Vector&a,const Vector&b){return Vector(a.x+b.x,a.y+b.y);}
    friend Vector operator-(const Vector&a,const Vector&b){return Vector(a.x-b.x,a.y-b.y);}
    friend double operator*(const Vector&a,const Vector&b){return (a.x*b.x+a.y*b.y);}
    friend double operator^(const Vector&a,const Vector&b){return (a.x*b.y-a.y*b.x);}
    friend istream& operator>>(istream& in,Vector a){in>>a.x>>a.y;return in;}
    double mod(){return sqrt(x*x+y*y);}
};

struct Dijkstra
{
    struct edge
    {
        int v,ne;
        double w;
    }a[200010];

    Vector pos[100010];
    double dis[100010];
    int h[100010],n,s,tmp,city[100010],tmp2;
    bool v[100010];

    void debug()
    {
//      printf("%d\n",n);
//      for(int i=1;i<=n;i++)
//      {
//          printf("i=%d city=%d h=%d dis=%f (%f,%f)\n",i,city[i],h[i],dis[i],pos[i].x,pos[i].y); 
//      }
//      for(int x=1;x<=n;x++)
//      for(int i=h[x];i!=0;i=a[i].ne)
//      {
//          printf("[%d(%d)] %d [%d(%d)] %d %f\n",x,city[x],i,a[i].v,city[a[i].v],a[i].ne,a[i].w);
//      }
    }

    void addedge(int u,int v,int w)//w?????? 
    {
//      printf("add %d(%d) %d(%d) %d\n",u,city[u],v,city[v],w); 
        a[++tmp]=(edge){v,h[u],(pos[u]-pos[v]).mod()*w};
        h[u]=tmp;
        a[++tmp]=(edge){u,h[v],(pos[u]-pos[v]).mod()*w};
        h[v]=tmp;
    }

    int addpoint(Vector p,int c)
    {
        city[++tmp2]=c;
        pos[tmp2]=p;
        return tmp2;
    }

    void clear()
    {
        memset(a,0,sizeof(a));
        memset(h,0,sizeof(h));
        memset(dis,0,sizeof(dis));
        memset(v,0,sizeof(v));
        memset(city,0,sizeof(city));
        n=s=tmp=tmp2=0;
    }

    void dijkstra()
    {
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++)
            dis[i]=999999999.0;
        dis[s]=0;
        priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > >q;
        q.push(make_pair(0.0,s));
        while(!q.empty())
        {
            int x=q.top().second;
            q.pop();
            if(v[x])continue;
            v[x]=1;
            for(int i=h[x];i!=0;i=a[i].ne)
            {
//              printf("%d %f %f %f\n",x,dis[x],a[i].w,dis[a[i].v]);
                if(dis[x]+a[i].w<dis[a[i].v])
                {
                    dis[a[i].v]=dis[x]+a[i].w;
                    q.push(make_pair(dis[a[i].v],a[i].v));
                }
            }
        }
    }
}solution;

int S,T,A,B;

void work(int city,Vector p1,Vector p2,Vector p3,int T)
{
    if(fabs((p1-p2)*(p2-p3))<=eps)swap(p1,p2);
    else if(fabs((p1-p3)*(p2-p3))<=eps)swap(p1,p3);
    Vector p4=p2+p3-p1;
    int f1=solution.addpoint(p1,city);
    int f2=solution.addpoint(p2,city);
    int f3=solution.addpoint(p3,city);
    int f4=solution.addpoint(p4,city);
    solution.addedge(f1,f2,T);
    solution.addedge(f1,f3,T);
    solution.addedge(f1,f4,T);
    solution.addedge(f2,f3,T);
    solution.addedge(f2,f4,T);
    solution.addedge(f3,f4,T);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double ans=999999999;
        solution.clear();
        cin>>S>>T>>A>>B;
        Vector p1,p2,p3;
        for(int Te,i=1;i<=S;i++)
        {
            scanf("%lf%lf%lf%lf%lf%lf%d",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&Te);
//          printf("(%f,%f)(%f,%f)(%f,%f)%d\n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,Te); 
            work(i,p1,p2,p3,Te);
        }
        for(int i=1;i<=4*S;i++)
            for(int j=i+1;j<=4*S;j++)
                if(solution.city[i]!=solution.city[j])
                    solution.addedge(i,j,T);
        solution.n=4*S;
        solution.debug();
        for(int i=1;i<=4*S;i++)
        {
            if(solution.city[i]==A)
            {
                solution.s=i;
                solution.dijkstra();
                for(int j=1;j<=4*S;j++)
                {
                    if(solution.city[j]==B)
                    {
//                      printf("found %f\n",solution.dis[j]);
                        ans=min(ans,solution.dis[j]);
                    }
                }
//              solution.debug();
            }
        }
        printf("%.1f\n",ans);
    }
    return 0;
}
