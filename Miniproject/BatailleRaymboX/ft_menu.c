#include "brc.h"
#include "var_extern.h"

char	ft_menu()
{
	int	valid;
	int	condition;

	if (ft_outcard_count() == 54)
		condition = 0;
	else if (gamename[0] != '\0')
		condition = 2;
	else
		condition = 1;
	valid = 1;
	while (valid)
	{
		ft_add_empty_line(50);
		ft_titre();
		ft_add_empty_line(5);
		ft_menu_command(condition);
		//ft_add_empty_line(5);
		if (valid == 2)
			write (1, "BAD ENTRY! TRY AGAIN OR JUST PRESS q AND ENTER\n", 47); 
		read(0, &input, 1);
		ft_clear_xtra_input();
		valid = 0;
		if ((input >= '0' && input <= '2') || input == 'r' || input == 'q'
				|| (condition > 0 && input >= '3' && input <= '4')
				|| (condition == 2 && input == '5'))
			return (input);
		else
			valid == 2;
	}	
}
	
void	ft_menu_command(int condition)
{
	int	i = 0;
	int	fd;

	while (i < 7)
	{
		ft_add_space(10);
		if (i == 0)
			write (1, "1 : NEW GAME", 12);
		if (i == 1)
			write (1, "2 : LOAD / DELETE SAVED GAME", 22);
		if (i == 2 && condition > 0)
			write (1, "3 : CONTINUE", 13);
		if (i == 3 && condition > 0)
			write (1, "4 : NEW SAVE", 12);
	       	if (i == 4 && condition == 2)
			write (1, "5 : SAVE", 8);
		if (i == 5)	
			write (1, "r : REGLEMENTS", 14);
		if (i == 6)
			write (1, "q : QUIT", 8);
		ft_add_empty_line(2);
		i++;
	}
}




void	ft_add_empty_line(int nbline)
{
	int	i = -1;
	while (++i < nbline)
		write (1, "\n", 1);
}

void	ft_add_space(int nbspace)
{
	while (nbspace-- > 0)
		write(1, " ", 1);
}

void	ft_titre()
{
	char	LINE1[] = "BATAILLE";
	char	LINE2[] = "RAYMBOX";
	char	LINE3[] = "C";

	ft_print_letter55(LINE1, 10);
	write (1, "\n\n", 2);
	ft_print_letter55(LINE2, 10);
	write (1, "\n\n", 2);
	ft_print_letter55(LINE3, 10);
}

