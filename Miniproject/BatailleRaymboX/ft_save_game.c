#include "brc.h"
#include "var_extern.h"

void	ft_save_new()
{
	int	fd;
	int	ret;

	fd = open("brc_saves", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd != -1)
	{
		lseek(fd, 0, SEEK_END);
		ft_write_gamename(fd);
		write_decks(fd);
		close(fd);
		write(1, "GAME SAVE : ", 12);
		write(1, gamename, 19);
		sleep (2);
	}
}

void	ft_write_gamename(int fd)
{
	time_t	now;
	struct	tm *tm;

	now = time(0);
	if ((tm = localtime(&now)) == NULL)
		printf("Error extracting time stuff\n");
	else
	{
		gamename_fill((int)tm->tm_year+1900, 4, 0);
		gamename[4] = '-';
		gamename_fill((int)tm->tm_mon+1, 2, 5);	
		gamename[7] = '-';
		gamename_fill((int)tm->tm_mday, 2, 8);	
		gamename[10] = ' ';
		gamename_fill((int)tm->tm_hour, 2, 11);	
		gamename[13] = ':';
		gamename_fill((int)tm->tm_min, 2, 14);	
		gamename[16] = ':';
		gamename_fill((int)tm->tm_sec, 2, 17);	
		gamename[19] = '\0';
		write (fd, gamename, 19);
		write (fd, "\n", 1);
	}
}

void	gamename_fill(int number, int nbchar, int offset)
{
	char	c;
	
	if (nbchar != 0)
	{
		c = number % 10 + '0';
		number /= 10;
		gamename[nbchar - 1 + offset] = c;
		gamename_fill(number, --nbchar,  offset);
	}
}

void	write_decks(int fd)
{
	int	i = -1;
	int	i2, i3;

	while (++i < 2)
	{
		i2 = 0;
		while (i2 <= 2)
		{
			i3 = -1;
			while (deck[i][i2][++i3])
				write (fd, &deck[i][i2][i3], 1);
			write (fd, "\n", 1);
			i2 += 2;
		}
	}
}
