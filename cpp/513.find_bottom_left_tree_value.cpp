class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return -1; // Assuming -1 as default return if tree is empty

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;

        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }
        
        return node->val;
    }
};