class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
            Observation:
            if total gas < total cost return
            while(i<n){
                currentGas += gas[i] - cost[i];
                at this point if current gas becomes less than 0 then its not possible and i+1 is solution because solution does exist 
                we will make currentGas = 0 and ans = i+1
            }      
        */
        int totalGas = 0;
        int totalCost = 0;
        for(int i=0; i<gas.size(); i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalGas < totalCost) return -1;

        int currentGas = 0;
        int sol = 0;
        for(int i=0; i<cost.size(); i++){
            currentGas += (gas[i] - cost[i]);
            if(currentGas < 0){
                sol = i+1;
                currentGas = 0;
            }
        }
        return sol;
    }
};
