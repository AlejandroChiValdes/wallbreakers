class Solution {
public:
	/* runtime 80ms storage 38mb */
    int W;
    int H;
    int totalItems;
    void solve(vector<vector<char>>& board) {
        if (!board.size()) return;
        vector<int> parents;
        W = board[0].size();
        H = board.size();
        totalItems = W * H;
        for (int i = 0; i < totalItems; ++i)
        {
            parents.push_back(i);
        }
        
        for (int row = 0; row < H; ++row)
        {
            for (int col = 0; col < W; ++col)
            {
                unionNeighbors(parents, board, col, row);
            }
        }
        set<int> borderParents;
        for (int row = 0; row < H; ++row)
        {
            if (row == 0 || row == H - 1)
            {
                for (int col = 0; col < W; ++col)
                {
                    borderParents.insert(find(parents, col + row*W));
                }
            }
            else
            {
                borderParents.insert(find(parents, row*W));
                borderParents.insert(find(parents, W - 1 + row*W));
            }
        }
        for (int row = 1; row < H - 1; ++row)
        {
            for (int col = 1; col < W - 1; ++col)
            {
                if (board[row][col] == 'O' && borderParents.find(find(parents, col + row*W)) == borderParents.end())
                {
                    board[row][col] = 'X';
                }
            }
        }
    }
    
    void unionNeighbors(vector<int>& parents, vector<vector<char>>& board, 
                       int x, int y)
    {
        vector<vector<int>> coords = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; ++i)
        {
            int xShift = coords[i][0] + x;
            int yShift = coords[i][1] + y;
            if (isLegal(xShift, yShift) && board[y][x] == 'O' &&
                board[yShift][xShift] == 'O')
            {

                // update the union-find list such that the current cell's 
                // neighbor shares the same parent with the current cell
                join(parents, xShift + yShift*W, x + y*W);
            }
        }
    }
    int find(vector<int>& parents, int f)
    {
        if (parents[f] == f)
            return f;
        return find(parents, parents[f]);
    }
    
    void join(vector<int>& parents, int lhs, int rhs)
    {
        // change the parents of lhs to be parent of rhs
        parents[find(parents, lhs)] = find(parents, rhs);
    }
    
    bool isLegal(int x, int y)
    {
        return x >= 0 && y >= 0 && x < W && y < H;
    }
};