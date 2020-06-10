class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        
        for(auto &i : address) {
            if(i == '.') {
                result += '[';
                result += '.';
                result += ']';
            }
            else
                result += i;
                
        }
        
        return result;
    }
};