class Solution {
public:
    string sortString(string s) {
        bool check = true;
        string result="";
        vector<int> letters(26, 0);
        
        for(int i = 0; i < s.size(); ++i){
            letters[s[i] - 'a']++;
        }
        
        for(int i = 0; i < s.size();){
            if(check){
                for(int j = 0; j < 26; ++j){
                    if(letters[j] > 0){
                        letters[j]--;
                        char c = j + 'a';
                        string s1(1, c);
                        result += s1;
                        ++i;
                    }
                }
            }
            else{
                for(int j = 25; j >= 0; --j){
                    if(letters[j] > 0){
                        letters[j]--;
                        char c = j + 'a';
                        string s1(1, c);
                        result += s1;
                        ++i;
                    }
                }
            }
            
            check = !(check);
        }
        
        return result;
        
    }
};