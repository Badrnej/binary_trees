#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST.
 * @value: The value to insert.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent = NULL, *current = NULL, *new_node = NULL;

	if (!tree)
		return (NULL);

	current = *tree;

	/* Find the parent node where the new node should be inserted */
	while (current)
	{
		parent = current;
		if (value == current->n)
			return (NULL); /* Value already exists in the tree */
		else if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	/* Create and insert the new node */
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent) /* If the tree was empty, new_node becomes the root */
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}