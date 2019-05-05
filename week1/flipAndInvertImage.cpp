class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        //12ms runtime with 9.3mb storage
        int rowSize = A[0].size();
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < rowSize / 2; ++j)
            {
                invertedSwap(A[i][j], A[i][rowSize - j - 1]);
            }
        }
        if (rowSize % 2 != 0)
        {
            for (int i = 0; i < A.size(); ++i)
            {
                A[i][rowSize / 2] = !A[i][rowSize / 2];
            }
        }
        return A;
    }
    
    void invertedSwap(int& x, int& y)
    {
        int temp = x;
        x = !y;
        y = !temp;
    }
};