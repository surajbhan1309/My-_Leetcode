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
class Solution
{
public:
    // Function to reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;
        
        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    // Function to insert nodes at tail
    void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
        ListNode* temp = new ListNode(val);
        
        // If the list is already empty
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    ListNode* add(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode* ansHead = nullptr;
        ListNode* ansTail = nullptr;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = 0;
            if (l1 != nullptr) {
                val1 = l1->val;
            }
            
            int val2 = 0;
            if (l2 != nullptr) {
                val2 = l2->val;
            }
            
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            
            // Adding nodes to the result list
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        
        return ansHead;
    }
    
    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        
        // Step 1: Add the two reversed linked lists
        ListNode* ans = add(l1, l2);
        
        // Step 2: Reverse the result to get the final answer
        //ans = reverse(ans);
        
        
        
        return ans;
    }
};

