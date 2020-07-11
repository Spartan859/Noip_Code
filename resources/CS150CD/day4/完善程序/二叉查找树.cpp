#include<iostream>
using namespace std;
const int SIZE=100;
const int INFINITE=1000000;
struct node {
	int left_child, right_child, value;
};
node a[SIZE];
int is_bst(int root, int lower_bound, int upper_bound) {
	int cur;
	if(root==0) return 1;
	cur=a[root].value;
	if((cur>lower_bound) && (____(1)____) &&
		(is_bst(a[root].left_child, lower_bound, cur)==1) &&
		(is_bst(____(2)____, ____(3)____, ____(4)____)==1))
		return 1;
	return 0;
}
int main() {
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].value>>a[i].left_child>>a[i].right_child;
	cout<<is_bst(___(5)____, -INFINITE, INFINITE)<<endl;
	return 0;
}

/*

*/
