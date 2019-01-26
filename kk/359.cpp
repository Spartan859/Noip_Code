#include<iostream>
#include<string>
#define SIZE 3200
using namespace std;
void converts(int *a,string s){
    int i,len=s.size();
    for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
    for(;i<SIZE;i++) a[i]=0;
}
//∏ﬂæ´∂»*int, œ‡µ±”⁄a*=b, “™«Ûb>0
void mul(int *a, int b) {
    for(int i=0,c=0; i<SIZE; i++){
        c = c/10 + a[i]*b;
        a[i] = c%10;
    }
}
void copy(int *a, int *b) {
    for(int i=0;i<SIZE;i++)a[i]=b[i];
}
//≈–∂œa<=b
bool le(int *a, int *b, int len=SIZE) {
    int i;
    for(i=len-1; i>=0&&a[i]==b[i]; i--);
    return i<0 || a[i]<b[i];
}
//∏ﬂæ´∂»-∏ﬂæ´∂»£¨œ‡µ±”⁄a-=b£¨◊¢“‚»∑±£a>=b
void sub(int *a, int *b, int len=SIZE) {
    for(int i=0;i<len;i++)
        if((a[i]-=b[i])<0){//ΩËŒª
            a[i+1]--;
            a[i]+=10;
        }
}
//∏ﬂæ´∂»/∫Õ%∏ﬂæ´∂»£¨q=a/b, r=a%b£¨“™«Ûb>0
void div(int *q,int *r,int *a,int *b){
    converts(q,"0");	//≥ı ºªØ…Ã
    copy(r,a);			//≥ı ºªØ”‡ ˝
    int j;
    for(j=SIZE-1; b[j]==0; j--) ; //’“b◊Ó∏ﬂ∑«¡„Œª÷√j
    for(int i=SIZE-1-j; i>=0; i--)
        for( ;le(b,r+i,SIZE-i); q[i]++)
            sub(r+i,b,SIZE-i);
}
void print(int *a){
    int i;
    for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
    for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE],y[SIZE],z[SIZE],a[SIZE];
int main(){
	int n,m;
	cin>>n>>m;
	converts(x,"1");
	converts(y,"1");
    for(int i=n;i>n-m;i--) mul(x,i);
    for(int i=m;i>=1;i--) mul(y,i);
    div(a,z,x,y);
    print(a);
    return 0;
}
