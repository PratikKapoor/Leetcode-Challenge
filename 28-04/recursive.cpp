class Solution {
public:
    int isSquare(vector<vector<char>>& matrix, int i, int j) {
        if(matrix[i][j]=='0') {
            return 0;
        }
        
        return min(min(isSquare(matrix, i+1, j), isSquare(matrix, i, j+1)), isSquare(matrix, i+1, j+1)) + 1;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) {
            return 0;
        }
        
        // Add padding to avoid checking for boundary in helper()
        for(auto &v : matrix) v.push_back('0');
        matrix.push_back(vector<char>(matrix[0].size(), '0'));
        
        int max_square = 0;
        
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                max_square = max(max_square, isSquare(matrix, i, j));
            }
        }
        return pow(max_square, 2);
    }
};
