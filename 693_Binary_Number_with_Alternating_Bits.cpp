class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool remainder;
        if(n % 2 == 0)
            remainder = 1;
        else
            remainder = 0;
        while(n > 0) {
            if(remainder == (n % 2))
                return false;
            else {
                remainder = n % 2;
                n /= 2;
            }
        }
        return true;
    }
};