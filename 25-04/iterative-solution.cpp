class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Check highest reachable node using the 0th index.
        int currentHighestReachable = nums.at(0);
        
        if(currentHighestReachable >= nums.size()-1) {
                return true;
        }
        
        for(int i=1; i<nums.size()-1; i++) {
            if (i <= currentHighestReachable) {
                // At each instance, we recalculate the current highest reachable node.
                currentHighestReachable = max(currentHighestReachable, i+nums.at(i));
            }
            
            // If at any point, the highest reachable node >= the last index, we know
            // it is possible to reach the last index.
            if(currentHighestReachable >= nums.size()-1) {
                return true;
            }
        }
        
        return false;
    }
};
