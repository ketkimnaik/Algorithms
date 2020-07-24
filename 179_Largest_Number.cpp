class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> num;
        
        for(auto n : nums) {
            num.push_back(to_string(n));
        }
        
        sort(num.begin(), num.end(), [](string a, string b) {
            return stoll(a + b) > stoll(b + a);
        });
        
        int i = 0;
        string ans = "";
        while(i < num.size() && num[i] == "0") ++i;
        
        for(; i < num.size(); ++i) {
            
            ans += num[i];
        }
        
        return ans.size() ? ans : "0";
    }
};