class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> result(candies.size(),false);
        
        int max_ele=*max_element(candies.begin(),candies.end());
        
        for(int i=0;i<candies.size();++i)
        {
            if(candies[i]+extraCandies>=max_ele)
                result[i]=true;
            
        }
        
        return result;
        
    }
};