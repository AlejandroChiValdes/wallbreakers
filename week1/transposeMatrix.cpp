class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        //28ms runtime with 11.5mb storage
		// spent an hour on the commented out solution below, then switched gears
		// toward the solution directly below
        int sz = A.size();
        int rowSize = A[0].size();
        vector<vector<int>> newA;
        for (int i = 0; i < rowSize; ++i)
        {
            newA.push_back(vector<int>(sz, 0));
        }
        for (int row = 0; row < sz; ++row)
        {
            for (int col = 0; col < rowSize; ++col)
            {
                if (col != row)
                {
                    newA[col][row] = A[row][col];
                }
                else
                {
                    newA[row][col] = A[row][col];
                }
            }
        }
        return newA;
        // not enough rows to perform swap as-is, must add rows to accomodate
//         if (rowSize > sz)
//         {
//             for (int i = 0; i < rowSize - sz; ++i)
//             {
//                 A.push_back(vector<int>{});
//             }
//         }
//         for (int row = 0; row < A[row].size(); ++row)
//         {
//             //if (row >= rowSize) break;
//             int numDeleted = 0;
//             for (int cell = 0; cell < rowSize; ++cell)
//             {
//                 // for a tall matrix
//                 if (sz > rowSize && row >= rowSize && cell != row)
//                 {
//                         //cout << "x" << endl;
//                         A[cell].push_back(A[row][cell - numDeleted]);
//                         //cout << "y" << endl;
//                         A[row].erase(A[row].begin() + cell - numDeleted++);
//                         // check if vector is empty. if so, delete it.
//                 }
//                 // for a wide matrix
//                 else if (rowSize > sz && cell >= sz && cell != row)
//                 {                  
//                         A[cell].push_back(A[row][cell - numDeleted] );
//                         A[row].erase(A[row].begin() + cell - numDeleted++);
//                         //--cell;
//                 }
//                 // item is to the left of diagonal, with no caveats
//                 else if (cell < row)
//                 {
//                     swap(A[row][cell], A[cell][row]);
//                 }
                
//             }
//         }
//         for (int v = 0; v < A.size(); ++v)
//         {
//             if (!A[v].size())
//             {
//                 A.erase(A.begin() + v);
//                 --v;
//             }
//         }
//         return A;
    }
    
    void swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
};