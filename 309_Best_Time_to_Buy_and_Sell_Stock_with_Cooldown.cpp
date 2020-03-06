class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if(prices.size()==0 || prices.size()==1)
           return 0;
        
        int wait=INT_MIN, Buy=INT_MIN;
        int cool_Down=0,sell=0;
        
        for(auto i : prices)
        {
            wait=max(wait,Buy);
            Buy=cool_Down-i;
            cool_Down=max(cool_Down,sell);
            sell=wait+i;
        }
        
        return max(cool_Down,sell);
    }
};