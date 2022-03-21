#include "brc.h"
#include "var_extern.h"

void	ft_sit_diff(char diffline[4][26])
{
	if (value[0][1] != 0 && value[1][1] != 0)
		ft_diffline_fill(diffline, 3);
	else if (value[0][1] == 0 ^ value[1][1] == 0)
		ft_diffline_fill(diffline, 2);
	else if (value[0][0] != 0 && value[1][0] != 0) 
		ft_diffline_fill(diffline, 1);
	else
		ft_diffline_fill(diffline, 0);
}

void	ft_diffline_fill(char diffline[4][26], int nbline)
{
	char	line0[] = "       DIFFERENCES";
	char	line1[] = "         CARD:";
	char	line2[] = "    CARD+DICE:";
	char	line3[] = "         DICE:";
	
	ft_strclear(diffline[0], 26);	
	ft_strclear(diffline[1], 26);
	ft_strclear(diffline[2], 26);
	ft_strclear(diffline[3], 26);
	switch (nbline)
	{
		case 1:
			ft_strcpy(line0, diffline[0]);
			ft_strcpy(line1, diffline[1]);
			ft_diff_fill(diffline, 1);
			break;
		case 2:
			ft_strcpy(line0, diffline[0]);
			ft_strcpy(line1, diffline[1]);
			ft_diff_fill(diffline, 1);
			ft_strcpy(line2, diffline[2]);
			ft_diff_fill(diffline, 2);
			break;
		case 3:
			ft_strcpy(line0, diffline[0]);
			ft_strcpy(line1, diffline[1]);
			ft_diff_fill(diffline, 1);
			ft_strcpy(line2, diffline[2]);
			ft_diff_fill(diffline, 2);
			ft_strcpy(line3, diffline[3]);
			ft_diff_fill(diffline, 3);
			break;
	}
}

void	ft_diff_fill(char diffline[4][26], int nbline)
{
	int	jp = 0;
	int	jm = 0;
	char	diff[2];

	if (value[0][0] - value[1][0] >= 0)
		jm = 1;
	else
		jp = 1;
	switch (nbline)
	{
		case 1:
			diff[0] = (value[jp][0] - value[jm][0]) / 10 + '0';	
			diff[1] = (value[jp][0] - value[jm][0]) % 10 + '0';		
			break;
		case 2:
			if (value[jp][0] < value[jm][0] + value[jm][1])
			{
				diff[0] = '+';
				diff[1] = (value[jm][0] + value[jm][1]) - value[jp][0] + '0';
			}
			else if (value[jp][0] > value[jm][0] + value[jm][1])
			{
				diff[0] = '-';
				diff[1] = value[jp][0] - (value[jm][0] + value[jm][1]) + '0';
			}
			else
			{
				diff[0] = ' ';
				diff[1] = '0';
			}
			break;
		case 3:
			if (value[jp][1] < value[jm][1])
			{
				diff[0] = '-';
				diff[1] = value[jm][1] - value[jp][1] + '0';
			}
			else if (value[jp][1] > value[jm][1])
			{
				diff[0] = '+';
				diff[1] = value[jp][1] - value[jm][1] + '0';
			}
			else
			{
				diff[0] = ' ';
				diff[1] = '0';
			}
	}
	ft_strcat(diffline[nbline], diff);
}
