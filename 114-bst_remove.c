#include "binary_trees.h"

/**
 * inorder_successor - Finds the inorder successor of a node.
 * @node: A pointer to the root node of the tree to traverse.
 * Return: A pointer to the inorder successor.
 */
bst_t *inorder_successor(bst_t *node)
{
	if (!node)
		return (NULL);
	if (node->left)
		return (inorder_successor(node->left));
	return (node);
}

/**
 * delete - Deletes a node and succeeds it by successor.
 * @root: The root node of the tree.
 * @successor: The successor node.
 * Return: The address of the successor.
 */
bst_t *delete(bst_t *root, bst_t *successor)
{
	successor->parent = root->parent;
	free(root);
	root = NULL;
	return (successor);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: The root node of the BST.
 * @value: The value of the node to remove.
 * Return: A pointer to the new root node of the tree after removing the node.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	/* Found the element */
	else
	{
		/* No children */
		if (!root->left && !root->right)
			free(root), root = NULL;
		/* Right child */
		else if (!root->left)
			root = delete(root, root->right);
		/* Left child */
		else if (!root->right)
			root = delete(root, root->left);
		/* 2 children, find next successor using inorder_successor */
		else
		{
			bst_t *successor = NULL;

			successor = inorder_successor(root->right);
			root->n = successor->n;
			/* Recursive call to handle the "succession" process */
			root->right = bst_remove(root->right, successor->n);
		}
	}
	return (root);
}