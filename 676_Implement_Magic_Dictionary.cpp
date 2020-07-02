Using hashmap:

class MagicDictionary {
public:
    map<int, vector<string>> mp;
    /** Initialize your data structure here. */
    MagicDictionary() {
        mp.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto &w : dict) {
            mp[w.size()].push_back(w); 
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if(mp.count(word.size()) == 1) {
            for(auto &w : mp[word.size()]) {
                int count = 0;
                for(int i = 0; i < word.size(); ++i) {
                    if(w[i] != word[i]) count++;
                }
                if(count == 1) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */

Using Trie:

class TrieNode {
    public:
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        memset(child, 0, sizeof(child));
        isWord = false;
    }
};
class MagicDictionary {
public:
    TrieNode * root;
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        TrieNode* node;
        
        for(auto &i : dict) {
            node = root;
            for(auto &j : i) {
                if(node->child[j - 'a'] == nullptr) {
                    node->child[j - 'a'] = new TrieNode;
                }
                node = node->child[j - 'a'];
            }
            node->isWord = true;
        }
    }
    
    bool find(string word) {
        TrieNode* node = root;
        for(auto& i : word) {
            if(node->child[i - 'a'] == nullptr) {
                return false;
            } else {
                node = node->child[i - 'a'];
            }
        }
        
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        TrieNode* node = root;
        for(auto &w : word) {
            for(int i = 0; i < 26; ++i) {
                char c = 'a' + i;
                if(w == c) continue;
                char temp = w;
                w = c;
                if(find(word)) {
                    return true;
                }
                w = temp;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */