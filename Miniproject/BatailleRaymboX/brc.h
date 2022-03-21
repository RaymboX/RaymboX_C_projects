#ifndef BRC_H
# define BRC_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

char	deck[2][3][54];
int	value[2][2];
char	input;
int	sit;
char	gamename[20];

enum	situation
{
	 START,
	 PLAY,
	 MENU,
	 PO6,
	 BO6,
	 B1TO6,
	 YOU_PASS,
	 YOU_TRY,
	 YOU_FAIL,
	 YOU_SUCCEED,
	 BOT_DICE,
	 P1TO6,
	 BOT_PASS,
	 BOT_TRY,
	 BOT_FAIL,
	 BOT_SUCCEED,
	 YOU_DICE,
	 YOU_WINALL,
	 YOU_WINPLAY,
	 BOT_WINPLAY,
	 BOT_WINALL,
	 REINITIALISATION,
	 BOT_RETRY,
	 YOU_RETRY,
	 BOT_NOTRY,
	 YOU_NOTRY,
	 BATAILLE,
	 BATAILLE_BET,
	 BAT_BOTBETALL,
	 BAT_YOUBETALL,
	 BAT_BOTWIN,
	 BAT_YOUWIN,
	 SPLIT,
	 YOU_WINGAME,
	 YOU_LOSEGAME
}sit_num;

//main.c
void	ft_gameloop();
void	ft_gamenameclear();

//ft_basic.c
int	ft_strlen(char *str, int offset);
void	ft_strcpy(char *src, char *dest);
void	ft_strclear(char *src, int len);
void	ft_strcat(char *dest, char *src);
void	ft_play_reset();
void	ft_dice_reset();

//ft_cardsit_check
char	ft_cardsit_check();
void	ft_deckcount(int deckcount[2][4]);
void	ft_brasse(int qui);

//ft_endgame.c
void	ft_endgame();

//ft_dice_play.c
void	ft_throw_dice(int qui);
void	ft_bot_choice();

//ft_game_screen.c
void	ft_game_screen();
void	ft_linegroup_draw();
int	ft_outcard_count();
void	ft_draw_deckplay(int x, int y);
void	ft_draw_depotmise(int x, int y);
void	ft_draw_out(int x, int y);
char	ft_char_de(int value, int offset_x, int x, int y);
void	ft_draw_de(int x, int y);
char	ft_char_card(int nbleft, char topcard, char name5char[6], int offset_x, int x, int y);
void	ft_clear_screen(int nbline);

//ft_load_delete_game.c
void	deload_menu();
void	deload_titre(int menu_mode);
void	write_save_choice(int fd, int *i);
void	write_int(int val);
int	ft_read_atoi(int fd);
void	ft_delete_save(int *fd1, int choice);
void	ft_load_save(int fd, int choice);
int	find_offset_choice(int fd, int choice);

//ft_menu.c
char	ft_menu();
void	ft_menu_command(int condition);
void	ft_add_empty_line(int nbline);
void	ft_add_space(int nbspace);
void	ft_titre();

//ft_message.c
void	ft_message(char message[2][26]);
void	ft_strcpy_message(char message[2][26], char line1[26], char line2[26]);

//ft_newgame.c
void	ft_newgame(char *base);
void	ft_jeu_fill(char *jeu, char *base);
void	ft_reset_deck(int i1, int i2);
void	ft_reset_alldeck();

//ft_print_letter55.c
void	ft_print_letter55(char *str, int offset_x);
void	ft_put_offset(int offset_x);

//ft_reglements_show.c
void	ft_reglement_show();

//ft_save_game.c
void	ft_save_new();
void	ft_write_gamename(int fd);
void	gamename_fill(int number, int nbchar, int offset);
void	write_decks(int fd);

//ft_sit_action.c
void	ft_sit_action();
void	ft_action_series(int actserie);
void	ft_clear_xtra_input();

//ft_sit_check.c
void	ft_sit_check();

//ft_sit_command.c
void	ft_sit_commandline(char commandline[26]);
void	ft_strcpy_command(char command[26], char *commandline);

//ft_sit_diff.c
void	ft_sit_diff(char diffline[4][26]);
void	ft_diffline_fill(char diffline[4][26], int nbline);
void	ft_diff_fill(char diffline[4][26], int nbline);

//ft_sit_movecard.c
void	ft_sit_movecard();
void	ft_movecard(int d1, int d2, int d3, int d4);
void	ft_value_play();
int	ft_findchar(int qui);

#endif
