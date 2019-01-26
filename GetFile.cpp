#include<bits/stdc++.h>
#include"stdio.h"
#include"assert.h"
#include"stdlib.h"
#include"winsock2.h"
#include "string"
#include"Wininet.h"
#include"iostream"
#include "windows.h"
#include"io.h"
#include"vector"
using namespace std;
string filePath="C:\\myserver\\mcoasis\\client\\.minecraft\\Flan\\DebdoM.Com_Pokers+Garage+V\\vehicles\\test";
string filePath2="C:\\myserver\\mcoasis\\client\\.minecraft\\Flan\\DebdoM.Com_Pokers+Garage+V\\vehicles\\test2";
void getFiles( string path, vector<string>& files )  
{  
    //文件句柄  
    long   hFile   =   0;  
    //文件信息  
    struct _finddata_t fileinfo;  
    string p;  
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
    {  
        do  
        {  
            //如果是目录,迭代之  
            //如果不是,加入列表  
            if((fileinfo.attrib &  _A_SUBDIR))  
            {  
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
                    getFiles( p.assign(path).append("\\").append(fileinfo.name), files );  
            }  
            else  
            {  
                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
            }  
        }while(_findnext(hFile, &fileinfo)  == 0);  
        _findclose(hFile);  
    }  
}
int main(){
	vector<string> files,files2; 
	getFiles(filePath, files);
	getFiles(filePath2,files2);
	int size = files.size();
	int size2=files2.size();
	string s;
	for (int i = 0;i < size;i++){
    	ifstream fin(files[i].c_str(),ios::in);
    	ofstream fout(files2[i].c_str(),ios::in);
    	while(getline(fin,s)){
    		if(s.substr(0,14)!="AddRecipeParts") fout<<s<<endl;	
		}
	}
	return 0;
}
 
