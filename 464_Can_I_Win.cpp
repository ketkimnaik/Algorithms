Optimized Approach:

class Solution {
public:
    bool Helper(int m, int d, int &state, vector<int> &dp, int current) {
        if(dp[state] != 0)
            return dp[state] > 0 ? true : false;
        
        int large_num = m;
        
        while(large_num > 0 && (state & (1 << (large_num - 1))))
            large_num--;
        
        if(large_num + current >= d) {
            dp[state] = 1;
            return true;
        }
            
        for(int i = 0; i < m; ++i) {
            if((state & (1 << i)))
                continue;
            state |= (1 << i);
            
            if(Helper(m, d, state, dp, current + i + 1) == false) {
                state ^= (1 << i);
                dp[state] = 1;
                return true;
            }
            state ^= (1 << i);
        }
        
        dp[state] = -1;
        return false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal)
            return true;
        
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if(sum < desiredTotal)
            return false;
        int state = 0;
        vector<int> dp(1 << maxChoosableInteger, 0);
        
        return Helper(maxChoosableInteger, desiredTotal, state, dp, 0);
        
    }
};

Brute Force:

class Solution {
public:
    bool Helper(int m, int d, int state, map<int, bool> &mp) {
        if(mp[state] > 0)
            return true;
        
        for(int i = 0; i < m; ++i) {
            bool currChoose = (state & (1 << i)) != 0 ;
            if(!currChoose) {
                if(d <= (i + 1) || ! Helper(m, d - (i + 1), state | (1 << i), mp)) {
                    mp[state] = true;
                    return true;
                }
            }
        }
        
        mp[state] =false;
        return false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal)
            return true;
        
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if(sum < desiredTotal)
            return false;
        
        map<int, bool> mp;
        
        return Helper(maxChoosableInteger, desiredTotal, 0, mp);
        
    }
};