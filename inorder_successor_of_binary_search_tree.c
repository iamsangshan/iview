

/* algo 
 *
 *
 * if parent pointer
 *
 * case 1: root->right != NULL
 * 	find min(root->right) = successor
 *
 * case 2: root->right == NULL
 * 	find the nearest node which is the left child of its parent.
 * 	the parent is the successor
 *
 */

inorder_succ (node *inputnode) {
  node *parent;
  parent = inputnode->parent;

  while (parent && parent->left != node) {
	  node = parent;
	  parent = node->parent;
  }

  return parent;
 }



/* algo
 *
 *
 * if parent pointer is not there in structure of BST
 *
 *  case 1: root->right != NULL
 *      find min(root->right) = successor
 *
 *  case 2: find the closest parent for which the given node 
 *  	is part of the paretns left tree
 */

inorder_succ (node *inputnode) {

	node *ancestor, *successor;

	anc = root;
	succ = NULL;

	while (anc != inputnode) {
		if (anc->data > inputnode->data) {
			succ = anc;
			anc = anc->left;
		} else
			anc = anc->right;
	}

	return succ;
}
 
