class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_var = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            xor_var = xor_var ^ nums[i];
        }
        
        return xor_var;
    }
};
