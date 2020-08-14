/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 /* ALGORITHM
 
 RECURSIVE
 

 - base case -> if data is node->data then return true
 
 - rec case -> traverse through the list till we reach end
 
 - exit - if we found then return the node
 
  1 - 2 - 3 - 4 - 5 - 6 - NULL
 
 
 */
 
/* search for an element recursively */

struct ListNode* searchLinkedListRecursive(struct ListNode* head, int data){

	struct ListNode* root;
	
	root = head;
	
	if (root == NULL)
		return false;
		
	if (root->val == data)
		return true;
	
	return searchLinkedListRecursive(root->next, data);


}