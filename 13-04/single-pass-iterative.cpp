class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> position;
        int sum = 0;
        map<int, int>::iterator iter;
        int length = 0;
        
        position[0] = -1;
        
        // At each point in the array, check if we have seen this sum earlier.
        // If the same sum has been seen, it means the number of 0's and 1's were equal
        // between that point and now.
        for (int i=0;i<nums.size();i++) {
            if(nums[i]==1) {
                sum += 1;
            } else {
                sum -= 1;
            }
            
            iter = position.find(sum);
            
            if(iter!=position.end()) {
                length = max(length,i - position[sum]);
            } else {
                position[sum] = i;
            }
        }
        
        return length;
    }
};
