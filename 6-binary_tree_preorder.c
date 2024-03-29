#include "binary_trees.h"
/**
 * binary_tree_preorder - traverse a binary tree using pre-order traversal.
 * 
 * @func: pointer to a function to call for each node.
 * 
 * @tree: pointer to root node of the tree to traverse.
 * 
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	if (tree->left)
		binary_tree_preorder(tree->left, func);
	if (tree->right)
		binary_tree_preorder(tree->right, func);

}
