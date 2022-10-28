  static int maxDepth(const Node* root) {
        if (!root) return 0;
        int max_child = 0;
        for (const Node* child : root->children) {
            max_child = max(max_child, maxDepth(child));
        }
        return 1 + max_child;
    }
