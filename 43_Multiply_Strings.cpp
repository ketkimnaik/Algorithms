class Solution {
public:
    string multiply(string nums1, string nums2) {
        if(nums1=="0" || nums2=="0")
            return "0";
        
        int carry=0;
        int length=219;
        
        int ind;
        char a[nums1.length()+nums2.length()];
        int result;
        int num;
        memset(a,'0',nums1.length()+nums2.length());
        
        int i=nums1.size()-1;
        for(;i>=0;--i)
        {
            ind=nums1.size()+nums2.length()-nums1.length()+i;
            for(int j=nums2.length()-1;j>=0;--j)
            {
                result=carry+(nums1[i]-'0')*(nums2[j]-'0');
                carry=((a[ind]-'0')+result)/10;
                a[ind]=(((a[ind]-'0')+result)%10+'0');
                ind--;
                
            }
            
            while(carry>0)
            {
                result=carry;
                
                carry=((a[ind]-'0')+result)/10;
                a[ind]=(((a[ind]-'0')+result)%10 + '0');
                ind--;
                
            }
            
            if(length>ind)
                length=ind;
        }
        
        return string(&a[length+1],&a[nums1.length()+nums2.length()]);
    }
};