class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // [4, 11, 20, 23, 30]
        // hr = 5
        // [3,6,7,11] 
        // hr = 8
        // find min and max bananas
        int l = 1;
        int r = INT_MIN;
        int minBanana = INT_MAX;

        for(int banana:piles){
            r = max(banana, r);
        }

        while(l<=r){
            int mid = (l+r)/2;
            int totalHour = 0;
            for(int i=0; i<piles.size(); i++){
                int total = piles[i]/mid;
                if(piles[i]%mid != 0){
                    total++;
                }
                totalHour += total;
            }
            if(totalHour > h){
                l = mid+1;
            } else if(totalHour <= h){
                minBanana = min(minBanana, mid);
                r = mid-1;
            }
        }
        return minBanana;

    }
};
