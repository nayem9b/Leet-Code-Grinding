class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if (numRows == 0) return result;

        vector<int> firstRow = {1};
        result.push_back(firstRow);

        if (numRows == 1) return result;

        for (int i = 1; i < numRows; ++i) {
            vector<int> prevRow = result[i - 1];

            // Start the next row
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j < i - 1; ++j) {
                row.push_back(prevRow[j] + prevRow[j + 1]);
            }
            row.push_back(1);

            // Add this new row to final result
            result.push_back(row);
        }

        return result;
    }
};
