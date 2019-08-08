#include<bits/stdc++.h> 
using namespace std;
int n,m,p,fake[21],err,w[200],nx;
string name[100],say[200];
string day[10]={"233","Today is Sunday.","Today is Monday.","Today is Tuesday.","Today is Wednesday.","Today is Thursday.","Today is Friday.","Today is Saturday.",};
void set_t(int who,int yx){
    if(fake[who]&&fake[who]!=yx)err=1;
    else fake[who]=yx;
}
int main(){
    cin>>m>>n>>p;
    for(int i=1;i<=m;i++)
        cin>>name[i];
    for(int i=1;i<=p;i++){
        string nm;
        cin>>nm;
        nm.erase(nm.end()-1);

        for(int j=1;j<=m;j++)
        if(name[j]==nm)w[i]=j;

        getline(cin,say[i]);
        say[i].erase(say[i].begin());
    //  say[i].erase(say[i].end()-1);
    }
    for(int td=1;td<=7;td++) 
    	for(int px=1;px<=m;px++){ 
	        err=0;
    	    memset(fake,0,sizeof(fake)); 
	
    	    for(int i=1;i<=p;i++){ 
        	    int who=w[i];
    	        if(say[i]=="I am guilty.")set_t(who,px==who?1:-1);
	            if(say[i]=="I am not guilty.")set_t(who,px!=who?1:-1);

    	        for(int j=1;j<=7;j++)
        	    if(say[i]==day[j])set_t(who,j==td?1:-1);
	            for(int j=1;j<=m;j++){
    	            if(say[i]==name[j]+" is guilty.")set_t(who,j==px?1:-1);
        	        if(say[i]==name[j]+" is not guilty.")set_t(who,j!=px?1:-1);
            	}
        	}
    		int cnt=0,ppp=0;//cnt:说假话的人数，ppp:不确定的人数 
    		for(int i=1;i<=m;i++){
        		if(fake[i]==-1)cnt++;
        		if(fake[i]==0)ppp++;
    		}
    	if(!err&&cnt<=n&&cnt+ppp>=n)
        	if(nx&&nx!=px){
            	cout<<"Cannot Determine";
            	return 0;
        	}else nx=px;
    	}
    if(!nx)cout<<"Impossible"; 
    else cout<<name[nx];
}
