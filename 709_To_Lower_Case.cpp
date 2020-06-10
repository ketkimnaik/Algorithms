class Solution {
public:
    string toLowerCase(string str) {
        int temp;
        for(auto &i : str) {
            if(i >= 'A' && i <= 'Z') {
                temp = i - 'A';
                i = (char)('a' + temp);
            }
        }
        
        return str;
    }
};