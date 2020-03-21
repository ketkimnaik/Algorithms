class Solution {
public:
    int characterReplacement(string s, int k) {
        int maximum=0,result=0;
        vector<int> record(26,0);
        for(int i=0,j=0;j<s.length();++j)
        {
            maximum=max(maximum,++record[s[j]-'A']);
            
            if((j-i+1 )> (maximum+k))
            {
                record[s[i]-'A']--;
                i++;
                
            }
            
            result=max(result,j-i+1);
        }
        
        return result;
    }
};