class Solution {
public:
    // Main function to check if the word exists on the board
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();  // Number of rows in the board
        int n = board[0].size();  // Number of columns in the board
        
        // Iterate through each cell of the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell matches the first character of the word
                if (board[i][j] == word[0]) {
                    // Call depth-first search (dfs) function to find the word starting from this cell
                    if (dfs(board, word, 0, i, j, m, n)) {
                        return true;  // If word is found, return true
                    }
                }
            }
        }
        
        return false;  // If word is not found in any cell, return false
    }
    
private:
    // Depth-first search function to find the word
    bool dfs(vector<vector<char>>& board, string word,
        int index, int i, int j, int m, int n) {
        
        // Base cases:
        // If current cell is out of board boundaries or does not match the word's character at given index
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }
        // If entire word is found
        if (index == word.size() - 1) {
            return true;
        }
        
        // Mark current cell as visited
        board[i][j] = '#';
        
        // Recursive calls to explore neighboring cells
        if (dfs(board, word, index + 1, i - 1, j, m, n)  // Up
            || dfs(board, word, index + 1, i + 1, j, m, n)  // Down
            || dfs(board, word, index + 1, i, j - 1, m, n)  // Left
            || dfs(board, word, index + 1, i, j + 1, m, n)) {  // Right
            return true;  // If word is found in any direction, return true
        }
        
        // Revert marking of current cell (backtrack)
        board[i][j] = word[index];
        return false;  // If word is not found in any direction, return false
    }
};
