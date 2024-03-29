#include "binary_trees.h"

/**
 * balance_tree - Balances an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 */
void balance_tree(avl_t **tree)
{
	int balance_factor;

	if (!tree || !*tree)
		return;

	balance_tree(&(*tree)->left);
	balance_tree(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - Finds the in-order successor in a binary search tree.
 * @node: Pointer to the root node of the tree to search.
 * Return: The value of the in-order successor.
 */
int find_successor(bst_t *node)
{
	int left = 0;

	if (!node)
		return (0);

	left = find_successor(node->left);

	if (left == 0)
		return (node->n);

	return (left);
}

/**
 * remove_node - Removes a node from a binary search tree.
 * @root: Pointer to the node to remove.
 * Return: 0 if the node has no children, otherwise the value of the new node.
 */
int remove_node(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if (!root->left || !root->right)
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;

			root->right->parent = root->parent;
		}
		else
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;

			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = find_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: Pointer to the root node of the tree to remove a node from.
 * @value: Value of the node to remove.
 * Return: Pointer to the new root node of the tree after removing.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (!root)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node(root);
		if (type != 0)
			bst_remove(root->right, type);
	}

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the tree to remove a node from.
 * @value: Value of the node to remove.
 * Return: Pointer to the new root node of the tree after removing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (!root_a)
		return (NULL);

	balance_tree(&root_a);

	return (root_a);
}