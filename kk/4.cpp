#include<iostream>
using namespace std;
int main()
{
 int i,j,k,h,s;
 int a[10];
 for(i=123;i*3<=987;i++)
 {
  for(h=1;h<10;h++)
  a[h]=0;
  a[i/100]=1;
  a[i/10%10]=1;
  a[i%10]=1;
  j=i*2;
  a[j/100]=1;
  a[j/10%10]=1;
  a[j%10]=1;
  k=i*3;
  a[k/100]=1;
  a[k/10%10]=1;
  a[k%10]=1;
  for(s=0,h=1;h<10;h++)
  s=s+a[h];
  if(s==9)
  cout<<i<<' '<<j<<' '<<k<<endl;
 }
 return 0;
}
