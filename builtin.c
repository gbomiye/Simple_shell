#include "shell.h"

/**
 * This function is used to exit the shell.
 * @info: Structure containing potential arguments.
 * Return: Exits with a given exit status (0) if info->argv[0] != "exit".
 * 
 */
int exitShell(info_t *info)
{
	int check;

	if (info->argv[1]) /* If there is an exit argument */
	{
		check = convertToInteger(info->argv[1]);
		if (check == -1)
		{
			info->status = 2;
			printErrorMessage(info, "Illegal number: ");
			printString(info->argv[1]);
			printCharacter('\n');
			return (1);
		}
		info->errorNumber = convertToInteger(info->argv[1]);
		return (-2);
	}
	info->errorNumber = -1;
	return (-2);
}

/**
 * _mycd - changes the current dir of process
 * @info: Struct contain potential arguments,used to maintain constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info)

{
	char *s, buffer[1024];
	char *directory
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		directory = _getenv(info, "HOME=");
		if (!directory)
			chdir_ret = /* TODO: what should this be? */
				chdir((directory = _getenv(info, "PWD=")) ? directory : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((directory = _getenv(info, "OLDPWD=")) ? directory : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp – to change the current dir of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **argarr;

	argarr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argarr); /* temp att_unused workaround */
	return (0);
}
