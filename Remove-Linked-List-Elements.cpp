class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to the head of the list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize two pointers: previous and current
        ListNode* prev = dummy;
        ListNode* current = head;

        // Traverse the linked list
        while (current != NULL) {
            if (current->val == val) {
                // If the current node's value matches `val`, remove it
                prev->next = current->next;
                // Store the next node before deletion
                ListNode* toDelete = current;
                current = current->next; // Move current pointer forward before deletion
                // Delete the node to free memory
                delete toDelete;
            } else {
                // Otherwise, move both pointers forward
                prev = current;
                current = current->next;
            }
        }
        
        // Return the new head of the list (dummy->next)
        return dummy->next;
    }
};
