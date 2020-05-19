class Solution {
public:
    /*static bool compare(string &a,string &b)
    {
        return a.size()<b.size();
    }
    */
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),[](string &a,string &b){return a.size()<b.size();});
        
        unordered_map <string,int> mp;
        
        for(auto &w: words)
            mp[w]=1;
        int result=1;
        for(auto &w:words)
        {
            for(int i=0;i<w.size();++i)
            {
                string curr=w.substr(0,i)+w.substr(i+1);
                if(mp.count(curr)==1)
                    mp[w]=mp[curr]+1;
                result=max(result,mp[w]);
            }
            
        }
        
        return result;
        
    }
};