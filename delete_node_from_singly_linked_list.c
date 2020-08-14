/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* Algorithm 

  - have 3 pointers 
  - if head is pointing to the "node", then delete the head, and adjust to new head
  - else, check if next node is pointing to "node"
  - if yes, delete that node and adjust the pointers
  - if no, continue traversing
 */

void deleteNode(struct ListNode* node) {
    
    struct ListNode *p, *q, *r;
    
    p = list;
    q = p->next;
    
    if (head == node) {
        free (head);
        head = NULL;
        return;
    }
    
    while (q) {
        r = q->next;
        if (q == node){
            free(q);
            q = NULL;
            p->next = r;
        }
        p = q;
        q = r;
    }
    
}