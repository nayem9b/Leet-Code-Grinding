class Solution
{
public:
    int row, col;
    bool insideGrid(int i, int j)
    {
        return (0 <= i) && (i < row) && (0 <= j) && (j < col);
    }
    vector<vector<int>> res;
    void fnc(vector<vector<int>> &land, int &r1, int &c1, int &r2, int &c2, int i, int j)
    {
        if (!insideGrid(i, j))
            return;
        if (land[i][j] == 1)
        {
            land[i][j] = 2;
            r1 = min(r1, i), c1 = min(c1, j), r2 = max(r2, i), c2 = max(c2, j);
            fnc(land, r1, c1, r2, c2, i + 1, j);
            fnc(land, r1, c1, r2, c2, i, j + 1);
            fnc(land, r1, c1, r2, c2, i - 1, j);
            fnc(land, r1, c1, r2, c2, i, j - 1);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        row = land.size();
        col = land[0].size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (land[i][j] == 1)
                {
                    int r1 = i, c1 = j, r2 = i, c2 = j;
                    fnc(land, r1, c1, r2, c2, i, j);
                    res.push_back({r1, c1, r2, c2});
                }
            }
        return res;
    }
};