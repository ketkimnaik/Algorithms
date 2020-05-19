class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        int n=searchWord.size();
        vector<vector<string>> result(n);
        sort(products.begin(),products.end());
        
        for(int i=0;i<n;++i)
        {
            int count=0;
            
            for(auto &p: products)
            {
                if(count==3)
                    break;
                else
                {
                    string temp=searchWord.substr(0,i+1);
                    if(temp.compare(p.substr(0,i+1))==0)
                    {
                        count++;
                        result[i].push_back(p);
                    }
                }
            }
            
           if(count==0)
               break;
            
        }
        
        return result;
        
    }
};