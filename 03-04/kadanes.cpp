class Solution {
public:
    // Pretty straightforward. Solved using the Kadane's algorithm.
    int maxSubArray(vector<int>& nums) {
        int global_sum = INT_MIN;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            
            // Greedily storing maximum sum so far.
            if(sum>global_sum) {
                global_sum = sum;
            }
            
            // Reset if sum so far is less than 0.
            if (sum<0) {
                sum = 0;
            }
        }
        
        return global_sum;
    }
};
