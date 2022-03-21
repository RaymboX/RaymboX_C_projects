#include "brc.h"
#include "var_extern.h"

void	ft_reglement_show()
{
	int	fd;
	char	c[22];
	
	fd = open("reglements", O_RDONLY);
	if (fd > -1)
	{
		ft_add_empty_line(50);
		while (read(fd, &c[0], 1) > 0)
		{
			if (c[0] == '\n' && c[1] == '\n')
			{
				read(0, &input, 1);
				ft_clear_xtra_input();
				c[0] = ' ';
				ft_add_empty_line(5);
			}
			else
			{	
				write(0,&c[0],1);
				c[1] = c[0];
			}
		}
		if (close(fd) == -1)
			write (1, "OUPS", 4);
	}
}
