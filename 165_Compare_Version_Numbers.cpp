class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1==version2)
            return 0;
        
        int ver1=Extractstring(version1,version1);
        int ver2=Extractstring(version2,version2);
        
        if(ver1==ver2)
        {
            return compareVersion(version1,version2);
        }
        
        return ver1<ver2?-1:1;
        
    }
    
    int Extractstring(string &input,string &next)
    {
        if(input.empty())
            input="0";
        
        int dotind=0;
        while(dotind<input.size() && input[dotind] != '.')
        {
            dotind++;
        }
        
        int ver=stoi(input.substr(0,dotind));
        
        next= dotind>=input.size()? "" :input.substr(dotind+1);
        return ver;
    }
};