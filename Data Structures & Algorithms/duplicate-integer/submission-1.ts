class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums: number[]): boolean {
        let mp = new Map<number, number>();
        for(const num of nums){
            let newCount = (mp.get(num) || 0) + 1;
            mp.set(num, newCount)
            if(newCount > 1){
                return true;
            }
        }
        return false;
    }
}
