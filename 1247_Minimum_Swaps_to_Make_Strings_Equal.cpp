class Solution {
public:
    int minimumSwap(string s1, string s2) {
        
        int x1 = 0;
        int x2 = 0;
        
        for(int  i = 0; i < s1.size(); ++i) {
            if(s1[i] == s2[i]) {
                continue;
            } else if(s1[i] == 'x') {
                x1++;
            } else {
                x2++;
            }
        }
        
        if((x1 + x2) % 2 != 0) return -1;
        
        return (x1 / 2) + (x2 / 2) + (x1 % 2) + (x2 % 2);
    }
};