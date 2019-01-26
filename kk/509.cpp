#include<bits/stdc++.h>
using namespace std;
int main(){  
    int s,t,i=0,w,j,k;  
    string arr;
    cin>>s>>t>>w;
    cin>>arr;
    for (i=0;i<5;i++){  
        for (j=w-1;j>=0;j--){  
            if (arr[j]+1<=('a'+(t-(w-j)))){   
                arr[j]+=1;  
                for (k=j+1;k<w;k++)   
                    arr[k]=arr[j]+k-j;  
                cout<<arr<<endl;  
                break;  
            }  
        }  
    }  
    return 0;  
} 
//CopyRight Spartan117 2018.6.3 
