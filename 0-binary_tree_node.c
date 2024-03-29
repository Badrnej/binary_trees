#include "binary_trees.h"
/**
 * create a binary tree node - binary_tree_node
 * @value:  in the node Integer stored
 * @parent: the parent node in Pointer
 * Return: the new node in Pointer
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)

{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	return (node);
}
