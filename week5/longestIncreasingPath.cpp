class Solution {
public:
    int numRows;
    int numCols;
    vector<vector<int>> offset { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        /*
        from every index, perform a recursive breadth first search, finding which neighbors are larger than you and recursively calling the BFS function on those neighbors
        
        Data structures needed: 
        set<int> visited - keeps track of which cells have been used for the current path
        int max - keeps track of the longest increasing path we've encountered so far
        
        algorithm
        for each pair (i, j) in the matrix with i rows and j columns:
        perform calcLongestPath(i, j)
        
        calcLongestPath - [out] the length of the longest increasing path starting at this cell
        base case: if index is out of bounds, return 0
        base case: if index has no neighbors
        */
        int total = 0;
        if (!matrix.size())
            return total;
        numRows = matrix.size();
        numCols = matrix[0].size();
        set<pair<int, int>> visited;
        vector<vector<int>> memo;
        for (int i = 0; i < numRows; ++i)
        {
            memo.push_back(vector<int>(numCols, -1));
        }
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                int result = calcLongestPath(i, j, matrix, visited, memo);
                total = total > result ? total : result;
            }
        }
        
        return total;
    }
    
    int calcLongestPath(int x, int y, vector<vector<int>>& matrix, set<pair<int, int>>& visited, vector<vector<int>>& memo)
    {
        // iterate through all neighbors that:
        // 1. have not been visited
        // 2. have values greater than the current cell's value
        // take the max value of recursively calling calcLongestPath on these neighbors and add return 1 + max
        if (memo[x][y] != -1)
            return memo[x][y];
        int max = 0;
        pair<int, int> curPair (x, y);
        // add current item to visited set so that neighbors in this sequence do not double-count the current item
        visited.insert(curPair);
        for (int i = 0; i < 4; ++i)
        {
            int newX = x + offset[i][0];
            int newY = y + offset[i][1];
            if (isLegal(newX, newY) && visited.find(pair<int, int>(newX, newY)) == visited.end() && matrix[newX][newY] > matrix[x][y])
            {
                int result = calcLongestPath(newX, newY, matrix, visited, memo);
                max = result > max ? result : max;
            }
        }
        visited.erase(curPair);
        memo[x][y] = 1 + max;
        return memo[x][y];
    }
    
    bool isLegal(int x, int y)
    {
        return x >= 0 && x < numRows && y >= 0 && y < numCols;
    }
};