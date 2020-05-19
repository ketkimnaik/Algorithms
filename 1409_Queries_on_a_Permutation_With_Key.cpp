class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> demo(m);
        vector<int> result(queries.size());
        for(int i=1;i<=m;++i)
            demo[i-1]=i;
        
        for(int i=0;i<queries.size();++i)
        {
            int f=queries[i];
            int k=0;
            for(;k<m;++k)
            {
                if(f==demo[k])
                {
                    result[i]=k;
                   break;
                }
                
            }
            
            for(int j=k-1;j>=0;--j)
            {
                demo[j+1]=demo[j];
            }
                
            demo[0]=f;
        }
            
        return result;
    }
};