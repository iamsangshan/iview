/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*

L1 = 1 2 3 4 -

		       5 6 7 8 -> NULL

L2 = 5 3 4 -

method 1: brute force - iterative

- start from head of L1 l1n1, this will be the outer loop  (O (n))

- compare l1n1 with all nodes in l2 - l2n1, l2n2, ..... (inner loop)  (O(m))

- if equal, merge point found

- else, move to l1n2

- while (l1 && l2) loop


o(mn)


method 2: leveraging simple compare
============

L1 = 1 2 3 4 -

		       5 6 7 8 -> NULL

L2 = 5 3 4 -

 - when two lists are equal length we can do simple 
   compare by traversing and comparing each node in L1 and L2
 - find len (L1) - len (L2) ==> 1   n + m
 - check if l1 > l2 viceversa
 - traverse the longer list by 1 position  n
 - now just do the simple compare
 
 o(n)
 
method 3: Clever trick
===========

L1 = 1 2 3 4 -

		       5 6 7 8 -> NULL

L2 = 5 3 4 -
 
 
 - traverse L1 and L2 till the end  (n + m )
 - once we reach end of L1, traverse L2
 - once we reach end of L2, traverse L1
 - at some point, we will either be at the end of both the lists simultaneously 
   because len(L1+L2) = len(L2+L1)
   or we will be at merge point
   
   note: start with simple search

 
 1 2 3 4 5 6 7 8 -> 5 3 4 5 6 7 8 -> NULL
 5 3 4 5 6 7 8 -> 1 2 3 4 5 6 7 8 -> NULL

 o(n)

*/


#if 0
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    struct ListNode *a, *b;
    
    a = headA;
    b = headB;
    
    if (!a || !b)
        return NULL;
    
    /* make trains off each other */
    while (a) {
        a = a->next;
    }
    a = headB;
    
    while (b) {
        b = b->next;
    }
    b = headA;
    
    
    /* now both lists are of equal length, simple compare */
   

    while (a && b && a != b) {
 
         {
            if (a)
                a = a->next;
            if (b)
                b = b->next;
        }
    }
    
    return a;
}

#endif


/* correct and simple solution */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    struct ListNode *a, *b;
    
    a = headA;
    b = headB;
    
    if (!a || !b)
        return NULL;
    
    while (a != b) {
        if (a)
            a = a->next;
        else
            a = headB;

        if (b)
            b = b->next;
        else
            b = headA;
    }
    
    return a;
}

