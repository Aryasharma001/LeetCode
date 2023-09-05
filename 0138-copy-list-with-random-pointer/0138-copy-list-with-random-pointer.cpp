/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        Node* iter=head;
        Node* next;
        
        // round 1: copy the nodes and connect them side by side to original linked List;
        while(iter!=NULL){
            next=iter->next;
            Node*copy= new Node(iter->val);
            iter->next=copy;
            copy->next=next;
            
            iter=next;
        }
        // Round 2: assign the random nodes 
        
        iter=head;
        while(iter){
            if(iter->random){
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        // third round extract the original list and return the copy list
        
        iter=head;
        Node* pseudohead=new Node(0);
        Node* copy;
        Node* copyIter=pseudohead;
        
        while(iter){
            next=iter->next->next;
            copy=iter->next;
            copyIter->next=copy;
            copyIter=copy;
            
            iter->next=next;
            
            iter=next;
        }
        
        return pseudohead->next;
        
    }
};