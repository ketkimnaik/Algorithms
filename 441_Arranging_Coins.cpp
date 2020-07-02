class Solution {
public:
    int arrangeCoins(long long int n) {
        
        return floor((-1 + sqrt(1 + 8 * n))/2.0);
        
    }
};

Brute Force:

class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        
        int limit = ceil(n / 2.0);
        int sum = 0;
        for(int i = 1; i <= limit; ++i) {
            sum += i;
            count++;
            if(n - sum < i + 1) break;
        }
        
        return count;
    }
};