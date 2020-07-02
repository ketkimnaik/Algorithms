class Solution {
public:
    string decodeAtIndex(string S, long long int K) 
    {
       long long int temp=0; 
       for(int i = 0; i < S.size(); i++)
       {
           if(S[i] >= 'a' && S[i] <= 'z') {
               temp += 1;
           } else if(S[i] >= '2' && S[i] <= '9') {
           
              if((temp* (S[i] - 48)) < K) {
                 temp = temp * (S[i] - 48);
                  cout<<temp;
              } else {
                 if(K % temp == 0) {
                    return decodeAtIndex(S, temp);
                 } else {
                    return decodeAtIndex(S, K % temp); 
                 }
              } 
           }
              
           
           if(temp == K)
              return S.substr(i, 1); 
       }
       return ""; 
    }
};