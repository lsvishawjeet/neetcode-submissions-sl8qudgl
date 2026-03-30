class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // create set of nums for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longestCon = 0;

        for(int num : nums) {
            if(numSet.find(num-1) == numSet.end()) {
                int length = 1;
                while(numSet.find(num+length) != numSet.end()) {
                    length++;
                }
                longestCon = max(longestCon, length);
            }
        }
        return longestCon;
    }
};
