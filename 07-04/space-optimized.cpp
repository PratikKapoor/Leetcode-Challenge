class Solution {
public:
    int countElements(vector<int>& arr) {
        // sort array.
        sort(arr.begin(), arr.end());
        
        int count = 0;
        int iter = 0;
        while(iter<arr.size()) {
            int duplicate_iter = iter;
            
            // Count number of duplicate elements.
            while(duplicate_iter+1<arr.size() && arr[duplicate_iter]==arr[duplicate_iter+1]) {
                duplicate_iter += 1;
            }
                        
            // Check if next larger element is bigger by 1. 
            // If yes, all duplicate items count towards the answer
            if(duplicate_iter+1<arr.size() && arr[duplicate_iter]==(arr[duplicate_iter+1] - 1)) {
                count += duplicate_iter - iter + 1;
            }
            
            iter = duplicate_iter + 1;
        }
        
        return count;
    }
};
