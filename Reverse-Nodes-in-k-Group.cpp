/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       // Check if there are at least k nodes left in the linked list
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (node == NULL) {
                return head; // Not enough nodes to reverse, return head as is
            }
            node = node->next;
        }
        //step1:reverse first k nodes
        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode*prev=NULL;
        int count=0;

        while(curr!=NULL && count <k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;


        }
        //step2:Recursion dekhlega aage ka
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        //step3:Return head of reversed list
        return prev;
        
    }
};