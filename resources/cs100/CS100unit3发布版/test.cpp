#include<iostream>
#include<string>
using namespace std;
void  encrypt(string &s)//º”√‹
{
  
 int i=s.length();
 for(int j=0;j<i;++j)
 {
  if('A'<=s[j]&&s[j]<='Z')
  {
   if('A'<=s[j]&&s[j]<='W')
    s[j]+=3;
   else
    s[j]-=23;
   //cout<<s[j];
   s[j]+=32;
   //cout<<s[j]<<endl;
  }
  else if('a'<=s[j]&&s[j]<='z')
  {
   if('a'<=s[j]&&s[j]<='w')
    s[j]+=3;
   else
    s[j]-=23;
   //cout<<s[j];
   s[j]-=32;
   //cout<<s[j]<<endl;
    
  }
   
 }
}
 
int main()//≤‚ ‘
{
 string xy;
 cout<<" ‰»Î◊÷∑˚¥Æ"<<endl;
 cin>>xy;
 encrypt(xy);
 cout<<xy<<endl;
 return 0;
 
}
