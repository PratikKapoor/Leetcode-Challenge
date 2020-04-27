class Solution {
public:
    // To check if a square with its top-left coordinates as (i, j) and bottom-right
    // coordinates as (x, y) is a valid square or not.
    bool isSquare(vector<vector<char>>& matrix, int row, int col, int i, int j, int x, int y) {
        for (int a=i; a<=x; a++) {
            for(int b=j; b<=y; b++) {
                if(matrix[a][b]=='0') {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) {
            return 0;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int max_square = 0;
        
        int flag = 0;
        
        // Iterate to each node and find largest square that node is top-left of.
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j]=='1') {
                    flag = 1;
                    
                    int x = i+1;
                    int y = j+1;
                    
                    while(x<row 
                          && y<col 
                          && isSquare(matrix, row, col, i, j, x, y)) {
                        x += 1;
                        y += 1;
                    }
                    
                    x -= 1;
                    y -= 1;
                    
                    // Greedily store maximum
                    max_square = max(x-i, max_square);
                }
            }
        }
        
        // If a "1" was seen, then calculate area.
        return flag==1 ? pow(max_square+1,2) : 0;
    }
};
