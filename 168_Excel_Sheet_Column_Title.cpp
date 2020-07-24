class Solution {
public:
    string convertToTitle(int n) {
        
        int rem;
        string result = "";
        
        while(n) {
            
            rem = n % 26;
            
            n /= 26;
            
            if (rem == 0) {
                n -= 1;
                result = char(25 + 'A') + result;
            } else {
                result = char(rem - 1 + 'A') + result;
            }
            
        }
        
        return result;
    }
};