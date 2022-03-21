#include <unistd.h>

int	main()
{
	int x = 0;
	int y = 0;
	char	eyecol[] = " RAY     BOX ";

	while (y < 13)
	{
		x = 0;
		while (x < 13)
		{
			if (x == y || x == (12 - y))
			{
				if (x == y && x == (12 - y))
					write (1, "M", 1);
				else if (x == y)
					write (1, "\\", 1);
				else
					write (1, "/", 1);
			}
			else if ((x < y && y < (12 - x))
					|| (x > (12 - y) && x > y))
				write (1, &eyecol[x], 1);
			else
				write(1, " ", 1);
			x++;
		}
		y++;
		write(1, "\n", 1);
	}
}
