class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // algorithm:
        //  -> create a priority queue (heap)
        //  -> inseart each element in the queue
        //  -> while ( the top element's index is less than the range ) -> pop
        //  -> inseart element to the soluition vector
        vector<int> sol;
        priority_queue<pair<int, int>> heap; // {element, index}

        for(int i=0; i<nums.size(); i++){
            heap.push({nums[i], i});
            if(i >= k-1){
                while(heap.top().second <= i-k){
                    heap.pop();
                }
                sol.push_back(heap.top().first);
            }
        }

        return sol;
    }
};
