class Solution {
public:
    // 24ms runtime with 11MB of storage
    int findCircleNum(vector<vector<int>>& M) {
        int numRows = M.size();
        int rowSize = M[0].size();
        // this array will represent the relationship circles
        vector<int> parents;
        for (int i = 0; i < numRows; ++i)
        {
            // set all indices' parents to themselves in preparation for
            // unioning
            parents.push_back(i);
        }
        // build the relationship circles
        for (int row = 0; row < numRows; ++row)
        {
            for (int col = 0; col < rowSize; ++col)
            {
                // any relationships to the right of the diagonal are
                // redundant
                if (col >= row) break;
                if (M[row][col])
                    join(parents, col, row);
            }
        }
        int uniqueCt(0);
        map<int,int> uniqueParents;
        for (int i = 0; i < numRows; ++i)
        {
            int currentParent = find(parents, i);
            if (uniqueParents.find(currentParent) == uniqueParents.end())
            {
                uniqueParents.insert(pair<int,int>(currentParent,0));
                ++uniqueCt;
            }
                
        }
        return uniqueCt;
    }
    
    // find the original 'friend' for the current person
    int find(const vector<int>& parents, int i)
    {
        if (parents[i] == i) return i;
        else return find(parents, parents[i]);
    }
    
    // i and all of its relationships now belong to j's relationship circle
    void join(vector<int>& parents, int i, int j)
    {
        parents[find(parents, i)] = parents[find(parents, j)];
    }
    
    
};