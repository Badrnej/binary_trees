#include "binary_trees.h"

/**
 * heap_is_complete - Vérifie si un arbre de tas est complet.
 * @tree: Un pointeur vers le nœud racine de l'arbre à vérifier.
 *
 * Retourne : Si l'arbre est NULL ou s'il n'est pas complet, retourne 0.
 *            Sinon, retourne 1.
 */
int heap_is_complete(const binary_tree_t *tree)
{
    int start = 0, end = 0;
    const binary_tree_t *queue[1024];

    if (!tree)
        return (0);

    queue[end++] = tree;

    while (start < end)
    {
        const binary_tree_t *node = queue[start++];

        if (!node)
        {
            while (start < end)
            {
                if (queue[start++])
                    return (0);
            }
        }
        else
        {
            queue[end++] = node->left;
            queue[end++] = node->right;
        }
    }

    return (1);
}

/**
 * bst_inorder_max - Fonction auxiliaire pour parcourir un BST en utilisant
 *                   un parcours in-ordre et déterminer s'il s'agit d'un tas max.
 * @tree: Pointeur vers le nœud racine de l'arbre à parcourir.
 * @prev: Pointeur vers le nœud que nous utiliserons pour vérifier récursivement.
 * Retourne : 1 si c'est un tas max, 0 sinon.
 */
int bst_inorder_max(const binary_tree_t *tree, const binary_tree_t *prev)
{
    if (tree)
    {
        if (prev && tree->n >= prev->n)
            return (0);

        if (tree->right && !tree->left)
            return (0);

        return (bst_inorder_max(tree->left, tree) &&
                bst_inorder_max(tree->right, tree));
    }

    return (1);
}

/**
 * binary_tree_is_heap - Vérifie si un arbre binaire est un tas max valide.
 * @tree: Racine de l'arbre à vérifier.
 * Retourne : 1 si l'arbre est un tas max valide, 0 sinon.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (bst_inorder_max(tree, NULL) && heap_is_complete(tree));
}

