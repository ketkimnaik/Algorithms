class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> result(2,-1);
        
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<numbers.size();++i)
        {
            if(mp.find(numbers[i]) !=mp.end())
            {
                result[0]=mp[numbers[i]];
                result[1]=i+1;
                break;
            }
            else
                mp[target-numbers[i]]=i+1;
        }
        
        return result;
        
    }
};