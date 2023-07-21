//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    node* rev2(node* head){
        node* p = nullptr, *c = head, *n = head->next;
        while(c!=nullptr){
            c->next = p;
            p = c;
            c = n;
            if(n!=nullptr){
                n = n->next;
            }
        }
        return p;
    }
    void rev(node* head, node* tail)
    {
        node* p = nullptr, *c = head, *n = head->next;
        while(p!=tail){
            c->next = p;
            p = c;
            c = n;
            if(n!=nullptr){
                n = n->next;
            }
        }
        // return p;
    }
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(k == 1) return head;
        node* dummy = new node(-1);
        dummy->next = head;
        
        node* before_start = dummy, *end = head;
        int count = 1;
        while(end!=nullptr){
            end = end->next;
            if(end != nullptr){
                count++;
            }
            
            if(count == k){
                node* start = before_start->next;
                node* next_end = end->next;
                rev(start, end);
                before_start->next = end;
                start->next = next_end;
                before_start = start;
                end = next_end;
                count = 1;
            }
        }
        
        if(count > 1){
            node* tmp = rev2(before_start->next);
            before_start->next = tmp;
            
        }
        return dummy->next;
    }
        
    
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends