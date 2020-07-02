class Solution {
public:
    bool IP4Validation(string IP) {
        if(IP.size() == 0 || IP.size() > 3)
            return false;
        
        if(IP.size() > 1 && IP[0] == '0')
            return false;
        int num = 0;
        for(int i = 0; i < IP.size(); ++i) {
            if(isdigit(IP[i]) == false)
                return false;
            num = num *10 + (IP[i] - '0');
        }
        
        if(num >= 0 && num <= 255)
            return true;
        
        return false;
    }
    
    bool IP6Validation(string IP) {
        if(IP.size() == 0 || IP.size() > 4)
            return false;
        
        for(int i = 0; i < IP.size() ; ++i) {
            if((IP[i] >= 'A' && IP[i] <= 'F') 
               || (IP[i] >= 'a' && IP[i] <= 'f') 
               || (isdigit(IP[i])))
                
                continue;
            else
                return false;
        }
        
        return true;
        
    }
    
    string validIPAddress(string IP) {
        stringstream ss(IP);
        string temp;
        bool result = true;
        
        int a = count(IP.begin(), IP.end(), '.');
        int num = 0;
        
        if(a == 3 ){
            while(getline(ss, temp, '.')) {
                num++;
                result &= IP4Validation(temp);
                if(result == false)
                    return "Neither";
            }
            
            if(num < 4)
                return "Neither";
            
            return "IPv4";
        }
        
        int b = count(IP.begin(), IP.end(), ':');
        
        if(b == 7) {
            while(getline(ss, temp, ':')) {
                result &= IP6Validation(temp);
                if(result == false)
                    return "Neither";
            }
            return "IPv6";
        }
        
        return "Neither";
        
    }
};