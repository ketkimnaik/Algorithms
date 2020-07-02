class RandomizedSet {
    map<int, int> mp;
    vector<int> vp{};
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) == mp.end()) {
            vp.push_back(val);
            mp[val] = vp.size() - 1;
            
           /* for(int i = 0; i < vp.size(); ++i)
                cout<< vp[i] << "  ";*/
            
            //cout<<endl;
            return true;
        }
        else {
            return false;
        }
        
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        else {
            mp[vp.back()] = mp[val];
            vp[mp[val]] = vp.back();
            vp.pop_back();
            mp.erase(val);
           /* for(int i = 0; i < vp.size(); ++i)
                cout<< vp[i] << "  ";*/
            
           // cout<<endl;
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        //cout<<vp[0];
        return vp[rand() % vp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */