class Solution {
public:
    double myPow(double x, int n) {
        
        double result = 1.0;
        
        if (n < 0) {
            x = 1.0 / x;
        }
        
        while(n) {
            
            if (n % 2 != 0) {
                result *= x;
            }
            
            n /= 2;
            
            x *= x;
            
        }
        
        return result;
    }
};