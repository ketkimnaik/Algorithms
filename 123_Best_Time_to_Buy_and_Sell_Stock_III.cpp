


Optimized Solution:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MIN / 2;
        int firstSell = INT_MIN / 2;
        int secondBuy = INT_MIN / 2;
        int secondSell = INT_MIN / 2;
        
        int preFirstBuy;
        int preFirstSell;
        int preSecondBuy;
        
        for(auto &i : prices) {
            preFirstBuy = firstBuy;
            preFirstSell = firstSell;
            preSecondBuy = secondBuy;
            
            firstBuy = max(firstBuy, -i);
            firstSell = max(firstSell, preFirstBuy + i);
            secondBuy = max(secondBuy, preFirstSell - i);
            secondSell = max(secondSell, preSecondBuy + i);
            
        }
        
        if(max(firstSell, secondSell) > 0) {
            return max(firstSell, secondSell);
        }
        
        return 0;
    }
};


Brute Force:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1) {
            return 0;
        }
        
        int max_element = INT_MIN;
        vector<vector<int>> T(3, vector<int> (size, 0));
        
        int max_diff ;
        
        for(int i = 1; i <= 2; ++i) {
            max_diff = -prices[0];
            for(int j = 1; j < size; ++j) {
                T[i][j] = max(T[i][j - 1], prices[j] + max_diff );
                max_diff = max(max_diff, T[i - 1][j] - prices[j]);
                max_element = max(max_element, T[i][j]);
            }
        }
            
         return max_element;  
    }
};