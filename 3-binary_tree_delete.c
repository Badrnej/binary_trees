#include "binary_trees.h"
/**
 * deletes an entire binary_tree
 * @tree: root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	if (tree->left)
		binary_tree_delete(tree->left);
	if (tree->right)
		binary_tree_delete(tree->right);
	if (tree)
		free(tree);

}
