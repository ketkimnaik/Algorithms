class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        //common numbers cancel out each other
        for(auto &n : nums) {
            x ^= n;
        }
        //find the set bit
        int bit = 0;
        for(int i = 0; i < 32; ++i) {
            if(x & (1 << i)) {
                bit = i;
                break;
            }
        }
        
        //get the first number;
        int first = 0;
        for(auto &n : nums) {
            if(n & (1 << bit)) {
                first ^= n;
            }
        }
        
        //get second number
        int second;
        second = x ^ first;
        
        return {first, second};
    }
};