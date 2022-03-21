#include "brc.h"
#include "var_extern.h"

void	ft_sit_commandline(char commandline[26])
{
	switch (sit)
	{
		case START:
			ft_strcpy_command(
					"enter: PLAY  m: MENU",
					commandline);
			break;
		case B1TO6:
			ft_strcpy_command(
					"m: MISE + DE  p: PASS",
					commandline);
			break;
		case BATAILLE_BET:
			ft_strcpy_command(
					"enter: MISE + DE",
					commandline);
			break;
		case BOT_SUCCEED: case BOT_FAIL: case YOU_RETRY:
			ft_strcpy_command(
					"enter: LANCE LE DE",
					commandline);
			break;
		case BAT_YOUBETALL:
			ft_strcpy_command(
					"enter: MISE POUR LES 2 + DE",
					commandline);
			break;
		//case YOU_NOTRY:
		//	ft_strcpy_command(
		//			"p: PASS",
		//			commandline);
		//	break;
		default:
			ft_strcpy_command(
					"enter: next",
					commandline);
			break;
	}
}

void	ft_strcpy_command(char command[26], char *commandline)
{
	ft_strcpy(command, commandline);
}

