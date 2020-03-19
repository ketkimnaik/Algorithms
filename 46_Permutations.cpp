class Solution {
    
    void Helper(vector<int> &nums,vector<int> &path, vector<vector<int>> &result)
    {
        
        //base condition
        if(path.size()==nums.size())
        {
            result.push_back(path);
            return;
        }
        
        //induction condition
        
        for(int i=0;i<nums.size();++i)
        {
            if(count(path.begin(),path.end(),nums[i])==0)
            {
                 path.push_back(nums[i]);
            Helper(nums,path,result);
                path.pop_back();
            }
           
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result{};
        vector<int> path{};
        
        if(nums.size()==0)
            return result;
        Helper(nums,path,result);
        return result;
    }
};