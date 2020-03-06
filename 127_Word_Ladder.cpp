class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(beginWord.size()==0 || endWord.size()==0 || beginWord.size()!=endWord.size())
            return 0;
        
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        
        q.emplace(beginWord);
        s.erase(beginWord);
        int level=0;
        
        int level_node=q.size();
        while(!q.empty())
        {
            string curr=q.front();
            q.pop();
            
            if(curr==endWord)
                return level+1;
            
            for(int i=0;i<curr.size();++i)
            {
                char curr_char=curr[i];
                for(int j=0;j<26;++j)
                {
                    curr[i]='a'+j;
                    string word=curr;
                    
                    if(s.find(curr)!=s.end())
                    {
                        q.emplace(word);
                        s.erase(word);
                    }
                    
                    curr[i]=curr_char;
                    
                    
                
                }
                
                
                
                
            }
            --level_node;
            if(level_node == 0)
                {
                    ++level;
                    level_node=q.size();
                }
            
        }
        return 0;
    
    }
};