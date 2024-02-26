#include <queue>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Create a queue of TreeNode pointers
        queue<TreeNode*> queue;
        // Enqueue the root nodes of both trees
        queue.push(p);
        queue.push(q);

        // Loop till the queue is not empty
        while (!queue.empty()) {
            // Dequeue the nodes for comparison
            TreeNode* first = queue.front();
            queue.pop();
            TreeNode* second = queue.front();
            queue.pop();

            // Check for equality
            if (first == nullptr && second == nullptr) {
                // If both nodes are null, continue to the next iteration
                continue;
            } else if (first == nullptr || second == nullptr || first->val != second->val) {
                // If only one of the nodes is null or their values are not equal, return false
                return false;
            }

            // Enqueue the left children of both nodes for further comparison
            queue.push(first->left);
            queue.push(second->left);
            // Enqueue the right children of both nodes for further comparison
            queue.push(first->right);
            queue.push(second->right);
        }
        // If the loop completes without returning false, return true
        return true;
    }
};
