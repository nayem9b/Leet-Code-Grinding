#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> values;

            if (level % 2 == 1) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    values.push_back(node->val);
                    q.push(node);
                }
               
                reverse(values.begin(), values.end());
            }

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (level % 2 == 1) {
                    node->val = values[i];
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ++level;
        }

        return root;
    }
};
