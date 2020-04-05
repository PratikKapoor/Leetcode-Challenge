class Solution {
public:
    bool isHappy(int n) {
        
        // Return true if the number is 1.
        if(n==1) {
            return true;
        }
        
        int sum;
        int temp_number = n;
        int num = n;
        
        // Creating a set to store already seen values. 
        // Will be useful to detect if we are in a cycle.
        set<int> seen;
        
        do {
            sum = 0;
            
            // Find sum of squares of digits.
            while(temp_number>0) {
                sum += pow(temp_number%10, 2);
                temp_number = temp_number/10;
            }
                      
            // Check if already seen using set.
            auto pos = seen.find(sum);
            
            if(pos!=seen.end()) {
                return false;
            }
            
            seen.insert(sum);

            num = sum;
            temp_number = sum;
        } while (sum!=1);
        
        return true;
    }
};
