/**
 * heap_extract - Extracts the root node and returns its value.
 * @root: Double pointer to the root node of the heap.
 * Return: Value of the extracted node.
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *temp;
	int value;

	if (!root || !(*root))
		return (0);

	value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last_node = find_last_level_node(*root);
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	temp = *root;
	(*root) = last_node;
	(*root)->left = temp->left;
	(*root)->right = temp->right;
	if (temp->left)
		temp->left->parent = (*root);
	if (temp->right)
		temp->right->parent = (*root);
	free(temp);

	sift_down(*root);
	return (value);
}