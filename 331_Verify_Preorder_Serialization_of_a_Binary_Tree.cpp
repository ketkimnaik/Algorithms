class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        int count = 0;
        for(int i = 0 ; i < preorder.size() ; i++){
            
            if(preorder[i] == ',') 
            {
                if(i>0 && preorder[i-1]==',')
                    return false;
                else
                continue;
                
            }
            
            if(count < 0) return false;
            
            if(preorder[i] == '#')
                count--;
            else{
                while(i < preorder.size() && preorder[i]!=','  )//for greater than single digit numbers
                    i++;
                count++;
            }
                
        }
        if(count == -1) return true;// Null nodes will always be greater than other nodes by 1
        return false;
        
    }
};