void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j, width;

	if (!tree)
		return;
	height = _height(tree);
	width = 1 << (height + 2); /* 2^(height + 2) */

	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * width);
		if (!s[i])
			return;
		memset(s[i], ' ', width - 1);
		s[i][width - 1] = '\0';
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = width - 2; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}