class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_code(26);
        
        morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",
                      ".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        map<string, int> mp;
        string temp;
        int count = 0;
        
        for(auto &i : words) {
            temp = "";
            for(int j = 0; j < i.size(); ++j) {
                temp += morse_code[i[j] - 'a'];
            }
            
            if(mp.find(temp) == mp.end()) {
                count++;
                mp[temp]++;
            }
            
        }
        
        return count;
    }
};