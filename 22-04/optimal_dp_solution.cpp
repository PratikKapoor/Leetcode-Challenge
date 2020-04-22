class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> cumulative_sum;
        // Initial sum is 0.
        cumulative_sum[0] = 1;
        int sum = 0;
        
        int result = 0;
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            
            // If sum - k has already been seen, then the array between then and now
            // has it's sum equal to k.
            if(cumulative_sum.find(sum - k) != cumulative_sum.end()) {
                result += cumulative_sum[sum-k];
            }
            
            // Increase freq of 'sum'.
            cumulative_sum[sum] = cumulative_sum[sum] + 1;
        }
        
        return result;
    }
};
