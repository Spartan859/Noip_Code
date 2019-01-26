#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> min; //�����еĺ�һ��Ԫ�����һ����С����
        vector<int> max; //�����е�ǰһ��Ԫ�����һ����󻯶�
    public:
        void Insert(int num) {
            if(((min.size()+max.size()) & 1) == 0) {  //ż�����ݵ�����£�������С���в���Ԫ��
                if(max.size() > 0 && num < max[0]) {
                    max.push_back(num);
                    push_heap(max.begin(), max.end(), less<int>());
                    num=max[0];
                    pop_heap(max.begin(), max.end(), less<int>());
                    max.pop_back();
                }
                min.push_back(num); //��ǰһ���ҵ������ֵ�ŵ���һ����
                push_heap(min.begin(), min.end(), greater<int>());
            } else {
                if(min.size() > 0 && num > min[0]) {   //�������ݵ�����£����������в���Ԫ��
                    min.push_back(num);
                    push_heap(min.begin(), min.end(), greater<int>());
                    num=min[0];
                    pop_heap(min.begin(), min.end(), greater<int>());
                    min.pop_back(); 
                }
                max.push_back(num); //�Ѻ�һ���ҵ������ֵ�ŵ�ǰһ����
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
