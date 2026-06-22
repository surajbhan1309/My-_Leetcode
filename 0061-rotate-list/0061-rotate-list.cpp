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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* curr=head;

        //find length of LL
        int len=1;
        while(curr->next){
            curr=curr->next;
            len++;
        }
        k=k%len;
        curr->next=head;
        curr=head;
        for(int i=0;i<len-k-1;i++){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;



        
    }
};