class Solution {
public:
    bool match(string pattern,string word)
    {
        if(pattern.size() != word.size())
            return false;
        
        map<char,char> m;
        vector<bool> track(26,false);
        
        for(int i=0;i<pattern.size();++i)
        {
            if(m.find(pattern[i])==m.end()  && track[word[i]-'a']==false)
            {
                m[pattern[i]]=word[i];
                track[word[i]-'a']=true;
            }
            else if(m.find(pattern[i])==m.end()  && track[word[i]-'a']==true)
                return false;
            else
            {
                if(word[i]==m[pattern[i]])
                    continue;
                else
                    return false;
            }
        }
        
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> result{};
        for(int i=0;i<words.size();++i)
        {
            if(match(pattern ,words[i]))
            {
                result.push_back(words[i]);
            }
        }
        
        return result;
    }
};