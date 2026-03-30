class Solution {
public:
    int climb(vector<int>& cost, int currStair, vector<int>& cache){
        if(currStair >= cost.size()){
            return 0;
        }
        if(cache[currStair] != -1){
            return cache[currStair];
        }
        return cache[currStair] = cost[currStair] + min(climb(cost, currStair+1, cache), climb(cost, currStair+2, cache));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size(), -1);
        return min(climb(cost, 0, cache), climb(cost, 1, cache));
    }
};
