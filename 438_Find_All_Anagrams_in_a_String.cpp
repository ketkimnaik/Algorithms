class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result{};
        
        if(s.size()<p.size())
            return result;
        vector<int> s_freq(26,0);
        vector<int> p_freq(26,0);
        
        int i=0;
        
        for(;i<p.size();++i)
        {
            s_freq[s[i]-'a']++;
            p_freq[p[i]-'a']++;
            
        }
        
        if(s_freq==p_freq)
            result.push_back(0);
        
        for(;i<s.size();++i)
        {
            s_freq[s[i-p.size()]-'a']--;
            s_freq[s[i]-'a']++;
            
            if(s_freq==p_freq)
                result.push_back(i-p.size()+1);
        }
        
        return result;
        
    }
};