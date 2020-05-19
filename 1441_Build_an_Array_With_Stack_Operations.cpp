class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> result{};
        int j=0;
        int size=target.size();
        for(int i=1;i<=n;++i)
        {
            if(size==j)
                break;
            
            if(target[j]==i)
            {
                result.push_back("Push");
                j++;
            }
            else
            {
                result.push_back("Push");
                result.push_back("Pop");
            }
            
        }
        
        return result;
    }
};