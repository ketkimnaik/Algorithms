Optimized:

class TrieNode {
        public:

    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        memset(child, 0, sizeof(child));
        isWord = false;
    }
};

class Trie {
    TrieNode* root;
    public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(auto &i : word) {
            if(node->child[i - 'a'] == nullptr) {
                node->child[i - 'a'] = new TrieNode();
            }
            node = node->child[i - 'a'];
        }
        node->isWord = true;
     }
    
    string replace(string word) {
        TrieNode* node = root;
        string result = "";
        for(auto &i : word) {
            result += i;
            if(node->child[i - 'a'] != nullptr) {
                
                if(node->child[i - 'a']->isWord == true) {
                    return result;
                } 
                node = node->child[i - 'a'];
            } else {
                return word;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie* trie = new Trie();
        
        for(auto &i : dict) {
            trie->insert(i);
        }
        
        istringstream ss(sentence);
        string w, result = "";
        
        while(ss >> w) {
            result += " " + trie->replace(w);
        }
        
        return result.substr(1);
    }
};


Brute Force:

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_map<string, string> mp;
        vector<string> tokens{};
        stringstream ss(sentence);
        string temp;
        while(getline(ss, temp, ' ')) {
            mp[temp] = temp;
            tokens.push_back(temp);
        }
        
        string t;
        
        for(auto i = mp.begin(); i != mp.end(); ++i) {
            for(auto &w : dict) {
                t = i->second;
                if(t.size() >= w.size()) {
                    if( w == t.substr(0, w.size())) {
                        i->second = w;
                    }
                }
            }   
        }
        
        string result = "";
        
        for(auto &t : tokens) {
            result += mp[t];
            result += " ";
        }
        
        return result.substr(0, result.size() - 1);
    }
};