class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size())
            return "0";
        int temp=k;
        string result;
        
        for(auto &n: num)
        {
            while(!result.empty() && k>0 && result.back()>n)
            {
                result.pop_back();
                --k;
            }
            
            if(!(result.empty() && n=='0'))
                result.push_back(n);
        }
        
        return result.empty()?"0":result.substr(0,num.size()-temp);
    }
};