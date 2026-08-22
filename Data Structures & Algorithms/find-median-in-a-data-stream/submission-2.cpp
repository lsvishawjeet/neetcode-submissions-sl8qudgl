class MedianFinder {
public:
    priority_queue<int> pq1; // max heap store larger on top
    priority_queue<int, vector<int>, greater<int>> pq2; // min heap store small on top
    MedianFinder() {
        /*
            Use two queues
            min and max heaps
            store the element to heap by comparing the top element
            then make them equal in size
        */
    }
    
    void addNum(int num) {
        if(pq1.empty() || pq1.top() > num){
            pq1.push(num);
        } else{
            pq2.push(num);
        }
        // now balance the both
        if(pq1.size() > pq2.size()+1){
            pq2.push(pq1.top());
            pq1.pop();
        } else if( pq1.size() < pq2.size() ){
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        if(pq1.size() == pq2.size()){
            return (pq1.top()+pq2.top())/2.0;
        } else{
            return pq1.top();
        }
    }
};
