class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result{{}};
        vector<int> temp{};
        int size;
        
        for(int n : nums) {
            size = result.size();
            for(int i = 0; i < size; ++i) {
                temp = result[i];
                temp.push_back(n);
                result.push_back(temp);
            }
        }
        
        return result;
    }
};