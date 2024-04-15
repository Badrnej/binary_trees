#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or if the tree is not complete, return 0.
 *         Otherwise, return 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    const binary_tree_t *queue[1024];
    int start = 0, end = 0;
    int null_seen = 0;

    queue[end++] = tree;

    while (start < end)
    {
        const binary_tree_t *node = queue[start++];

        if (!node)
            null_seen = 1;
        else
        {
            if (null_seen)
                return (0);

            queue[end++] = node->left;
            queue[end++] = node->right;
        }
    }

    return (1);
}
