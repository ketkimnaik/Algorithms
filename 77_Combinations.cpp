Using recursion:

class Solution {
    
    void Helper(int n,int k, vector<int> path,vector<vector<int>> &result,int index)
    {
        if(path.size()==k)
        {
            
                
            result.push_back(path);
            return;
            
        }
        
        for(int i=index;i<=n;++i)
        {
            
                path.push_back(i);
                Helper(n,k,path,result,i+1);
                path.pop_back();
            
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> path{};
        vector<vector<int>> result{};
        Helper(n,k,path,result,1);
        return result;
        
    }
};


Using Iteration :

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result{};
        
        if(n==0 || k==0 )
            return result;
        
        vector<int> path(k,0);
        
        int i=0;
        
        while(i>=0)
        {
            if(i==k)
            {
                result.push_back(vector<int> (path));
                i--;
            }
            
            path[i]++;
            
            while((i > 0 && path[i]<=path[i-1]) || (i==0 && path[i]<=0))
            {
                path[i]++;
            }
            
            if(path[i] >n-k+i+1)
            {
                path[i]=0;
                i--;
                
            }
            
            else
            {
                i++;
            }
        }
        
        return result;
    }
};