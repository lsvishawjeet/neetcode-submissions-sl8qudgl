class Solution {
public:
    bool canJump(vector<int>& nums) {
        // follow the greedy apporcha
        /*
            from can jump nums[i] steps
            traverse all nums[i] steps and find the largest one or the largest index it can visit
            its i+nums[i]
        */
        int goal = nums.size()-1;
        // traverse from last and check if i can reach i from this
        for(int i=nums.size()-2; i>=0; i--){
            if(i+nums[i] >= goal){
                goal = i;
            }
        }
        return goal==0;

    }
};
