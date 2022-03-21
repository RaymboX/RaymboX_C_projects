#include "brc.h"
#include "var_extern.h"

void	ft_sit_movecard()
{
	switch (sit)
	{
		case PLAY:
			//1 deck PLAYER to play PLAYER
			ft_movecard(0,0,0,1);
			//1 deck BOT to play BOT
			ft_movecard(1,0,1,1);
			ft_value_play();
			break;
		case BOT_TRY:
			//1 deck BOT to mise BOT
			ft_movecard(1,0,1,3);
			break;       
		case YOU_TRY:
			//1 deck PLAYER to mise PLAYER
			ft_movecard(0,0,0,3);
			break;
		case BOT_PASS: case PO6:
			//1 play PLAYER to depot PLAYER
			ft_movecard(0,1,0,2);
			//1 play BOT to depot PLAYER
			ft_movecard(1,1,0,2);
			ft_play_reset();
			break;
		case YOU_PASS: case BO6:
			//1 play BOT to depot BOT
			ft_movecard(1,1,1,2);
			//1 play PLAYER to depot BOT
			ft_movecard(0,1,1,2);
			ft_play_reset();
			break;
		case BATAILLE_BET:
			//1 deck PLAYER to mise PLAYER
			ft_movecard(0,0,0,3);
			//1 deck BOT to mise BOT
			ft_movecard(1,0,1,3);
			break;
		case BOT_WINALL: case BAT_BOTWIN:
			//all mise BOT to depot BOT
			ft_movecard(1,3,1,2);
			//all mise PLAYER to depot BOT
			ft_movecard(0,3,1,2);
			//1 play BOT to depot BOT
			ft_movecard(1,1,1,2);
			//1 play PLAYER to depot BOT
			ft_movecard(0,1,1,2);
			ft_play_reset();
			ft_dice_reset();
			break;
		case YOU_WINALL: case BAT_YOUWIN:
			//all mise PLAYER to depot PLAYER
			ft_movecard(0,3,0,2);
			//all mise BOT to depot PLAYER
			ft_movecard(1,3,0,2);
			//1 play PLAYER to depot PLAYER
			ft_movecard(0,1,0,2);
			//1 play BOT to depot PLAYER
			ft_movecard(1,1,0,2);
			ft_play_reset();
			ft_dice_reset();
			break;
		case BOT_WINPLAY:
			//mise PLAYER to OUT
			ft_movecard(0,3,2,0);
			//mise BOT to OUT
			ft_movecard(1,3,2,0);
			//1 play BOT to depot BOT
			ft_movecard(1,1,1,2);
			//1 play PLAYER to depot BOT
			ft_movecard(0,1,1,2);
			ft_play_reset();
			ft_dice_reset();
			break;
		case YOU_WINPLAY:
			//1 mise BOT to OUT
			ft_movecard(1,3,2,0);
			//1 mise YOU to OUT
			ft_movecard(0,3,2,0);
			//1 play PLAYER to depot PLAYER
			ft_movecard(0,1,0,2);
			//1 play BOT to depot PLAYER
			ft_movecard(1,1,0,2);
			ft_play_reset();
			ft_dice_reset();
			break;
		case BAT_BOTBETALL:
			//1 deck BOT to mise BOT
			ft_movecard(1,0,1,3);
			//1 deck BOT to mise PLAYER 
			ft_movecard(1,0,0,3);
			break;
		case BAT_YOUBETALL:
			//1 deck PLAYER to mise PLAYER
			ft_movecard(0,0,0,3);
			//1 deck PLAYER to mise BOT
			ft_movecard(0,0,1,3);
			break;
		case SPLIT:
			//all mise PLAYER to depot PLAYER
			ft_movecard(0,3,0,2);
			//1play PLAYER to depot PLAYER
			ft_movecard(0,1,0,2);
			//all mise BOT to depot BOT
			ft_movecard(1,3,1,2);
			//1 play BOT to depot BOT
			ft_movecard(1,1,1,2);
			ft_play_reset();
			ft_dice_reset();
			break;
	}
}



void	ft_movecard(int	d1, int d2, int d3, int d4)
{
	//decki [0]: from who (0:player 1:BOT 2:OUT)
	//decki [1]: from where (0:deck 1:play 2:depot 3:mise)
	//decki [2,3] : to same as from
	
	int	limit[2] = {0, 0};
	int	offset[2] = {0, 0};
	int	i = -1;
	int	decki[4];

	decki[0] = d1;
	decki[1] = d2;
	decki[2] = d3;
	decki[3] = d4;

	while (++i < 2)
	{
		if (decki[i * 2] != 2 && decki[i * 2 + 1] != 1)//n'est pas OUT ou n'est pas play
		{
			if (decki[i * 2 + 1] == 3)//est mise
			{
				offset[i] = 1;
				decki[i * 2 + 1] = 1;
			}
			limit[i] = ft_strlen(deck[decki[i * 2]][decki[i * 2 + 1]], offset[i]);
		}
	}
	if (limit[0] > 0)
		limit[0] -= 1;//retire 1 de la limite from afin qu'il pointe sur la carte (contrairement a to pointe sur vide)
	
	if (deck[decki[0]][decki[1]][limit[0]]  != '\0')
	{	
		if (offset[0] == 1)// si from est la mise (doit vider au complet)
		{
			if (decki[2] != 2) //si pas OUT
			{
				while (deck[decki[0]][1][1])//tant que mise pas vide
				{
					deck[decki[2]][decki[3]][limit[1]] = deck[decki[0]][decki[1]][limit[0] + 1];
					deck[decki[0]][decki[1]][limit[0] + 1] = '\0';
					limit[0]--;
					limit[1]++;
				}
			}
			else
				deck[decki[0]][decki[1]][limit[0] + offset[0]] = '\0';
		}
		else //tous les autres movecard sont le deplacement d'une carte uniquement 
		{
			deck[decki[2]][decki[3]][limit[1] + offset[1]] = deck[decki[0]][decki[1]][limit[0] + offset[0]];
			deck[decki[0]][decki[1]][limit[0] + offset[0]] = '\0';
		}
	}
}

void	ft_value_play()
{
	int	i = -1;

	while (++i < 2)
	{
		value[i][0] = ft_findchar(i) + 1;
		if (value[i][0] == 14)
			value[i][0] = 50;
		else if (value[i][0] == 15)
			value[i][0] = 90;
	}
}
	

int	ft_findchar(int qui)
{
	char	base[] = "123456789XJQKZZ";
	int	i = 0;

	while (deck[qui][1][0] != base[i])
		i++;
	return (i);
}
