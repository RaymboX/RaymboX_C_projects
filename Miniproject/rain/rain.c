#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define HEIGHT 50
#define WIDTH 100
#define NBLINECLEAR 0
#define CHAR_RAIN "*"
#define SLEEPTIME 150000
#define PROBRAIN 1 
#define CHRESTOFFSET_X 40
#define CHRESTOFFSET_Y 15

void	ft_reset_rain_index(int *rain);
void	ft_reset_rain_all(int rain[HEIGHT][WIDTH]);
void	ft_create_rain(int *rain);
void	ft_sleep_n_clear();
int	ft_chrest(int x, int y);

int	main()
{
	int	rain[HEIGHT][WIDTH];
	int	start_index;
	int	index;
	int	y;
	int	x;
	
	srand(time(NULL));
	ft_reset_rain_all(rain);
	index = (start_index = 0);
	while (1)
	{
		y = 0;
		index = start_index;
		while (y < HEIGHT)
		{
			if (y == 0)
			{
				ft_reset_rain_index(rain[index]);
				ft_create_rain(rain[index]);
			}
			x = -1;
			while (++x < WIDTH)
			{
				if (rain[index][x] == 1)
				{
					if (ft_chrest(x, y) == 0)
						write(1, CHAR_RAIN, 1);
				}
				else
					write(1, " ", 1);
			}
			write(1, "\n", 1);
			y++;
			index--;
			if (index < 0)
				index = HEIGHT - 1;
		}
		start_index++;
		if (start_index == HEIGHT)
			start_index = 0;
		ft_sleep_n_clear();		

	}
}
				
void	ft_reset_rain_index(int *rain)
{
	int	i = -1;

	while (++i < WIDTH)
		rain[i] = 0;
}

void	ft_reset_rain_all(int rain[HEIGHT][WIDTH])
{
	int	i = -1;

	while (++i < HEIGHT)
		ft_reset_rain_index(rain[i]);
}

void	ft_create_rain(int *rain)
{
	int	i = -1;

	while (++i < WIDTH)
	{
		if (rand() % 100 < PROBRAIN)
			rain[i] = 1;
	}
}

void	ft_sleep_n_clear()
{
	int	i = -1;

	while (++i < NBLINECLEAR)
		write (1, "\n", 1);
	usleep (SLEEPTIME);
}

int	ft_chrest(int x, int y)
{
	int	size = 12;
	char	eyecol[] = " RAY     BOX ";
	int	xo = x - CHRESTOFFSET_X;
	int	yo = y - CHRESTOFFSET_Y;

	if ((x >= CHRESTOFFSET_X && x <= (CHRESTOFFSET_X + size))
			&& (y >= CHRESTOFFSET_Y && y <= (CHRESTOFFSET_Y + size)))
	{
		if (xo == yo || xo == (size - yo))
		{
			if (xo == yo && xo == (size - yo))
		       		write (1, "M", 1);
			else if (xo == yo)
				write (1, "\\", 1);
			else
				write (1, "/", 1);
			return (1);
		}
		else if ((xo < yo && yo < (size - xo))
			|| (xo > (size - yo) && xo > yo))
		{
			write (1, &eyecol[x - CHRESTOFFSET_X], 1);
			return (1);
		}
	}
	return (0);
}	

