class Solution {
public:
    bool checkSquare(vector<vector<char>>& grid, int row, int col, char color) {
        return grid[row][col] == color && grid[row][col + 1] == color &&
               grid[row + 1][col] == color && grid[row + 1][col + 1] == color;
    }
    
    bool canChangeColor(vector<vector<char>>& grid, int row, int col) {
        char original_color = grid[row][col];
        grid[row][col] = (original_color == 'W') ? 'B' : 'W';
        
        for (int i = 0; i <= 1; ++i) {
            for (int j = 0; j <= 1; ++j) {
                if (checkSquare(grid, i, j, grid[i][j])) {
                    grid[row][col] = original_color;
                    return true;
                }
            }
        }
        
        grid[row][col] = original_color; 
        return false;
    }
    
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (canChangeColor(grid, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
