// doit etre utiliser avec seulement des majuscules
#include "brc.h"
#include "var_extern.h"

void	ft_print_letter55(char *str, int offset_x)
{
	int	l;
	int	y;
	int	x;
	int	fd;
	int	fo; // file_offset
	int	buffer;

	fd = open("letter55", O_RDONLY);
	y = 0;
	while (y < 5) //pour les 5 col de la lettre
	{
		ft_put_offset(offset_x);
		l = 0;
		while (str[l]) // pour chaque lettre
		{
			fo = (str[l] - 'A') * 5 * 6 + 6 * y;
			lseek(fd, fo, SEEK_SET);
			x = -1;
			while (++x < 5)
			{
				read (fd, &buffer, 1);
				write (1, &buffer, 1);
			}
			write (1, "   ", 2);
			l++;
		}
		write (1, "\n", 1);
		y++;
	}
	close (fd);
}

void	ft_put_offset(int offset_x)
{
	int	x = -1;

	while (++x < offset_x)
		write (1, " ", 1);
}
