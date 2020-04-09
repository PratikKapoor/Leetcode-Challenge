class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // To count the numnber of backspaces.
        int backspace_count = 0;
        string S_processed;
        
        // Iterating in reverse as using the # to erase elements is easier.
        for(int i=S.length()-1;i>=0;i--) {
            if(S[i]=='#') {
                backspace_count += 1;
            } else {
                // If previous elements were #, these ones would be erased.
                // If not, those elements are part of the final string.
                if(backspace_count>0) {
                    backspace_count -= 1;
                } else {
                    S_processed += S[i];
                }
            }
        }
        
        backspace_count = 0;
        string T_processed;
        
        // Doing the same as above for the second string.
        for(int i=T.length()-1;i>=0;i--) {
            if(T[i]=='#') {
                backspace_count += 1;
            } else {
                if(backspace_count>0) {
                    backspace_count -= 1;
                } else {
                    T_processed += T[i];
                }
            }
        }
        
        // Comparing as it is as reverse doesn't matter here.
        return S_processed == T_processed;
    }
};
