class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        
        for(auto &i : arr1) {
            mp[i]++;
        }
        
        int j = 0;
        for(auto &i : arr2) {
            while(mp[i]--) {
                arr1[j++] = i;
            }
            mp.erase(i);
        }
        
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            while((it->second)--)
                arr1[j++] = it->first;
        }
        
        return arr1;
    }
};