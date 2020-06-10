class Solution {
public:
    bool isPrime(int n){
        return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || 
            n == 23 || n == 29 || n == 31;
    }
    
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        int count = 0;
        for(int i = L; i <= R; i++) {
            count = __builtin_popcount(i);
            res += isPrime(count);
        }
        return res;
    }
    
    
};