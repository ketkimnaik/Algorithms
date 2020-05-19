Brute Force:


class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        int num=1;
        int level=0;
        vector<int> tree{};
        //tree[0]=1;
        tree.push_back(1);
        while(num<label)
        {
            int start=num;
            level++;
            num+=pow(2,level);
            
            int end=num;
            if(level%2 !=0)
            {
            for(int i=start;i<num;++i)
            {
                tree.push_back(end);
                end--;
            }
            }
            else
            {
               for(int i=start;i<num;++i)
            {
                   start++;
                tree.push_back(start);
                
            } 
            }
                
        }
        level+=1;
        
        //binaru search
        
        int index=0;
        int left=pow(2,level-1)-1;
        
        for(int i=left;i<left+pow(2,level-1);++i)
        {
            if(label==tree[i])
            {
                index=i;
                break;
            }
        }
        //cout<<left<<"   "<<right<<"\n";
        
        //cout<<index<<"  ";
        vector<int> result(level,0);
        while(level >0)
        {
            result[level-1]=tree[index];
            //cout<<result[level-1]<<"    ";
            level--;
            if(index%2==0)
                index=(index-2)/2;
            else
                index=(index-1)/2;
        }
        
        return result;
    }
};




Optimized Solution:
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
vector<int> res;
if(label==1)
return {1};
int level=log2(label);
        //cout<<level;
res.insert(res.begin(),label);
while(--level)
{
label=3*pow(2,level)-1-label/2;
    cout<<label<<"  ";
res.insert(res.begin(),label);
}
res.insert(res.begin(),1);
return res;
}
        
   
};