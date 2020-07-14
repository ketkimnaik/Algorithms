static auto __io_speed_up = [](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;  
}();
class Solution {
public:
    string reverseWords(string s) {
        int i, t, st, j;
        string s2 = s;
        
        st = 0;
        j = 0;
        for(i = 0; i < s.size(); i++){
            if (i == s.size() - 1){
                t = i;
                while(t >= st) {
                    s2[j] = s[t];
                    j++;
                    t--;
                }
            } else if (s[i] == ' ') {
                t = i - 1;
                while(t >= st) {
                    s2[j] = s[t];
                    j++;
                    t--;
                }
                s2[j] = ' ';
                j++;
                st = i + 1;
           
            }
        }

        return s2;
    }
};