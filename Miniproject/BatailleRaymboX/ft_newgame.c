#include "brc.h"
#include "var_extern.h"

void	ft_newgame(char *base)
{
	char	jeu[55];
	int	i = 0;
	int	irnd;

	ft_jeu_fill(jeu, base);
	//printf("\n%s\n", jeu);
	ft_reset_alldeck();
	while (i < 54)
	{
		irnd = rand() % 54;
		if (jeu[irnd] != '_')
		{
			deck[i % 2][0][i / 2] = jeu[irnd];
			jeu[irnd] = '_';
			i++;
		}
	}
	
	value[0][0] = 0;
	value[0][1] = 0;
	value[1][0] = 0;
	value[1][1] = 0;
	ft_gamenameclear();
	sit = START;
//	printf("\ndeck0: %s\n", deck[0][0]);	
//	printf("\ndeck1: %s\n", deck[1][0]);
}
	


void	ft_jeu_fill(char *jeu, char *base)
{
	int	ijeu = 0;
	int	ibase = 0;
	int	nbcard;

	while (ibase < 15)
	{
		if (ibase < 13)
			nbcard = 4;
		else
			nbcard = 1;
		while (nbcard != 0)
		{
			jeu[ijeu] = base[ibase];
			nbcard--;
			ijeu++;
		}
		ibase++;
	}
	jeu[ijeu] = '\0';
}

void	ft_reset_deck(int i1, int i2)
{
	int	i = -1;

	while (++i < 55)
		deck[i1][i2][i] = '\0';
}

void	ft_reset_alldeck()
{
	int	i1 = -1;
	int	i2;

	while (++i1 < 2)
	{
		i2 = -1;
		while (++i2 < 3)
			ft_reset_deck(i1, i2);
	}
}
