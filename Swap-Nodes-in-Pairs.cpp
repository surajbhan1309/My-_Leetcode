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
    ListNode* swapPairs(ListNode* head) {
    ListNode* dummy=new ListNode();
    dummy->next=head;
    ListNode* node=dummy;

    while(node!=NULL){
        ListNode*prev=node->next;
        ListNode*curr=NULL;
        if(prev!=NULL){
            curr=prev->next;
        }
        if(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            node->next=curr;
            prev->next=forward;
            node=prev;
        }
        else{
            break;
        }
    }
    return dummy->next;
    }
};