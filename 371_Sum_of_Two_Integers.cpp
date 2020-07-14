class Solution {
public:
    int getSum(int a, int b) {
        //using bit manupalation
        
        while(b) {
            unsigned int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        
        return a;
    }
};