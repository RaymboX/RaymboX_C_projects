#include "brc.h"
#include "var_extern.h"

void	ft_sit_action()
{
	switch (sit)
	{
		case START: case B1TO6:
		case BOT_FAIL: case BOT_SUCCEED:
			ft_action_series(1);
			ft_action_series(5);
			break;
		case PLAY:
			ft_action_series(3);
			ft_value_play();
			ft_action_series(4);
			ft_action_series(5);
			break;
		case P1TO6:
			ft_action_series(2);
			ft_bot_choice();
			ft_action_series(5);
			break;
		case YOU_FAIL: case YOU_SUCCEED:
		case BOT_NOTRY: case YOU_NOTRY:
			ft_action_series(2);
			ft_action_series(5);
			break;
		case YOU_WINGAME: case YOU_LOSEGAME:
			ft_endgame();
			ft_action_series(5);	
			break;
		case REINITIALISATION:
			ft_action_series(2);
			ft_dice_reset();
			ft_action_series(5);
			break;
		case BOT_PASS: case YOU_PASS:
		case PO6: case BO6:
		case YOU_WINALL: case YOU_WINPLAY:
		case BOT_WINALL: case BOT_WINPLAY:	
		case BAT_BOTWIN: case BAT_YOUWIN:
		case SPLIT:
			ft_action_series(6);
			break;
		case BOT_DICE: case YOU_DICE:
		case BOT_RETRY: case YOU_RETRY:
			ft_action_series(2);
			if (sit == YOU_RETRY || sit == YOU_DICE)
				ft_throw_dice(0);
			else
				ft_throw_dice(1);
			ft_action_series(5);
			break;
		case BOT_TRY: case YOU_TRY:
			ft_action_series(2);
			ft_action_series(3);
			ft_action_series(4);
			if (sit == YOU_TRY)
				ft_throw_dice(0);
			else
				ft_throw_dice(1);
			ft_action_series(5);
			break;
		case BATAILLE:
			ft_action_series(2);
			ft_action_series(4);
			ft_action_series(5);
			break;
		case BATAILLE_BET: case BAT_YOUBETALL:
			ft_action_series(1);
			ft_action_series(3);
			ft_action_series(4);
			ft_throw_dice(0);
			ft_throw_dice(1);
			ft_action_series(5);
			break;
		case BAT_BOTBETALL:
			ft_action_series(2);
			ft_action_series(3);
			ft_action_series(4);
			ft_throw_dice(0);
			ft_throw_dice(1);
			ft_action_series(5);
			break;
			
	}
}	

void	ft_action_series(int actserie)
{
	switch (actserie)
	{
		case 1:
			ft_game_screen();
			read(0, &input, 1);
			ft_clear_xtra_input();
			break;
		case 2:
			ft_game_screen();
			read(0, &input, 1);
			ft_clear_xtra_input();
			input = '\n';
			break;
		case 3:
			ft_sit_movecard();
			break;	
		case 4:
			input = ft_cardsit_check();
			if (input == 'b' || input == 'B')
			{
				if (input == 'b')
					ft_brasse(0);
				else
					ft_brasse(1);
				input = '\n';
			}
			break;
		case 5:
			ft_sit_check();
			break;
		case 6:
			ft_action_series(2);
			ft_action_series(3);
			ft_action_series(4);
			ft_play_reset();
			ft_dice_reset();
			ft_action_series(5);
			break;
	}
}	

void	ft_clear_xtra_input()
{
	char	clearxin;
	
	clearxin = input;
	while (clearxin != '\n')
		read(0, &clearxin, 1);
}
