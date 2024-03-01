var isEvenOddTree = function(root) {
    // Check if root is null
    if (!root) return true;

    // Initialize queue and level
    let queue = [root];
    let level = 0;

    // Traverse the tree using BFS
    while (queue.length > 0) {
        let size = queue.length;
        // Set prevVal based on level
        let prevVal = (level % 2 === 0) ? Number.MIN_SAFE_INTEGER : Number.MAX_SAFE_INTEGER;

        // Process nodes at current level
        for (let i = 0; i < size; i++) {
            let node = queue.shift();

            // Check if node value violates even-odd pattern
            if ((level % 2 === 0 && (node.val % 2 === 0 || node.val <= prevVal)) ||
                (level % 2 === 1 && (node.val % 2 === 1 || node.val >= prevVal))) {
                return false;
            }

            prevVal = node.val;

            // Enqueue child nodes
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }

        level++; // Move to next level
    }

    return true; // Tree follows even-odd pattern
};
