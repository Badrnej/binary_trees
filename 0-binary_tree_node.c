#include "binary_trees.h"
/**
 * binary_tree_node - create a binary tree node
 * @value: Integer stored in the node
 * 
 * @parent: Pointer to the parent node
 * 
 * Return: Pointer to the new node
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
