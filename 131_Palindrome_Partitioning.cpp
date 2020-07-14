class Solution {
public:
    bool palindrome(string s) {
        int size = s.size();
        for(int i = 0; i < size / 2; ++i) {
            if(s[i] != s[size- 1 - i]) return false;
        }
        
        return true;
    }
    
    void DFS(string &s, int index, vector<string> &path, vector<vector<string>> &result, int size) {
        if(index == size) {
            result.push_back(path);
            return;
        }
        
        for(int i = index; i < size; ++i) {
            string temp = s.substr(index, i - index + 1);
            if(palindrome(temp)) {
                path.push_back(temp);
                DFS(s, i + 1, path, result, size);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result{};
        vector<string> path{};
        DFS(s, 0, path, result, s.size());
        return result;
    }
};