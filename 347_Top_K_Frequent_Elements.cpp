class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> hash;
        priority_queue <pair<int, int> ,vector<pair<int, int>>, greater<pair<int, int>>> Q;
        for (auto i: nums) {
           hash[i]++;
        }
        for (auto x=hash.begin(); x!=hash.end(); x++) {
            Q.push(make_pair(x->second, x->first));
            if (Q.size()>k)
                Q.pop();
        }
        while(Q.size()) {
            auto val = Q.top();
            ans.push_back(val.second);
            Q.pop();
        }
        
        return ans;
    }
};