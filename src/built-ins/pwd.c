#include "../../inc/executor.h"

void	ex_pwd(char *pwd_value)
{
	if (!pwd_value)
	{
		printf(Y "Error: pwd is corrupted" RE);
		return ;
	}
	printf("%s", pwd_value);
}
