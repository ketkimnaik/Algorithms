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
    vector<int> postorder(Node* root) {
        if(! root)
            return {};
        
        stack<Node*> s1, s2;
        vector<int> result{};
        s1.push(root);
        
        while(! s1.empty()){
            Node *node = s1.top();
            s1.pop();
            s2.push(node);
            for(int i = 0; i < (node->children).size(); ++i){
                s1.push(node->children[i]);
            }
        }
        
        while(! s2.empty()){
            result.push_back((s2.top())->val);
            s2.pop();
        }
        
        return result;
    }
};