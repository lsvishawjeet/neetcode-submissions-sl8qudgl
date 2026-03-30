class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        /*
            Only choose those arrays which contains the target array elements
        */
        vector<vector<int>> tripletsThatMakesSense;
        bool m = false;
        bool n = false;
        bool o = false;
        for(vector<int> &triplet : triplets){
            int i = triplet[0];
            int j = triplet[1];
            int k = triplet[2];
            if(i <= target[0] && j<=target[1] && k<=target[2]){
                if(i == target[0]) m = true;
                if(j == target[1]) n = true;
                if(k == target[2]) o = true;
                tripletsThatMakesSense.push_back(triplet);
            }
        }
        if(tripletsThatMakesSense.size()==0) return false;
        return m && n && o;
    }
};
