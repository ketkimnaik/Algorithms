class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size() - 1;
        int bsize = b.size() - 1;
        string result = "";
        int carry = 0;
        
        while(asize >= 0 || bsize >= 0 || carry == 1) {
            
            carry += (asize >= 0 ? a[asize] - '0' : 0);
            carry += (bsize >= 0 ? b[bsize] - '0' : 0);
            
            result = char(carry % 2 + '0') + result;
            
            carry /= 2;
            
            asize--;
            bsize--;
            
        }
        
        return result;
    
    }
};