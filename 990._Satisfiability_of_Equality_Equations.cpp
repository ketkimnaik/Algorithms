class Solution {
public:
    int find(int x, vector<int>& parent)
    {
        if(x == parent[x])
            return x;
        else
            return parent[x] = find(parent[x],parent);
    }
    bool equationsPossible(vector<string>& equations) 
    {
        int n = equations.size();
        vector<int>parent(26,0), size(26,1);
        for(int i = 0 ; i < 26 ; i++)
            parent[i] = i;
        for(int i = 0 ; i < n ; i++)
        {
            if(equations[i][1] == '=')
            {
                int a = find(equations[i][0] - 'a',parent);
                int b = find(equations[i][3] - 'a',parent);
                if(a != b)
                {
                    if(size[a] < size[b])
                        swap(a,b);
                    parent[b] = a;
                    size[a] += size[b];
                }
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(equations[i][1] == '!')
            {
                int a = find(equations[i][0] - 'a',parent);
                int b = find(equations[i][3] - 'a',parent);
                if(a == b)
                    return false;
            }
        }
        return true;
    }
};