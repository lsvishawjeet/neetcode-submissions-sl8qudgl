class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> sol;
        deque<int> dq; 

        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && nums[dq.front()] <= nums[i]){
                while(!dq.empty() && nums[dq.front()] <= nums[i]){
                    dq.pop_front();
                }
                dq.push_front(i);
            }
            else if(!dq.empty() && nums[dq.back()] <= nums[i]){
                while(!dq.empty() && nums[dq.back()] <= nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            } else{
                dq.push_back(i);
            }
            if(i>=k-1){
                while(!dq.empty() && dq.front() <= i-k){
                    dq.pop_front();
                }
                sol.push_back(nums[dq.front()]);
            }
        }

        return sol;
    }
};
