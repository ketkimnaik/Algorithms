class Solution {
    
    void DFS(vector<int> &candidates,int target,int curr,vector<int> &path,vector<vector<int>> &result)
    {
        if(target==0)
        {
            if(find(result.begin(),result.end(),path)==result.end())
            result.push_back(path);
            return;
        }
          for(int i=curr;i<candidates.size();++i)
          {
              if(candidates[i]>target)
                  continue;
              path.push_back(candidates[i]);
              
              DFS(candidates,target-candidates[i],i+1,path,result);
              path.pop_back();
          }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> result{};
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        DFS(candidates,target,0,path,result);
        return result;
        
    }
};