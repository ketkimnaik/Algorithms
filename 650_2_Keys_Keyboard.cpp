class Solution {
public:
    int factor(int val) {
        
        for(int i = val / 2; i >= 1; --i) {
            if(val % i == 0) return i;
        }
        
        return 1;
    }
    int minSteps(int n) {
        
        if(n <= 1) return 0;
        int ans = 0;
        
        while(n) {
            int f = factor(n);
            ans += (n / f);
            if(f == 1) break;
            n = f;
        }
        
        return ans;
        
    }
};