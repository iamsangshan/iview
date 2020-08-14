/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//############## TWO METHODS COVERED ###########

/* Algorithm
 
   1. Iterative method:
       - have 3 pointers a, b, c
       - starting from the head, traverse the linked list such that
         a, b, and c points the consecutive nodes
       - during each traversal, reverse a and b, i.e. assign b->next to a, 
         if a is head, point a->next to NULL
       - continue traversing the list using the next pointer 'c'
       - at the end, make the last node as 'head'
       - return the head
   */
       

/* 2. recursive method */

/*  Algorithm 
    - base case - less than 2 element or end of the list
    
      i.e. head == NULL || head->next == NULL
      
    - recursive case - go over the list till node->next = NULL
    
    - 1. the last node is head, carry that pointer from the top to the bottom of the stack
    
    - 2. during each stack, reverse the pointers 
 
 */

#if 0
struct ListNode* reverseList(struct ListNode* head){
    
    /* iterative */
    struct ListNode *a, *b, *c;
    
    if (head == NULL)
        return NULL;
    
    a = head;
    b = a->next;
    a->next = NULL;
    
    while (b != NULL) {
        /* save next pointer */
        c = b->next;
        /* reverse a and b */
        b->next = a;
        /* traverse further */
        a = b;
        b = c;
    }
    
    /* assign last node to head */
    return a;
}

#endif


/* recursion */

/* algorithm 

  - base case - less than 2 node , no need to reverse
     !head || !head->next
     
  - recursive case - call reverse till end of the list
  
  - 1. End node is the new head node. return it to the calling function
  
  - 2. Reverse the next pointer 
  


 1 -> 2 -> 3 -> 4 -> 5 -> NULL
     
     r1 - 1
     r2 - 2
     ...
     r5 - 5  (new head)
     
     node4->next->next = node4
     
     node4->next = NULL
     
*/


struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode *new_head;
    
    /* base case */
    if (!head || !head->next)
        return head;
    
    /* rec case */
    while (head->next) {
        /* carry the new_head from base case */
        new_head = reverseList(head->next);
        
        /* reverse the pointer */
        head->next->next = head;
        head->next = NULL;
    }
    
    /* exiting recursion to the actual caller */
    return new_head;
}
