class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
	//Runtime: 24 ms
	//Memory Usage: 12.5 MB
        // make a hashmap for rows
        map<int, set<int>> rows;
        // make a hashmap for columns
        map<int, set<int>> cols;
        // make a hasmap for blocks
        map<int, set<int>> blocks;
        
        int H = board.size();
        int W = board[0].size();
        for (int row = 0; row < H; ++row)
        {
            for (int col = 0; col < W; ++col)
            {
                if (board[row][col] == '.') continue;
                if (rows[row].find(board[row][col]) != rows[row].end())
                    return false;
                rows[row].insert(board[row][col]);
                
                if (cols[col].find(board[row][col]) != cols[col].end())
                    return false;
                cols[col].insert(board[row][col]);
                
                pair<set<int>::iterator, bool> res;
                if (row < 3 )
                {
                    if (col < 3)
                        res = blocks[0].insert(board[row][col]);
                    else if (col < 6)
                        res = blocks[1].insert(board[row][col]);
                    else
                        res = blocks[2].insert(board[row][col]);
                }
                else if (row < 6 )
                {
                    if (col < 3)
                        res = blocks[3].insert(board[row][col]);
                    else if (col < 6)
                        res = blocks[4].insert(board[row][col]);
                    else
                        res = blocks[5].insert(board[row][col]);
                }
                else if (row < 9 )
                {
                    if (col < 3)
                        res = blocks[6].insert(board[row][col]);
                    else if (col < 6)
                        res = blocks[7].insert(board[row][col]);
                    else
                        res = blocks[8].insert(board[row][col]);
                }
                if (!res.second)
                    return false;
            }
        }
        return true;
    
    }
};