#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parse_args(char *line) //Ex: "ls -a -f"
{
	char **return_args = malloc(6 * sizeof(char *)); //Five args plus ending NULL
	char *s, *b;
	s = line;

	int i = 0;
	while (s)
	{
		//printf("RUN\n");
		//printf("%s\n",s);
		return_args[i] = strsep(&s, " ");
		//printf("%s\n",return_args[i]);
		i++;
		//printf("strlen: %d\n",strlen(s));
		//printf("END\n");
	}

	return return_args;
}

int main()
{
	char line[] = "ls -a -l -F -h";
	char **args = parse_args(line);
	execvp(args[0], args);

	return 0;
}