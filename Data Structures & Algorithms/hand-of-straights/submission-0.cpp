class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        map<int, int> freq;
        for(int card : hand){
            freq[card]++;
        }
        while(!freq.empty()){
            int startCard = freq.begin()->first;
            for(int i=0; i<groupSize; i++){
                int nextCard = i + startCard;
                if(freq.find(nextCard) == freq.end()) return false;
                freq[nextCard]--;
                if(freq[nextCard] == 0) freq.erase(nextCard);
            }
        }
        return true;
    }
};
