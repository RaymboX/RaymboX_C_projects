#include "brc.h"
#include "var_extern.h"

void	ft_throw_dice(int qui)
{
	value[qui][1] = rand() % 6 + 1;
}

void	ft_bot_choice()
{
	int	chance;

	switch (value[0][0] - value[1][0])
	{
		case 1:
			chance = 95;
			break;
		case 2:
			chance = 90;
			break;
		case 3:
			chance = 85;
			break;
		case 4:
			chance = 30;
			break;
		case 5:
			chance = 5;
			break;
		case 6:
			chance = 1;
			break;
	}
	if (rand() % 100 < chance)
		input = 'm';
	else
		input = 'p';
}
