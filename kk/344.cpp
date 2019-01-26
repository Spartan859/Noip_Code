#include <deque>
#include <iostream>
using namespace std;
template<class T>
void GetMaxOfMoveWindow(T nums[], int length, int window_size) {
    if (nums == NULL || length <= 0 || window_size <= 0 || length < window_size)
        return;
    deque<int> max_index_queue; // �洢���������ֵ������
    int begin = 0, end = 0; // ���ڵĿ�ʼ�ͽ���
    while (end < length) {
        if (!max_index_queue.empty() && max_index_queue.front() < begin) {
            max_index_queue.pop_front(); //�������ֵ�ѻ�������
        }

        if (!max_index_queue.empty() && nums[end] > nums[max_index_queue.front()]) {
            // ��ֵ���������е����ֵ��ɾ�����У�������ֵ
            max_index_queue.clear();
            max_index_queue.push_back(end);
        } else {
            // ���������ֵС�����г�Ϊ�´������ֵ�Ŀ���
            while (!max_index_queue.empty() && nums[end] >= nums[max_index_queue.back()]) {
                max_index_queue.pop_back(); // ���������б���ֵС�Ѿ�û�п���
            }
            max_index_queue.push_back(end);
        }

        if (end >= window_size-1) 
            cout << nums[max_index_queue.front()] << " ";
        // ��������
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
