/ Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */


 /* Algorithm:

    - create a node for the data
    - if the list is null, then make this node as head
    - else, traverse through the list to find the position to insert

 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {

    DoublyLinkedListNode *new_node, *node;

    node = head;

    /* init the new node */
    new_node = (DoublyLinkedListNode*) malloc(sizeof(DoublyLinkedListNode));
    new_node->data = data;
    new_node->next = new_node->prev = NULL;

    /* if list is empty */
    if (!head) {
        head = new_node;
    } else {

        for(node = head; node && node->next && node->next->data < data; node = node->next);
        
        /* we found the place which is larger node */
        if (node) {
            new_node->next = node->next;
            new_node->prev = node;
            node->next = new_node;
            if (node->next)
                node->next->prev = new_node;
        }


    }


return head;
}
