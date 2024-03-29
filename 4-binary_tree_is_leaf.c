#include "binary_trees.h"
/**
 *  determines if a node is a leaf node
 * @node: node to test.
 * Return: 1 if leaf node, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left || node->right)
		return (0);
	return (1);

}
