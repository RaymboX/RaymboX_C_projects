#include "brc.h"
#include "var_extern.h"

char	ft_cardsit_check()
{
	int	deckcount[2][4];
	char	ret = input;
	int	i = -1;
	
	ft_deckcount(deckcount);
	while (++i < 2)
	{
		if (deckcount[i][0] == 0)//plus de carte dans le deck
		{
			if (deckcount[i][2] > 0 && !(sit == BAT_BOTBETALL && i == 0)
					&& !(sit == BAT_YOUBETALL && i == 1))//si carte dans le depot
				ret = 'b';//brasse les cartes
			else
			{
				if (sit == BATAILLE)//si carte dans la mise
					ret = 'c';//bataille plus de carte
				else
				{
					if (deckcount[i][1] > 0)//si carte en jeu
					{
						if ((i == 0 && value[0][0] < value[1][0]) 
								|| (i == 1 && value[0][0] > value[1][0]))	
							ret = 'n';//NOTRY
					}
					else//si pas de carte en jeu
						ret = 'w';//WIN OR LOSE
				}
			}
		}
		if (ret != input)
		{
			if (i == 1)
				return (ret - ('a' - 'A'));
			else
				return (ret);
		}
	}	
	return (ret);
}

void	ft_deckcount(int deckcount[2][4])
{
	int	i = -1;
	
	while (++i < 2)
	{

		deckcount[i][0] = ft_strlen(deck[i][0], 0);
		if (deck[i][1][0] != '\0')
			deckcount[i][1] = 1;
		else
			deckcount[i][1] = 0;
		deckcount[i][2] = ft_strlen(deck[i][2], 0);
		deckcount[i][3] = ft_strlen(deck[i][1], 1);
	}
}

void	ft_brasse(int qui)
{
	int	i = 0;
	int	nbcard;
	int	irnd;

	nbcard = ft_strlen(deck[qui][2], 0);
	srand(time(NULL));
	
	while (i < nbcard)
	{
		irnd = rand() % nbcard;
		if (deck[qui][2][irnd] != '\0')
		{
			deck[qui][0][i] = deck[qui][2][irnd];
			deck[qui][2][irnd] = '\0';
			i++;
		}
	}
}
