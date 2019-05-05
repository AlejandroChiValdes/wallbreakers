class Solution {
public:
    int numRows;
    int rowSize;
    int numIslands(vector<vector<char>>& grid) {
        // 20ms runtime with 11.7MB of storage
        if (!grid.size()) return 0;
        vector<int> parents;
        numRows = grid.size();
        rowSize = grid[0].size();
        int totalItems = numRows * rowSize;
        for (int i = 0; i < totalItems; ++i)
        {
            // don't index vector because its size hasn't been specified
            parents.push_back(i);
        }
        
        for (int row = 0; row < numRows; ++row)
        {
            for (int col = 0; col < rowSize; ++col)
            {
                if (grid[row][col] == '1')
                {
                    buildIslands(parents, grid, col, row);
                }
            }
        }
        int uniqueCt(0);
        map<int, int> uniqueParents;
        for (int row = 0; row < numRows; ++row)
        {
            for (int col = 0; col < rowSize; ++col)
            {
                if (grid[row][col] == '1' && uniqueParents.find(find(parents, col + row*rowSize)) == uniqueParents.end())
                {
                    ++uniqueCt;
                    uniqueParents.insert(pair<int,int>(col + row*rowSize, 0));
                }
            }
        }
        
        return uniqueCt;;
    }
    
    void buildIslands(vector<int>& parents, vector<vector<char>>& grid, int x, int y)
    {
        if (grid[y][x] == '0') return;
        int coords[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        // check all neighbors & attempt to convert their parents to your parents
        for (int i = 0; i < 4; ++i)
        {
            // skip out of bounds coordinates
            int xOffset = coords[i][0];
            int yOffset = coords[i][1];

            if (!coordsAreLegal(x + xOffset, y + yOffset, grid)) continue;
            // if both you and your neighbor belong to the same parent, continue
            if (find(parents, x + xOffset + (y + yOffset)*rowSize) == find(parents, x + y*rowSize))
                continue;
            else
            {
                join(parents, x + xOffset + (y + yOffset)*rowSize, x + y*rowSize);
                buildIslands(parents, grid, x + xOffset, y + yOffset);
            }
        }
        return;
    }
    
    int find(const vector<int>& parents, int item)
    {
        if (parents[item] == item) return item;
        return find(parents, parents[item]);
    }
    
    void join(vector<int>& parents, int lhs, int rhs)
    {
        parents[find(parents, lhs)] = find(parents, rhs);
    }
    
    bool coordsAreLegal(int x, int y, vector<vector<char>>& grid)
    {
        return x >= 0 && y >= 0 && x < rowSize && y < numRows && grid[y][x] != '0';
    }
};