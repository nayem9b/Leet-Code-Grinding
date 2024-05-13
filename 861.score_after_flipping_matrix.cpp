class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int res = (1 << (COLS - 1)) * ROWS;
        
        for (int r = 0; r < ROWS; ++r) {
            if (grid[r][0] == 0) {
                for (int c = 0; c < COLS; ++c) {
                    grid[r][c] = 1 - grid[r][c];
                }
            }
        }
        
        for (int c = 1; c < COLS; ++c) {
            int count1 = 0;
            for (int r = 0; r < ROWS; ++r) {
                count1 += grid[r][c];
            }
            if (count1 > (ROWS / 2)) {
                res += count1 * (1 << (COLS - c - 1));
            } else {
                res += (ROWS - count1) * (1 << (COLS - c - 1));
            }
        }
        
        return res;
    }
};
