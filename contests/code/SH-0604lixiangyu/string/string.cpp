#include<bits/stdc++.h>
#define ll long long
using namespace std;

char a[2005],b[2005];
char s_new[4010];
int p[4010];
int n;

int Init(char* s) {
    int len=strlen(s);
    s_new[0]='$';
    s_new[1]='#';
    int j=2; 
    for(int i=0;i<len;i++) {
        s_new[j++]=s[i];
        s_new[j++]='#';
    } 
    s_new[j]='\0';
    return j; 
}

int Manacher(char* s) {
    int len=Init(s);
    int max_len=-1;
    int id;
    int mx=0;
    memset(p,0,sizeof(p));
    for(int i=1;i<=len;i++) {
        if(i<mx)
            p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        while(s_new[i-p[i]]==s_new[i+p[i]])
            p[i]++;
        if(mx<i+p[i]) {
            id=i;
            mx=i+p[i];
        }
        max_len=max(max_len,p[i]-1); 
    } 
    return max_len; 
}
 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
    scanf("%s",&a);
    scanf("%s",&b);
    int ans=Manacher(a);ans=max(ans,Manacher(b));
    for(int i=0;i<n;i++){
    	if(a[i]!=b[i]) continue;
    	int anst=2,j=i-1,k=i+1;
    	while(j>=0&&k<n&&a[j]==b[k]) anst+=2,j--,k++;
    	ans=max(ans,anst);
	}
	for(int i=0;i<n-1;i++){
		if(a[i]!=b[i+1]) continue;
		int anst=3,j=i-1,k=i+2;
		while(j>=0&&k<n&&a[j]==b[k]) anst+=2,j--,k++;
		ans=max(ans,anst);
	}
	printf("%d\n",ans);
    return 0;
}
