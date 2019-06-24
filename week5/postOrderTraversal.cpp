/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        recursivePostOrder(root, result);
        return result;
    }
    
    // recursively populate the result vector with our results
    void recursivePostOrder(Node* n, vector<int>& result)
    {

        // cout << "value: " << n->val << "left: " << n->children[0] << " right: " << n->children[1] << endl;

        // base case: if you are a leaf node, add your value to the result
        if (!(n->children.size()))
        {
            result.push_back(n->val);
            return;
        }
        for (Node* child : n->children)
        {
            recursivePostOrder(child, result);
        }
        // add your own value to the result
        
        result.push_back(n->val);
    }
};