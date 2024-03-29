#include "binary_trees.h"

/**
 * Inserts a node as the right-child of another node - binary_tree_insert_right - 
 * @parent: Pointer to the parent node
 * @value: Integer stored in the new node
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (!parent)
        return (NULL);

    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    if (parent->right)
    {
        new_node->right = parent->right;
        new_node->right->parent = new_node;
    }
    parent->right = new_node;

    return (new_node);
}

