class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)return "0";
        long n = numerator;
        long d = denominator;
        string ans = "";
        long val = n/d;
        if(n<0 ^ d <0) {
            ans += "-";
        }
        if(n < 0) {
            n *= (-1);
            val *= (-1);
        }
        if(d < 0) {
            d *= (-1);
            val *=(-1);
        }
        ans += to_string(val);
        long r = n%d;
        if(r == 0) return ans;
        ans += ".";
        unordered_map<int,int> m;
        while(r!=0) {
            if(m.find(r) != m.end()) {
                ans.insert(m[r],"(");
                ans += ")";
                break;
            } else {
                m[r] = ans.size();
                r = r*10;
                ans += to_string(r/d);
                r = r%d;
            }
        }
        return ans;
    }
};