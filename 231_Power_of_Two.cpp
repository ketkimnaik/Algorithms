class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        //int count = __builtin_popcount(n);
        if(__builtin_popcount(n) == 1)
            return true;
        
        return false;
    }
};