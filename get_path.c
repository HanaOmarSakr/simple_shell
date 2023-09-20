#include "main.h"

/**
 * get_path - returns true if shell is interactive mode
 * @command: struct address
 * Return: ...........
 */


char *get_path(char *command)
{
	char *path, *path_copy, *token_path, *file_path;
	int command_len = _strlen(command);
	int directory_len, check;
	struct stat buffer;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = strdup(path);
	token_path = strtok(path_copy, ":");
	while (token_path != NULL)
	{
		directory_len = _strlen(token_path);
		file_path = malloc(command_len + directory_len + 2);
		_strcpy(file_path, token_path);
		_strcat(file_path, "/");
		_strcat(file_path, command);
		_strcat(file_path, "\0");
		check = stat(file_path, &buffer);
		if (check == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			token_path = strtok(NULL, ":");
		}
	}
	free(path_copy);
	check = stat(command, &buffer);
	if (check == 0)
		return (command);
	return (NULL);
}
