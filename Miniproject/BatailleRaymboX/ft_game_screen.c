#include "brc.h"
#include "var_extern.h"

#define SW 25 

void	ft_game_screen()
{
	 
	// les situations d'animation seront inserer ici
	// et passer en argument de la fonction ft_linegroup_draw

	ft_linegroup_draw();



}


void	ft_linegroup_draw()
{
	int	x;
	int	y;
	int	linegroup = 0;
	char	message[2][26];
	char	commandline[26];	
	char	diffline[4][26];

	ft_clear_screen(10);
	while (linegroup < 5)
	{
		y = 0;
		while (y < 8)
		{
			x = 0;
			while (x < SW)
			{
				if (linegroup == 0)
				{
					// message line
					ft_message(message);
					// diff & who line
					ft_sit_diff(diffline);
					switch (y)
					{
						case 0 ... 1:
							write(1, message[y], ft_strlen(message[y], 0));
							break;
						case 3 ... 6:
						write(1, diffline[y - 3],ft_strlen(diffline[y - 3], 0));
					}
					x = SW;
				}
				if (linegroup == 1)
					ft_draw_deckplay(x, y);
				if (linegroup == 2)
					ft_draw_depotmise(x, y);
				if (linegroup == 3)
				{
					if (x <= 19)
						ft_draw_de(x, y);
					else if (ft_outcard_count() > 0)
						ft_draw_out(x, y);
				}
				if (linegroup == 4)
				{
					if (y == 0)
					{
						//command lines
						ft_sit_commandline(commandline);
						write(1, commandline, ft_strlen(commandline, 0));
					}
					else
						y = 8;
					x = SW;
				}
				x++;
			}
			y++;
			write (1, "\n", 1);
		}
		linegroup++;
	}
}

int	ft_outcard_count()
{
	int	i1 = -1;
	int	i2;
	int	nbgame = 0;

	while (++i1 < 2)
	{
		i2 = -1;
		while (++i2 < 3)
			nbgame += ft_strlen(deck[i1][i2], 0);
	}
	return (54 - nbgame);
}

void	ft_draw_deckplay(int x, int y)
{
	char	c = ' ';
	
	if (x >= 0 && x <= 4 && deck[0][0][0])
		c = ft_char_card(ft_strlen(deck[0][0], 0), '0', "DECK ", 0, x, y);
	else if (x >= 6  && x <= 10 && deck[0][1][0])
		c = ft_char_card(1, deck[0][1][0], "PLAY ", 6, x, y);
	else if (x >= 14  && x <= 18 && deck[1][1][0])
		c = ft_char_card(1, deck[1][1][0], "PLAY ", 14, x, y);
	else if (x >= 20 && x <= 24 && deck[1][0][0])
		c = ft_char_card(ft_strlen(deck[1][0], 0), '0', "DECK ", 20, x, y);
	write(1, &c, 1);
}

void	ft_draw_depotmise(int x, int y)
{
	char	c = ' ';
	
	if (x >= 0 && x <= 4 && deck[0][2][0] != '\0')
		c = ft_char_card(ft_strlen(deck[0][2], 0), '0', "DEPOT", 0, x, y);
	else if (x >= 6  && x <= 10 && deck[0][1][1] != '\0') 
		c = ft_char_card(ft_strlen(deck[0][1], 1), deck[0][1][ft_strlen(deck[0][1], 1)], "MISE ", 6, x, y);
	else if (x >= 14  && x <= 18 && deck[1][1][1] != '\0')
		c = ft_char_card(ft_strlen(deck[1][1], 1), deck[1][1][ft_strlen(deck[1][1], 1)], "MISE ", 14, x, y);
	else if (x >= 20 && x <= 24 && deck[1][2][0] != '\0') 
		c = ft_char_card(ft_strlen(deck[1][2], 0), '0', "DEPOT", 20, x, y);
	write(1, &c, 1);
}

void	ft_draw_out(int x, int y)
{
	char	c = ' ';

	if (x >= 20 && x <= 24)
		c = ft_char_card(ft_outcard_count(), '0', "OUT", 20, x, y);
	write(1, &c, 1);
}

void	ft_draw_de(int x, int y)
{
	char	c = ' ';

	if (value[0][1] != 0 && x >= 5 && x <= 10)
		c = ft_char_de(value[0][1], 5, x, y);
	else if (value[1][1] != 0 && x >= 13 && x <= 18)
		c = ft_char_de(value[1][1], 13, x, y);
	write (1, &c, 1);
}

char	ft_char_de(int value, int offset_x, int x, int y)
{
	char	c = ' ';
	int	xo = x - offset_x;
	
	if (y == 4)
	{
		if (xo == 1)
			c = 'D';
		else if (xo == 2)
			c = 'E';
	}
	else if ((y == 1 && xo == 5) || ((y >= 1 && y <= 3) && (xo == 0 || xo == 4)))
		c = '|';
	else if ((y == 0 && xo >= 2 && xo <= 4) || ((y == 1 || y == 3) && (xo >= 1 && xo <= 3)))
		c = '-';
	else if (((y == 0) && (xo == 1 || xo == 5)) || (y == 2 && xo == 5))
		c = '/';
	else if (y == 2 && xo == 2)
		c = value + '0';
	return (c);
}

char	ft_char_card(int nbleft, char topcard, char name5char[6], int offset_x, int x, int y)
{
	char	c = ' ';
	int	xo = x - offset_x;

	if (nbleft > 0 && xo >= 0 && xo <= 5)
	{
		if (y == 0)
		{
			if (xo == 0)
				c = nbleft / 10 + '0';
			else if (xo == 1)
				c = nbleft % 10 + '0';
		}
		else if ((y == 1 || y == 5) && (xo >= 0) && (xo <= 4))
			c = '-';
		else if (y >= 2 && y <= 4)
		{
			if (xo == 0 || xo == 4)
				c = '|';
			else if (topcard == '0')
			{
				if ((y == 2 && xo == 1)
						|| (y == 4 && xo == 3))
					c = '\\';
				if ((y == 2 && xo == 3)
						|| (y == 4 && xo == 1))
					c = '/';
				if (y == 3 && xo == 2)
					c = 'X';
			}
			else if ((y == 2 && xo == 1) || (y == 4 && xo == 3))
				c = topcard;
		}
		else if (y == 6)
			c = name5char[xo];		
	}
	return (c);
}

void	ft_clear_screen(int nbline)
{
	int	i = -1;

	while (++i < nbline)
		write(1, "\n", 1);
}
