class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return binarySearch(0, A.size() - 1, A);
    }
    
    int binarySearch(int start, int end, vector<int>& A)
    {
        int midpoint = start + (end - start) / 2;
        if (A[midpoint - 1] < A[midpoint] && A[midpoint + 1] > A[midpoint])
            return binarySearch(midpoint + 1, end, A);
        else if (A[midpoint - 1] > A[midpoint] && A[midpoint + 1] < A[midpoint])
            return binarySearch(start, midpoint - 1, A);
        return midpoint;
    }
};