class Solution {
public:
    int diff=0;
    int maxProfit(vector<int>& prices) {
        
        if(prices.empty())
            return 0;
        int minprice=prices[0];
        int result=0;
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<minprice)
                minprice=prices[i];
            else
                result=max(prices[i]-minprice,result);
        }
        
        return result;
    }
};