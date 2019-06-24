class Solution {
public:
    int numRows;
    int numCols;
    vector<vector<char>> b;
    string w;
    bool exist(vector<vector<char>>& board, string word) {
        // int currentChar keeps track of the current character of the word you're trying to match
        // set<int> visited keeps track of the grid cells that you've already used for this iteration of the word. Clears once this iteration of the word fails and you move on
        // Strategy: go through each cell in the board, check if the current cell's character matches word[currentChar]. If not, move onto the next cell, clearing any visited cells you've visited and resetting the currentChar back to 0. If it does match, perform a breadth first search on all valid adjacent cells and repeat the above process for each of the neighbors.
        numRows = board.size();
        numCols = board[0].size();
        int currentChar = 0;
        set<vector<int>> visited;
        b = board;
        w = word;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                if (wordExists(i, j, currentChar, visited))
                    return true;
                visited = set<vector<int>>();
                currentChar = 0;
            }
        }
        return false;
    }
    
    bool wordExists(int x, int y, int currentChar, set<vector<int>>& visited)
    {
        // check if current char matches the word's current char && is not in the current working set. if both pass, add your character to the current set and return the result of recursively calling wordExists on all of your neighbors
        if (!isLegal(x, y))
            return false;
        else if (visited.find(vector<int>{x, y}) != visited.end())
        {
            return false;
        }
            

        if (b[x][y] != w[currentChar])
        {  
            return false;
        }
            
        else if (b[x][y] == w[currentChar] && currentChar == w.size() - 1)
            return true;
        vector<vector<int>> offset { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        // if (b[x][y] == w[currentChar]) and the current character is not the last one in the current word
        visited.insert(vector{x, y});
        for (int i = 0; i < offset.size(); ++i)
        {
            int newX = x + offset[i][0];
            int newY = y + offset[i][1];
            if (wordExists(newX, newY, currentChar + 1, visited))
                return true;
        }
        visited.erase(visited.find(vector<int>{x, y}));
        return false;
    }
    
    bool isLegal(int x, int y)
    {
        return x >= 0 && x < numRows && y >= 0 && y < numCols;
    }
};