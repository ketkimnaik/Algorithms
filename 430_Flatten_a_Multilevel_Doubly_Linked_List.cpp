/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head, Node* Next = nullptr) {
        Node* temp = head;
        
        while(temp) {
            if(temp->child) {
                temp->child->prev = temp;
                temp->next = flatten(temp->child, temp->next);
                temp->child = NULL;
            }
            
            if(temp->next == NULL) {
                temp->next = Next;
                if(Next) {
                    Next->prev = temp;
                }
                return head;
            }
            
            temp = temp->next;
        }
        
        return head;
    }
};