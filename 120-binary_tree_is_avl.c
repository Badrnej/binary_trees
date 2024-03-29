/**
 * check_balance - Vérifie si un arbre binaire est équilibré
 * @tree: Pointeur vers le nœud racine de l'arbre à vérifier
 * @height: Pointeur vers la variable de hauteur
 * Return: 1 si l'arbre est équilibré, et 0 sinon
 */
int check_balance(const binary_tree_t *tree, int *height)
{
    int left_height = 0, right_height = 0;

    if (!tree)
    {
        *height = 0;
        return (1);
    }

    if (!check_balance(tree->left, &left_height) ||
        !check_balance(tree->right, &right_height))
        return (0);

    *height = MAX(left_height, right_height) + 1;

    if (ABS(left_height - right_height) > 1)
        return (0);

    return (1);
}

/**
 * binary_tree_is_avl - Vérifie si un arbre binaire est un AVL valide
 * @tree: Pointeur vers le nœud racine de l'arbre à vérifier
 * Return: 1 si l'arbre est un AVL valide, et 0 sinon
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height;

    if (!tree)
        return (0);

    // Vérifie l'équilibre de l'arbre
    if (!check_balance(tree, &height))
        return (0);

    // Vérifie si l'arbre est un BST
    if (!binary_tree_is_bst(tree))
        return (0);

    return (1);
}