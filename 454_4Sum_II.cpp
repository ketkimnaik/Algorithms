class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        int result = 0;
        
        for(auto&i : A) {
            for(auto &j : B) {
                mp[i + j]++;
            }
        }
        
        for(auto& i : C) {
            for(auto &j : D) {
                result += mp[0 - i - j];
            }
        }
        
        return result;
    }
};