struct TrieNode {
    unordered_map<char, TrieNode*> child;
    int sum;
    TrieNode(){
        sum = 0;
    }
  
};

class MapSum {
    TrieNode* root;
    unordered_map<string, int> m;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
        root->sum = 0;
    }
    
    void insert(string key, int val) {
        TrieNode* node = root;
        //if key already exist
        if(m.find(key) != m.end()) {
            val -= m[key];
        }
        
        node->sum += val;
        
        for(int i = 0; i < key.size(); ++i) {
            if(node->child.find(key[i]) != node->child.end()) {
                node = node->child[key[i]];
                node->sum += val;
            } else {
                TrieNode* tmp = new TrieNode();
                node->child[key[i]] = tmp;
                tmp->sum = 0;
                node = tmp;
                node->sum += val;
            }
            
        }
        
        m[key] = node->sum;
        
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        
        for(int i = 0; i < prefix.size(); ++i) {
            
            if(node->child.find(prefix[i]) == node->child.end()) {
                return 0;
            } else {
                node = node->child[prefix[i]];
                
            }
        }
        
        return node->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */