#include <queue>
using namespace std;

class MedianFinder {
public:
    // Max-heap to store the smaller half
    priority_queue<int> maxHeap;
    
    // Min-heap to store the larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
        // No initialization needed
    }
    
    void addNum(int num) {
        // Add to the maxHeap first
        maxHeap.push(num);
        
        // Make sure all elements in maxHeap are smaller than those in minHeap
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        // Balance the sizes of the two heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // If there are an odd number of elements, the median is the top of the maxHeap
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        // If even, the median is the average of the tops of both heaps
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
