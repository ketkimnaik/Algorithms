class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        vector<int> count(26,0);
        for(int i=0;i<n;++i)
        {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        
        int result=0;
        for(auto &i: count)
        {
            if(i>0)
               result+=i; 
        }
        
        return result;
        
    }
};