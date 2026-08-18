class Solution {
public:
    int maxArea(vector<int>& heights) {
        // mvoe the smaller 
        int l = 0 ;
        int r = heights.size()-1;
        int maxA = 0;

        while(l<r){
            int currA = min(heights[l],heights[r]) * (r-l);
            maxA = max(maxA, currA);
            if(heights[l] < heights[r]){
                l++;
            } else{
                r--;
            }
        }
        return maxA;
    }
};
