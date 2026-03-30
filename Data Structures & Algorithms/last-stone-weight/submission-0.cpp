class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // use two pointer
        int i = stones.size()-2;
        int j = stones.size()-1;
        //[2,2,3,4,6]
        sort(stones.begin(), stones.end());
        while(i>=0 && j>=0){
            if(stones[i]==stones[j]){
                i = i-2;
                j = j-2;
            }
            else if(stones[i] < stones[j]){
                stones[i] = stones[j] - stones[i];
                j = j-1;
                i = i-1;
            }
            sort(stones.begin(), stones.end());
        }
        if(j>=0){
            return stones[j];
        }
        return 0;
    }
};
