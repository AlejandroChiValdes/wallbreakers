class Solution {
public:
    int rowSize;
    int colSize;
    int islandPerimeter(vector<vector<int>>& grid) {
        // start at index x = 0, y = 0
        // place all neighbors into queue
        // as you place neighbors into queue, increment your perimeter count accordingly (no change if current cell is water, +1 if neighbor is water and current cell is land)
        // continue until there are no unvisited cells left
        int total = 0;
        if (!grid.size())
            return total;
        rowSize = grid.size();
        colSize = grid[0].size();
        queue<vector<int>> neighbors;
        set<vector<int>> visited;
        neighbors.push(vector<int>{0,0});
        vector<vector<int>> offset { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        while (neighbors.size())
        {
            // take current cell, pop from queue
            vector<int> currentCell = neighbors.front();
            //cout << "currentCell: " << currentCell[0] << ", " << currentCell[1] << endl;
            neighbors.pop();
            // if current cell is visited or out of bounds, continue to the next cell
            if (visited.find(currentCell) != visited.end())
                continue;
            // else, if cell is legal, take all neighbors 
            for (int i = 0; i < offset.size(); ++i)
            {
                int newX = offset[i][0];
                int newY = offset[i][1];
                vector<int> neighbor {currentCell[0] + newX, currentCell[1] + newY};
                // add new neighbor to neighbor queue
                if (isLegal(neighbor))
                    neighbors.push(neighbor);
                // if our current cell is land, check your perimeter
                if (grid[currentCell[0]][currentCell[1]] == 1)
                {
                    if (!isLegal(neighbor) || grid[neighbor[0]][neighbor[1]] == 0)
                    {
                        ++total;
                        //cout << "neighbor: " << newX << ", " << newY << endl;
                        //cout << "Added to perimeter" << endl;
                    }
                        
                }
            }
            visited.insert(currentCell);
        }
        return total;
    }
    
    bool isLegal(vector<int>& currentCell)
    {
        int x = currentCell[0];
        int y = currentCell[1];
        return x < rowSize && x >= 0 && y < colSize && y >= 0;
    }
};