class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        //only 64 patterns are possible because after 1st loop 1st and 8th bit is going to be 0
        vector<int> temp(8);
        vector<vector<int>> dp;
        
        while(N--) {
            for(int i = 1; i < 7; ++i) {
                temp[i] = cells[i - 1] == cells[i + 1];
            }
            
            if(dp.size() && (dp.front() == temp)) {
                return (dp[N % dp.size()]);
            } else {
                dp.push_back(temp);
            }
            
            cells = temp;
        }
        
        return cells;
    }
};