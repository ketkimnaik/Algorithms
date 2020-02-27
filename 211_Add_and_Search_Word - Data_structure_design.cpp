struct TrieNode{
  TrieNode *child[26]={nullptr};
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
    }
};

class WordDictionary {
    TrieNode *root;
    
    bool helper(string word,TrieNode* root)
    {
        int n=word.size();
        TrieNode *current=root;
        for(int i=0;i<n;++i)
        {
            char a=word[i];
         if(a != '.')
         {
             int index=word[i]-'a';
        if(current->child[index]==nullptr)
            return false;
        else 
            
            current=current->child[index];
            } 
            
         else
         {
             bool f;
             int j=0;
             for( ;j<26;++j)
             {
                 if(current->child[j])
                     f |= helper(word.substr(i+1),current->child[j]);
                 
                 if(f)
                     return true;
             }
             if(j==26)
                return false;
             
             }
            
            
        }
        
        return current->isEnd;
         
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n=word.size();
        int index;
        TrieNode *current=root;
        for(int i=0;i<n;++i)
        {
            index=word[i]-'a';
            if(current->child[index]==nullptr)
                current->child[index]=new TrieNode();
            current=current->child[index];
                
        }
        current->isEnd=true;
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(word,root);
        
       
        }
        
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */