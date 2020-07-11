#include <iostream>
using namespace std;

int main()
{
	int medals[3][4] = {
    {28, 30, 28, 86},
    {19, 19, 12, 50},
    {17, 15, 20, 52}};
    for (int i=0; i < 3; ++i) {  // 循环每一行 
    	for (int j=0; j < 4; ++j) {  // 循环每一列 
    		cout << medals[i][j] << " ";  // 打印数组元素 
		}
		cout << endl;  // 每循环一行后，打印换行 
	}
	return 0;
} 
