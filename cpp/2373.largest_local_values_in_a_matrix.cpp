#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>(grid.size() - 2));

        for (size_t i = 0; i < ans.size(); i++) {
            for (size_t j = 0; j < ans[i].size(); j++) {
                ans[i][j] = getMaxValueAcross3X3Grid(grid, i, j);
            }
        }
        return ans;
    }

private:
    int getMaxValueAcross3X3Grid(vector<vector<int>>& grid, int row, int col) {
        int maximum = 0;

        for (size_t i = row; i < row + 3; i++) {
            for (size_t j = col; j < col + 3; j++) {
                maximum = max(grid[i][j], maximum);
            }
        }
        return maximum;
    }
};


int main()
{
    
    return 0;
}