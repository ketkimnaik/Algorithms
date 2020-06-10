class Solution {
    
public:
    
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> temp(A.size(), vector<int> (26, 0));
        vector<string> result{};
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < A[i].size(); ++j) {
                temp[i][A[i][j] - 'a']++; 
            }
        }
        
        for(int i = 0; i < 26; ++i) {
            int min_val = INT_MAX;
            for(int j = 0; j < A.size(); ++j) {
                min_val = min(min_val, temp[j][i]);
            }
            if(min_val){
                while(min_val--){
                    char c = (char)(i+'a');
                    string s(1,c);
                    result.push_back(s);
                   
                }
            }
        }
       return result;
    }
};