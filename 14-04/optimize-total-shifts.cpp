class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        if(s.length() <= 1) {
            return s;
        }
        
        // Calculate cumulative amount of shift and direction of final shift.
        int shift_amount = 0;
        for(int i=0;i<shift.size();i++) {
            int direction = shift[i][0];
            int amount = shift[i][1];
            
            if(direction == 1) {
                shift_amount = shift_amount + amount;
            } else {
                shift_amount = shift_amount - amount;
            }
        }
        
        int direction = shift_amount<0 ? 1 : 0;
        // If shift amount is larger than array itself, we can reduce it to the % of the length.
        shift_amount = abs(shift_amount) % s.length();
        
        // If resultant shift is leftwards, convert it to equivalent right shift.
        if (direction) {
            shift_amount = s.length() - shift_amount;
        }
        
        int start_pos = s.length() - shift_amount;
        string result;

        for(int i=start_pos;i<s.length();i++) {
            result += s[i];
        }
        
        for(int i=0;i<start_pos;i++) {
            result += s[i];
        }
        
        return result;
    }
};
