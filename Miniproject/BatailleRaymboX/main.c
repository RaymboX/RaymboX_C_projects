#include "brc.h"

int	main()
{
	char	menu_ret = '0';
	char	base[] = "123456789XJQKZZ";
	
	srand(time(NULL));	
	ft_reset_alldeck();
	ft_gamenameclear();
	while (menu_ret != 'q')	
	{
		menu_ret = ft_menu();	
		//menu_ret = 1;
		switch (menu_ret)
		{
			case '1'://new game
				ft_newgame(base);
				ft_gameloop();
				break;
			case '2'://load_delete saved game
				deload_menu();
				break;
			case '3'://continue
				sit = START;
				ft_gameloop();
				break;
			case '4'://new save
				ft_save_new();
				break;
			case '5'://save
				break;
			case 'r'://rules
				ft_reglement_show();
				break;
		}
	}
	ft_clear_screen(50);
}


void	ft_gameloop()
{
	while (sit != MENU)
		ft_sit_action();
}

void	ft_gamenameclear()
{
	int	i = -1;

	while (++i < 20)
		gamename[i] = '\0';
}
