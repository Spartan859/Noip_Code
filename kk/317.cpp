#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> min; //数组中的后一半元素组成一个最小化堆
        vector<int> max; //数组中的前一半元素组成一个最大化堆
    public:
        void Insert(int num) {
            if(((min.size()+max.size()) & 1) == 0) {  //偶数数据的情况下，则在最小堆中插入元素
                if(max.size() > 0 && num < max[0]) {
                    max.push_back(num);
                    push_heap(max.begin(), max.end(), less<int>());
                    num=max[0];
                    pop_heap(max.begin(), max.end(), less<int>());
                    max.pop_back();
                }
                min.push_back(num); //把前一半找到的最大值放到后一半中
                push_heap(min.begin(), min.end(), greater<int>());
            } else {
                if(min.size() > 0 && num > min[0]) {   //奇数数据的情况下，则在最大堆中插入元素
                    min.push_back(num);
                    push_heap(min.begin(), min.end(), greater<int>());
                    num=min[0];
                    pop_heap(min.begin(), min.end(), greater<int>());
                    min.pop_back(); 
                }
                max.push_back(num); //把后一半找到的最大值放到前一半中
                push_heap(max.begin(), max.end(), less<int>());
            }
        }

        double GetMedian() { 
            int size=min.size() + max.size();
            if(size==0) return -1;
            double median = 0;
            if((size&1) != 0) {
                median = (double) min[0];
            } else {
                median = (double) (max[0] + min[0]) / 2;
            }
            return median;
        }
};

int main() {
    Solution s;
    vector<int> v{5,2,3,4,1,6,7,0,8};
    for (int i = 0; i < v.size(); ++i) {
        s.Insert(v[i]);
        cout << s.GetMedian() << endl;
    }
    return 0;
}
