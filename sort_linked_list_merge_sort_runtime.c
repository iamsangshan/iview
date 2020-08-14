/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/* Merge sort */


/* Algorithm  (Divide and Conquer)

  - base case: less than 2 nodes i.e. !head || !head->next

  - recursive case: split the list into 2 equal halves and call merge_sort recursively till     the base case is hit 
    (till there is 1 node)
  
  - after recursion: merge the 2 sorted small list into 1 big list
  
  Note: use 1 slow pointer and 1 fast pointer to split the list into 2.
  
   
   9 -> 3 -> 8 -> 4 -> 1 -> 5->NULL
   
     9 3 8               4 1 5
   
   9 3    8         4 1          5
   
 9     3          4      1
   
   
    leftlist      rightlist   merged_sorted_list
       3            1               1
       8            4               3
       9            5               4
                                    5
                                    8
   
  
  
 */


struct ListNode* merge_the_two_lists (struct ListNode *leftlist, struct ListNode*rightlist);
void split_list_into_two (struct ListNode* head, struct ListNode **leftlist, struct ListNode **rightlist);
void merge_sort(struct ListNode** head);


struct ListNode* sortList(struct ListNode* head){
    
   
    
    merge_sort(&head);
    
    return head;

}



void merge_sort(struct ListNode** headref){
    
     struct ListNode *a, *b, *new_head, *head;
    
     head = *headref;
        
     
     /* base case */
     if (!head || !(head->next))
         return head;
    
     /* split the list into two */
     split_list_into_two(head, &a, &b);
    
    
      merge_sort(a);
    
      merge_sort (b);
    
      /* exit */
      new_head = merge_the_two_lists(a, b);
    
    *headref = new_head;
    
}


void split_list_into_two (struct ListNode* head, struct ListNode **leftlist, struct ListNode **rightlist){
    
    /* slow and fast pointer method */
    
    struct ListNode *slow, *fast;
    
    if (!head || !head->next) {
        *leftlist = head;
        *rightlist = NULL;
        
        return;
    }
        
    
    slow = head;
    fast = slow->next;
    
    while (fast) {
       fast = fast->next;
       if (fast) {
           fast = fast->next;
           slow = slow ->next;
       }
    } 
    
    /* slow->next will be at the middle of the list */
    *leftlist = head; /* mark the start  of the left list */
    *rightlist = slow->next; /* mark the start of the right list */
    slow->next = NULL; /* mark the end of the left list */
}

struct ListNode* merge_the_two_lists (struct ListNode *leftlist1, struct ListNode *rightlist1){
 
    struct ListNode *leftlist, *rightlist, *merged_list, *new_head, *temp;
    leftlist = leftlist1;
    rightlist = rightlist1;
    merged_list = NULL;
    new_head = NULL;
        
    
    if (!leftlist)
        return rightlist;
    if (!rightlist)
        return leftlist;
    
    while(leftlist && rightlist) {
        
        if (leftlist->val < rightlist->val) {
            /* put leftlist content to new list and increment leftlist alone */
            if (!merged_list) {
                merged_list = leftlist;
            } else {
                merged_list->next = leftlist;
                merged_list = merged_list->next;
            }
            
            leftlist = leftlist->next;
        }
        
        if (rightlist->val < leftlist->val) {
            if (!merged_list) {
                merged_list = rightlist;
            } else {
                merged_list->next = rightlist;
                merged_list = merged_list->next;
            }
            rightlist = rightlist->next;
        }
        else { /* both values equal, choose arbitrarily to copy data and skip both lists */
            
            if (!merged_list) {
                merged_list = leftlist;
            } else {
                merged_list->next = leftlist;
                merged_list = merged_list->next;
            }
            
            leftlist = leftlist->next;
            rightlist = rightlist->next;
        }
        
        if (!new_head)
            new_head = merged_list;
    }
    
    
    if (!leftlist && !rightlist)
        return new_head;
    
    if (!leftlist)
        merged_list->next = rightlist;
    else
        merged_list->next = leftlist;
    
    
    
    return new_head;
    
}