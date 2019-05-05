class Solution {
public:
    int hammingDistance(int x, int y) {
        return calcOnes(x^y);
    }
    
    int calcOnes(int x)
    {
        unsigned int total = 0;
        int newX = x;
        while (newX != 0)
        {
            if (newX % 2 != 0){
                //cout << "incremented" << endl;
                ++total;
            } 
            //cout << "x " << newX << endl;
            newX = newX >> 1;
            //cout << "x after " << newX << endl;
        }
        return total;
    }
};