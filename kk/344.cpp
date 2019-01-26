#include <deque>
#include <iostream>
using namespace std;
template<class T>
void GetMaxOfMoveWindow(T nums[], int length, int window_size) {
    if (nums == NULL || length <= 0 || window_size <= 0 || length < window_size)
        return;
    deque<int> max_index_queue; // 存储窗口中最大值的索引
    int begin = 0, end = 0; // 窗口的开始和结束
    while (end < length) {
        if (!max_index_queue.empty() && max_index_queue.front() < begin) {
            max_index_queue.pop_front(); //已有最大值已滑出窗口
        }

        if (!max_index_queue.empty() && nums[end] > nums[max_index_queue.front()]) {
            // 新值，大于已有的最大值，删除所有，存入新值
            max_index_queue.clear();
            max_index_queue.push_back(end);
        } else {
            // 比已有最大值小，仍有成为新窗口最大值的可能
            while (!max_index_queue.empty() && nums[end] >= nums[max_index_queue.back()]) {
                max_index_queue.pop_back(); // 队列中所有比新值小已经没有可能
            }
            max_index_queue.push_back(end);
        }

        if (end >= window_size-1) 
            cout << nums[max_index_queue.front()] << " ";
        // 滑动窗口
        end++;
        if (end > window_size-1)
            begin++;
    }
}

int main() {
	int n,k;
	cin>>n>>k;
	int nums[n];
	for(int i=0;i<n;i++) cin>>nums[i];
    int length = sizeof(nums)/sizeof(nums[0]);
    const int window_size = k;
    GetMaxOfMoveWindow(nums, length, window_size);
}
