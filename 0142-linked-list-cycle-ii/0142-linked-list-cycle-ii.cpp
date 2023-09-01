/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *>s;
        ListNode* temp=head;
        int i=-1;
        while(temp!=NULL){
            if(s.find(temp)!=s.end())
                return temp;
            s.insert(temp);
            temp=temp->next;
            i++;
        }
        return temp;
    }
};