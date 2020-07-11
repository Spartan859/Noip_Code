/*
打印出杨辉三角形（要求打印出10行）
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int i,j;
    int a[10][10];
    for(i=1;i<10;i++){
	    a[i][j]=1;
        a[i][i]=1;
    }
    for(i=1;i<10;i++)
    for(j=1;j<i;j++)
    a[i][i]=a[i-1][j-1]+a[i-1][j];
    for(i=0;i<10;i++){
	    for(j=0;j<=i;j++)
        cout<<setw(5)<<a[i][j];
        cout<<endl;
    }
}

