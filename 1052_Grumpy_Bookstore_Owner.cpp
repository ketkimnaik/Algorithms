class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int common_sum = 0;
        
        for(int i = 0; i < customers.size(); ++i) {
            if(grumpy[i] == 0) {
                common_sum += customers[i]; 
            }
        }
        int ans = common_sum;
        int i = 0;
        for(; i < X; ++i) {
            if(grumpy[i] == 1) {
                ans += customers[i];
            }
        }
        
        int max_ans = ans;
        for(; i < customers.size(); ++i) {
            if(grumpy[i - X] == 1) {
                    ans -= customers[i - X];
                }
            if(grumpy[i] == 1) {
                ans += customers[i];
            }
            
            max_ans = max(max_ans, ans);
        }
        
        return max_ans;
    }
};