#include "brc.h"
#include "var_extern.h"

void	deload_menu()
{
	int	fd;
	int	menu_mode = 1;
	int	retint = 0;
	int	nbchoice;
	
	fd = open("brc_saves", O_RDWR | O_CREAT, S_IWUSR | S_IRUSR);
	if (fd != -1)
	{
		while (retint <= 0)
		{
			ft_add_empty_line(50);
			if (retint == 0)
				menu_mode += 1;
			deload_titre(menu_mode);
			nbchoice = 0;
			write_save_choice(fd, &nbchoice);
			if (nbchoice > 0)
			{
				ft_add_empty_line(21 - nbchoice);
				write (1, "WRITE SAVE NUMBER AND PRESS ENTER\n", 34);
				if (menu_mode % 2 == 0)
					write (1, "0: CHANGE TO DELETE MODE -", 26);  
				else
					write (1, "0: CHANGE TO LOAD MODE -", 24);
				write (1, "m: RETURN TO MENU\n", 18);

				retint = ft_read_atoi(fd);				
				if (retint == (int)('m' - '0'))
					retint = 9999;
				else if (retint < 0 || retint > nbchoice)
					retint = -1;
				else if (retint > 0 && retint <= nbchoice)
				{
					//load or delete
					if (menu_mode % 2 == 0)
						ft_load_save(fd, retint);//load
					else
						ft_delete_save(&fd, retint); //delete
				}
			}
			else
			{
				write(1, "\nNO SAVE", 8);
				ft_add_empty_line(22);
				sleep (2);
				retint = 9999;
			}	
		}
	}
	close(fd);
}



void	deload_titre(int menu_mode)
{
	char	line1[2][7] = 	{
				"LOAD",
				"DELETE"
				};
	char   	line2[5] = "GAME";
	
	ft_print_letter55(line1[menu_mode % 2], 0);
	ft_add_empty_line(2);
	ft_print_letter55(line2, 0);
	ft_add_empty_line(2);
}

void	write_save_choice(int fd, int *i)
{
	int	offset = 0;
	int	nbline;
	char	c;
	int	iname;
	int	ret;
	int	endfile;
	
	endfile = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	while (offset <= endfile && endfile - offset > 20)
	{
		write_int(++*i); 
		write (1, ": ", 2);
		iname = -1;
		while (++iname < 19)
		{
			ret = read(fd, &c, 1);
			write (1, &c, 1);
			offset += 1;
		}
		write (1, "\n", 1);
		nbline = 0;
		while (nbline < 5)
		{
			ret = read (fd, &c, 1);
			offset += 1;
			if (c == '\n')
				nbline += 1;
		}
	}
}

void	write_int(int val)
{
	char	c;

	if (val > 0)
	{
		c = val % 10 + '0';
		val /= 10;
		write_int(val);
		write(1, &c, 1);	
	}
}

int	ft_read_atoi(int fd)
{
	char	c;
	int	val = 0;
	
	read(0, &c, 1);
	while (c != '\n')
	{
		val *= 10;
		val += (int)c - '0';
		read(0, &c, 1);
	}
	return (val);
}

void	ft_delete_save(int *fd1, int choice)
{
	int	fd2;
	int	offset;
	int	nbline = 0;
	char	c;
	int	cur_pos;

	offset = find_offset_choice(*fd1, choice);
	close(*fd1);
	rename("brc_saves", "brc_saves_temp");
	*fd1 = open("brc_saves_temp", O_RDONLY);
	fd2 = open("brc_saves", O_RDWR | O_CREAT, S_IWUSR | S_IRUSR);
	cur_pos = lseek(*fd1, 0, SEEK_SET);
	while (cur_pos < (offset - 1))
	{
		read(*fd1, &c, 1);
		cur_pos = lseek(*fd1, 0, SEEK_CUR);	
		write(fd2, &c, 1);
	}
	while (nbline < 5 && read(*fd1, &c, 1) == 1)
	{
		if (c == '\n')
			nbline += 1;
	}
	while (read(*fd1, &c, 1) == 1)
		write(fd2, &c, 1);
	close(*fd1);
	remove("brc_saves_temp");
	*fd1 = fd2;
	write (1, "\nSAVE DELETE\n", 13);
	sleep (2);
}

void	ft_load_save(int fd, int choice)
{
	int	offset;
	int	nbline = 0;
	char	c;
	int	i = 0;

	offset = find_offset_choice(fd, choice);
	ft_reset_alldeck();
	
	while (nbline < 5)
	{
		read(fd, &c, 1);
		if (c == '\n')
		{
			nbline += 1;
			i = 0;
		}
		else
		{
			switch (nbline)
			{
				case 0:
					gamename[i++] = c;
					break;
				case 1:
					deck[0][0][i++] = c;
					break;
				case 2:
					deck[0][2][i++] = c;
					break;
				case 3:
					deck[1][0][i++] = c;
					break;
				case 4:
					deck[1][2][i++] = c;
					break;
			}
		}
	}
	write(1, "\nGAME LOADED\n", 13);
	sleep (2);
}

int	find_offset_choice(int fd, int choice)
{
	int	nbline = 0;
	char	c;
	int	offset = 0;

	lseek(fd, 0, SEEK_SET);
	while (nbline != (choice - 1) * 5)
	{
		read(fd, &c, 1);
		offset += 1;
		if (c == '\n')
			nbline += 1;
	}
	return (offset + 1);
}




