class Solution {
public:
    int maxArea(vector<int>& heights) {
        // use two pointer
        // start from i and j (last el)
        // move i or j based on which is small
        // calculate aread and update

        int i=0;
        int j=heights.size()-1;
        int maxArea = 0;

        while(i<j){
            int area = (j-i)*min(heights[i], heights[j]);
            maxArea = max(area, maxArea);
            if(heights[i]>heights[j]){
                j--;
            } else{
                i++;
            }
        }
        return maxArea;
    }
};
