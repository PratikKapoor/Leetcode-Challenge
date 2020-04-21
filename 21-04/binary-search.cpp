/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int rows = dimensions[0];
        int cols = dimensions[1];
        
        // Add all rows to list of eligible rows.
        set<int> eligible;
        for(int i=0;i<rows;i++) {
            eligible.insert(i);
        }
        
        int result = -1;
        
        int start = 0;
        int high = cols-1;
        int mid = start + (high-start)/2;
        
        // Binary search to find leftmost 1.
        while(start<=high) {
            // Check if any row contains a 1.
            int contains_one = 0;
            for(int i=0;i<rows;i++) {
                if(eligible.count(i)!=0 && binaryMatrix.get(i, mid)==1) {
                    contains_one = 1;
                    break;
                }
            }
            
            // If a 1 is seen.
            if(contains_one == 1) {
                result = result == -1 ? mid : min(result, mid);
                
                // Remove all rows from eligible list which do not have a 1 at the mid position.
                // Since 1 has been seen, we can safely discard these rows.
                for(int i=0;i<rows;i++) {
                    if(eligible.count(i)!=0 && binaryMatrix.get(i, mid)==0) {
                        eligible.erase(i);
                    }
                }
                
                high = mid-1;
                mid = start + (high-start)/2;
            } else {
                start = mid + 1;
                mid = start + (high-start)/2;
            }
        }
        
        return result;
    }
};
