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
    int diameterOfBinaryTree(TreeNode* root) {
        return maxDiameter(root);
    }
    
    int maxDiameter(TreeNode* t)
    {
        if (t == NULL)
            return 0;
        int leftHalf = halfDiameter(t->left);
        int rightHalf = halfDiameter(t->right);
        return max(leftHalf + rightHalf, max(maxDiameter(t->left), maxDiameter(t->right)));
    }
    
    int halfDiameter(TreeNode* t)
    {
        if (t == NULL)
            return 0;
        return max(1 + halfDiameter(t->left), 1 + halfDiameter(t->right));
    }
};