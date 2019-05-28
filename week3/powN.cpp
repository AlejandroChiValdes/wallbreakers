class Solution {
public:
    double myPow(double x, int n) {
        if (!n) return 1;
        
        double temp = myPow(x, n / 2);
        if (n % 2 == 0)
            return temp * temp;
        else if (n > 0)
            return x * temp * temp;
        return 1/x * temp * temp;
    }
    
//     double myPow(double x, int n) {
//         //vector<int> pows(n, -1);
//         bool applyNegative = n < 0;
//         if (n == -2147483648)
//         {
//             cout << "blah" << endl;
//             n = n + 1;
//             cout << n << endl;
//         }
//         double result = calcPow(x, abs(n));
//         return applyNegative ? 1 / result : result;
//     }
    
//     long double calcPow(int x, int n)
//     {
//         cout << "passed in x " << x << "n " << n << endl;
//         if (n == 0)
//             return 1; 
//         else if (n == 2)
//         {
//             //cout << "x " << x << endl;
//             return x * x;
//         }
            
//         else if (n % 2 == 0)
//         {
//             return calcPow(calcPow(x, n / 2), 2);
//         }
//         else
//         {
//             return x * calcPow(x, n - 1);
//         }
//     }
};