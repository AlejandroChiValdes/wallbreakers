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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        vector<int> seq2;
        getLeafValueSequence(root1, seq1);
        getLeafValueSequence(root2, seq2);
        
        // check the lengths of each sequence, if they're different, then return false
        if (seq1.size() != seq2.size())
            return false;
        
        // once we know that sequence lengths are ==, then iterate through each index and check for equality
        for (int i = 0; i < seq1.size(); ++i)
        {
            //cout << "seq1[i]: " << seq1[i] << ", seq2[i]: " << seq2[i] << endl;
            if (seq1[i] != seq2[i])
                return false;
        }
        return true;
    }
    
    void getLeafValueSequence(TreeNode* t, vector<int>& sequence)
    {
        if (t->left == NULL && t->right == NULL)
        {
            sequence.push_back(t->val);
            return;
        }
        if (t->left != NULL)
        {
            getLeafValueSequence(t->left, sequence);
        }
        if (t->right != NULL)
        {
            getLeafValueSequence(t->right, sequence);
        }
    }
};