class MedianFinder {
public:
    // maintain two heaps, one is min heap and other is max heap
    priority_queue<int> maxHeap; // first half
    priority_queue<int, vector<int>, greater<int>> minHeap; // second half

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // min heap and max heap;
        // if max heap and min both empty push to max heap
        // if el > max heap push to min heap ,, also check if the size of min heap is greater than max heap then push the top most element to max heap
        // if ele < min heap
        minHeap.push(num);
        if(maxHeap.empty() || maxHeap.size() < minHeap.size()){
            int secondHalfSmallest = minHeap.top();
            minHeap.pop();
            maxHeap.push(secondHalfSmallest);
        }
            if(minHeap.top() < maxHeap.top()){
                int topLeft = maxHeap.top();
                int topRight = minHeap.top();
                minHeap.pop();
                maxHeap.pop();
                minHeap.push(topLeft);
                maxHeap.push(topRight);
            }
    }
    
    double findMedian() {
        if((maxHeap.size() + minHeap.size()) % 2 != 0){
            return maxHeap.top();
        }
        return double((double)(maxHeap.top()) + (double)minHeap.top())/2;
    }
};
