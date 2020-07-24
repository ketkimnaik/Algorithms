class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long int left = 0, right = sqrt(c);
        long int temp;
        
        while(left <= right) {
            
            temp = left * left + right * right;
            
            if (temp > c) {
                right--;
            } else if (temp < c) {
                left++;
            } else {
                return true;
            }
        }
        
        return false;
        
    }
};