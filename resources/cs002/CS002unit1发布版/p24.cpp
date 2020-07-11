#include<iostream>
#include<cstring>
#include<cmath>
#define ERR 0.000001
using namespace std;
int used[10],o[10];
double d[10]; 
//d[i] is the i-th input 
//used[i]==1 means the i-th number is used. 
//o[x]=i means that the x-th number in the answer output is d[i]
char op[10];
//op[i] is the operator for the i-th step

void search(int step){  //there are 3 steps in all
int i,j;
	if (step==4) {
		if (abs(d[6]-24)<ERR){
			//print out all the 3 steps
			for(i=1;i<=3;i++){
				cout<<d[o[i*2-1]]<<op[i]<<d[o[i*2]]<<'='<<d[3+i]<<endl;
			}
			exit(0);
		} 
		return;
	} else {
		for(i=0;i<=2+step;i++) if (used[i]==0) for(j=0;j<=2+step;j++) if (i!=j && used[j]==0) {
			used[i]=used[j]=1; 
			o[step*2-1]=i; o[step*2]=j;
			//+
			if (d[i]>=d[j]) { d[3+step]=d[i]+d[j]; op[step]='+'; search(step+1); }
			//-
			if (d[i]>d[j]) { d[3+step]=d[i]-d[j]; op[step]='-'; search(step+1); }
			//*
			if (d[i]>=d[j]) { d[3+step]=d[i]*d[j]; op[step]='*'; search(step+1); }
			// div
			if (abs(d[j])>ERR ) { d[3+step]=d[i]/d[j]; op[step]='/'; search(step+1); }
			used[i]=used[j]=0;			
		}		
	}	
}
int main(){
	for(int i=0;i<4;i++) cin>>d[i];
	search(1);
	cout<<"No answer!"<<endl;
	return 0;
}
