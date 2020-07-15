class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int sum = 0;
        int mul = 1;
        int rem;
        
        while(n) {
            
            rem = n % 10;
            mul = mul * rem;
            sum += rem;
            n /= 10;
        }
        
        return mul - sum;
    }
};