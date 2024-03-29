#include "binary_trees.h"
/*
 * binary_tree_insert_left - Insert a node as the left child of another node
 *
 * This function inserts a new node with the given value as the left child of
 * the parent node. If the parent already has a left child, the new node takes
 * its place and the previous left child becomes the left child of the new node.
 *
 * @parent : A pointer to the parent node.
 * @value : The value to store in the new node.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	if (parent->left)
	{
		parent->left->parent = node;
		node->left = parent->left;
	}
	parent->left = node;

	return (node);
}
