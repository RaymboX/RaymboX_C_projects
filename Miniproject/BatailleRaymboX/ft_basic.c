#include "brc.h"
#include "var_extern.h"

int	ft_strlen(char *str, int offset)
{
	int	i = offset;

	while (str[i])
		i++;
	return (i - offset);
}

void	ft_strcpy(char *src, char *dest)
{
	int	i = -1;

	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
}

void	ft_strclear(char *src, int len)
{
	int	i = -1;

	while (++i < len)
		src[i] = '\0';
}

void	ft_strcat(char *dest, char *src)
{
	int	idest = 0;
	int	isrc = 0;
	
	while (dest[idest])
		idest++;

	while (src[isrc])
	{
		dest[idest] = src[isrc];
		isrc++;
		idest++;
	}
}

void	ft_play_reset()
{
	value[0][0] = 0;
	value[1][0] = 0;
}

void	ft_dice_reset()
{
	value[0][1] = 0;
	value[1][1] = 0;
}
