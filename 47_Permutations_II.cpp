class Solution {
    
    
    
    void Helper(vector<int> &nums,vector<int> &path,vector<vector<int>> &result,unordered_map<int,int> &mp)
    {
        //base condition
        
        if(path.size()==nums.size())
        {
          
                result.push_back(path);
                return;
            
        }
        
        //inductive condition
        for(int i=0;i<nums.size();++i)
        {
            if(mp[nums[i]]>0)  
            {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            path.push_back(nums[i]);
                mp[nums[i]]--;
            Helper(nums,path,result,mp);
                mp[nums[i]]++;
            path.pop_back();
                
                
            }
            
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<int> path{};
        vector<vector<int>> result{};
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        if(nums.size()==0)
            return result;
        
        for(int i=0;i<nums.size();++i)
        {
            mp[nums[i]]++;
        }
        
        Helper(nums,path,result,mp);
        return result;
    }
};