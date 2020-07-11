#include<iostream>
using namespace std;
int n;
char c;

void pyramid(int m,char x){
    for(int b=0;b<m;b++){//控制金字塔层高度
	for(int c=b;c<m-1;c++){//金字塔是三角形的所以最顶端是有很多空格，这里控制输出空格
    cout<<" ";
}
    for(int d=0;d<=2*b;d++){//空格输出后输出金字塔砖块
    cout<<x;
}
    cout<<endl;//一层盖完了换行进入下一次继续盖 从最顶端开始盖 }
	}
    
}

 
int main(){
cin>>n>>c;
pyramid(n,c);
pyramid(2*n,c);
return 0; } 
