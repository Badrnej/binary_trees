#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree. 
 * @tree: pointer to node in the tree to measure its depth.
 * Return: depth of tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
	{
		return (0);
	}

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
