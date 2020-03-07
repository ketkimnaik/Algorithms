class Solution {
    vector<vector<int>> result;
public:
    
    void DFS(vector<int>& candidates,vector<int>& temp_result,int ind,int sum,int target)
    {
        if(sum==target)
        {
            result.push_back(temp_result);
        }
        
        for(int i=ind;i<candidates.size();++i)
        {
            if(sum+candidates[i]<=target)
            {
                
                temp_result.push_back(candidates[i]);
                DFS(candidates,temp_result,i,sum+candidates[i],target);
               temp_result.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        if(candidates.size()==0)
            return {};
        
        vector<int> temp_result;
        DFS(candidates,temp_result,0,0,target);
        return result;
    }
};