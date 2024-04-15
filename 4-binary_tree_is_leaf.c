#include "binary_trees.h"
/**
 * binary_tree_is_leaf - determines if a node is a leaf node
 * 
 * @node: node to test.
 * 
 * Return: 1 if leaf node, 0 otherwise.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	return (0);
}
