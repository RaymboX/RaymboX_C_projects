#include "brc.h"
#include "var_extern.h"

void	ft_endgame()
{
	int	speed = 100000;
	int	hauteur = 20;
	int	i = 45;

	while (i-- > hauteur)
	{
		ft_clear_screen(hauteur + (hauteur - i));
		ft_print_letter55("YOU", 20);
		ft_clear_screen(2);
		if (sit == YOU_WINGAME)
			ft_print_letter55("WIN", 20);
		else
			ft_print_letter55("LOST", 20);
		ft_clear_screen(i);	
		usleep (speed);
	}
	sleep (3);
	ft_gamenameclear();
	ft_reset_alldeck();
}
