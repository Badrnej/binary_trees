#include "binary_trees.h"

/**
 * bst_inorder - Vérifie si un arbre est un BST en effectuant un parcours inordre.
 * @tree: Un pointeur vers le nœud racine de l'arbre.
 * @prev: Un pointeur vers le nœud précédent dans l'ordre inordre.
 *
 * Return: 1 si l'arbre est un BST, 0 sinon.
 */
int bst_inorder(const binary_tree_t *tree, const binary_tree_t **prev)
{
	if (!tree)
		return (1);

	/* Vérifie le sous-arbre gauche */
	if (!bst_inorder(tree->left, prev))
		return (0);

	/* Vérifie si le nœud courant est plus grand ou égal au précédent */
	if (*prev && tree->n <= (*prev)->n)
		return (0);

	*prev = tree;

	/* Vérifie le sous-arbre droit */
	return (bst_inorder(tree->right, prev));
}

/**
 * binary_tree_is_bst - Vérifie si un arbre binaire est un BST.
 * @tree: Le nœud racine de l'arbre à vérifier.
 *
 * Return: 1 si l'arbre est un BST, 0 sinon.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *prev = NULL;

	if (!tree)
		return (0);

	/* Appel récursif à bst_inorder pour vérifier si c'est un BST */
	return (bst_inorder(tree, &prev));
}