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
    int sumOfLeftLeaves(TreeNode* root) {
        return recursiveSumOfLeftLeaves(root, false);
    }
    
    int recursiveSumOfLeftLeaves(TreeNode* t, bool isLeft)
    {
        if (t == NULL)
            return 0;
        if (t->left == NULL && t->right == NULL)
        {
            if (isLeft)
            {
                return t->val;
            }
        }
        int result = 0;
        if (t->left != NULL)
        {
            result += recursiveSumOfLeftLeaves(t->left, true);
        }
        if (t->right != NULL)
        {
            result += recursiveSumOfLeftLeaves(t->right, false);
        }
        return result;
    }
};