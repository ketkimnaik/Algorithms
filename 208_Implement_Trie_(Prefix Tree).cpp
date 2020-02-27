struct TrieNode{
    TrieNode *child[26]={nullptr};
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
    }
    
};

class Trie {
    TrieNode *node;
public:
    /** Initialize your data structure here. */
    Trie() {
        
        node=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n=word.length();
        int index=0;
        TrieNode *root=node;
        for(int i=0;i<n;++i)
        {
            index=word[i]-'a';
            if(root->child[index]==nullptr)
                root->child[index]=new TrieNode();
            root=root->child[index];
        }
        root->isEnd=true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n=word.length();
        int index;
        TrieNode *root=node;
        for(int i=0;i<n;++i)
        {
            index=word[i]-'a';
            if(root->child[index] ==nullptr)
                return false;
            else
                root=root->child[index];
        }
        return root->isEnd;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        
        int n=word.length();
        int index=0;
        TrieNode *root=node;
        for(int i=0;i<n;++i)
        {
            index=word[i]-'a';
            if(root->child[index]!=nullptr)
                root=root->child[index];
            else 
                return false;
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */