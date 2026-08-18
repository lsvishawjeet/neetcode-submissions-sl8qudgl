class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int &n:nums){
            st.insert(n);
        }
        int maxLen = 0;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            if(st.contains(num-1)){
                continue;
            }
            while(true){
                if(!st.contains(num)){
                    break;
                }
                st.erase(num);
                num++;
            }
            maxLen = max(maxLen, num-nums[i]);
        }
        return maxLen;
    }
};
