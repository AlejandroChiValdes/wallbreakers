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
    int findBottomLeftValue(TreeNode* root) {
        // if root is a leaf node, check if current depth has already been reached. if not, add your value to the map. if so, exit from the function
        map<int, int> result;
        int index = populateLeafMap(root, result, 0);
        return result[index];
    }
    
    // populate map if current node is a leaf, return your depth if a leaf
    int populateLeafMap(TreeNode* root, map<int,int>& result, int depth)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
        {
            if (result.find(depth) == result.end())
            {
                //cout << "current val: " << root->val << "and depth: " << depth << endl;
                result[depth] = root->val;
            }
            return depth;
        }
        int leftMax = populateLeafMap(root->left, result, depth + 1);
        int rightMax = populateLeafMap(root->right, result, depth + 1);
        return max(leftMax, rightMax);
    }
};