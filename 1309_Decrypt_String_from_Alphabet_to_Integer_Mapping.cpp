Optimized solution:

class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '#')
            {
                int index = stoi(s.substr(i - 2, 2));
                char c = 'a' + index - 1;
                ans.pop_back();
                ans.pop_back();
                ans.push_back(c);
            }
            else ans.push_back((s[i] - '0') + 'a' - 1);
        }
        return ans;
    }
};

Brute Force:

class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        
        for(int i = 0; i < s.size();) {
            //cout<<(char)('a' + stoi(s.substr(i, 2)) - 1)<<endl;
            if(s[i] == '1' || s[i] == '2') {
                if(i + 2 < s.size() && s[i + 2] == '#' ) {
                    result += (char)('a' + stoi(s.substr(i, 2)) - 1);
                    i +=3;
                }
                else {
                    result += (char)('a' + stoi(s.substr(i, 1)) - 1);
                    i++;
                }
            }
            else {
                result += (char)('a' + stoi(s.substr(i, 1)) - 1);
                i++;
            }
        }
        
        return result;
    }
};