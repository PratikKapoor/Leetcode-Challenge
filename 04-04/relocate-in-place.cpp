class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // To count non-zero elements in array.
        int nonzero = 0;
        
        // Return if array contains a single element.
        if(nums.size()==1) {
            return;
        }
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0) {
                nonzero += 1;
                
                // Finding first non-zero position empty in the array.
                int j = i-1;
                while(j>=0 && nums[j]==0) {
                    j-=1;
                }
                
                // Relocating element to the first position with '0'.
                nums[j+1] = nums[i];
                
                // Set relocated element to 0.
                if (j+1 != i) {
                    nums[i]=0;
                }
            }
        }
                
        // Fill rest of the positions with 0.
        if (nonzero>0) {
            for(int i=nonzero;i<nums.size();i++) {
                nums[i]=0;
            }
        }
    }
};
