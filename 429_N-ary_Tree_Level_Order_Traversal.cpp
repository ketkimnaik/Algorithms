/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(! root)
            return {};
        vector<vector<int>> result{};
        queue<Node*> q;
        q.push(root);
        int u = q.size();
        vector<int> temp{};
        while(! q.empty()){
            temp = {};
            
            while(u > 0){
                u--;
                temp.push_back(q.front()->val);
                
                for(int i = 0; i < (q.front()->children).size(); ++i)
                    q.push(q.front()->children[i]);
                
                q.pop();
            }
            
            result.push_back(temp);
            u = q.size();
        }
        
        return result;
    }
};