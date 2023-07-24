#include "shell.h"

/**
 * display_history - Displays the history list, one command per line, starting at index 0.
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int display_history(info_t *info)
{
	print_list(info->history);
	return 0;
}

/**
 * remove_alias - Removes an alias from the alias list.
 * @info: Parameter structure
 * @str: The string representing the alias
 * Return: Always 0 on success, else 1 on error
 */
int remove_alias(info_t *info, char *str)
{
	char *equal_sign;
	char temp;
	int return_value;

	equal_sign = _strchr(str, '=');
	if (!equal_sign)
		return 1;
	temp = *equal_sign;
	*equal_sign = 0;
	return_value = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*equal_sign = temp;
	return return_value;
}

/**
 * This function sets an alias for a given string.
 * 
 * @param info A struct containing information about the alias
 * @param str The string alias to be set
 * 
 * @return 0 on success, 1 on error
 */
int setAlias(info_t *info, char *str)
{
    char *p;

    p = findCharacter(str, '=');
    if (!p)
        return (1);
    if (!*++p)
        return (unsetAlias(info, str));

    unsetAlias(info, str);
    return (addNodeEnd(&(info->alias), str, 0) == NULL);
}

/**
 * This function prints an alias string.
 * 
 * @param node The node containing the alias
 * 
 * @return 0 on success, 1 on error
 */
int printAlias(list_t *node)
{
    char *p = NULL, *a = NULL;

    if (node)
    {
        p = findCharacter(node->str, '=');
        for (a = node->str; a <= p; a++)
            printCharacter(*a);
        printCharacter('\'');
        printString(p + 1);
        printString("'\n");
        return (0);
    }
    return (1);
}

/**
 * This function mimics the alias builtin (man alias).
 * 
 * @param info A struct containing potential arguments
 * 
 * @return Always 0
 */
int myAlias(info_t *info)
{
    int i = 0;
    char *r = NULL;
    list_t *node = NULL;

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            printAlias(node);
            node = node->next;
        }
        return (0);
    }
    for (i = 1; info->argv[i]; i++)
    {
        r = findCharacter(info->argv[i], '=');
        if (r)
            setAlias(info, info->argv[i]);
        else
            printAlias(nodeStartsWith(info->alias, info->argv[i], '='));
    }

    return (0);
}

