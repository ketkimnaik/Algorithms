class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        int i=0;
        for(;i<s1.size();++i)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        
        if(v1==v2)
            return true;
        
        for(;i<s2.size();++i)
        {
            v2[s2[i-s1.size()]-'a']--;
            v2[s2[i]-'a']++;
            
            if(v1==v2)
                return true;
        }
        
        return false;
        
        
        
    }
};