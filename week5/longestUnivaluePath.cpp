/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        // rightMatchingPath + leftMatchingPath
        // rightNonMatchingPath
        // leftNonMatchingPath
        if (root == NULL)
            return 0;
        int leftMatchingPath = singlePath(root->left, root->val);
        int rightMatchingPath = singlePath(root->right, root->val);
        return max( max( leftMatchingPath + rightMatchingPath, longestUnivaluePath(root->right)),
                longestUnivaluePath(root->left));
    }
    
    int singlePath(TreeNode* t, int val)
    {
        if (t == NULL)
            return 0;
        if (t->val != val)
            return 0;
        return max(1 + singlePath(t->left, val), 1 + singlePath(t->right, val));
    }
};