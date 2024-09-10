#include <queue>

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // Use a queue to perform level-order traversal (BFS)
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr; // To keep track of the previous node at the same level

            for (int i = 0; i < size; ++i) {
                Node* curr = q.front();
                q.pop();

                // Connect the previous node's next to the current node
                if (prev) {
                    prev->next = curr;
                }

                prev = curr; // Update prev to the current node

                // Push the left and right children to the queue
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // Set the last node's next pointer to null (end of level)
            if (prev) {
                prev->next = nullptr;
            }
        }

        return root;
    }
};
