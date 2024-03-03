class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Map to store the depth of each node
        unordered_map<TreeNode*, int> map;
        // Stack for iterative traversal
        stack<TreeNode*> stk;
        // Variable to store the diameter of the binary tree
        int diameter = 0;

        // If the root is not null, push it onto the stack
        if (root != nullptr)
            stk.push(root);

        // Iterative post-order traversal
        while (!stk.empty()) {
            TreeNode* node = stk.top();

            // Fill up stack to perform post-order traversal
            if (node->left != nullptr && map.find(node->left) == map.end()) {
                stk.push(node->left);
            } else if (node->right != nullptr && map.find(node->right) == map.end()) {
                stk.push(node->right);
            } else {
                // Process the root, once left and right sub-tree have been processed
                stk.pop();
                // Fetch depths of left and right children from the map
                int leftDepth = map[node->left];
                int rightDepth = map[node->right];

                // Put the max depth at a node in the map
                map[node] = 1 + max(leftDepth, rightDepth);

                // Update the max diameter found so far
                diameter = max(diameter, leftDepth + rightDepth);
            }
        }
        // Return the calculated diameter of the binary tree
        return diameter;
    }
};