#include "brc.h"
#include "var_extern.h"

void	ft_sit_check()
{
	switch (input)
	{
		case 'c':
			sit = BAT_BOTBETALL;
			break;
		case 'C':
			sit = BAT_YOUBETALL;
			break;
		case 'S':
			sit = SPLIT;
			break;
		case 'w':
			sit = YOU_LOSEGAME;
			break;
		case 'W':
			sit = YOU_WINGAME;
			break;
		case 'n':
			sit = YOU_NOTRY;
			break;
		case 'N':
			sit = BOT_NOTRY;
			break;
		default:
			switch (sit)
			{
				case START: case YOU_WINGAME: case YOU_LOSEGAME:
					if ((input == 'm' && sit == START) 
							|| sit == YOU_WINGAME || sit == YOU_LOSEGAME)
						sit = MENU;
					else
						sit = PLAY;
					break;
				case PLAY:
					if (value[0][0] == value[1][0])
					       sit = BATAILLE;
					else if (value[0][0] - value[1][0] < -6)
						sit = BO6;
					else if (value[0][0] - value[1][0] > 6)
						sit = PO6;
					else if (value[0][0] < value[1][0])
						sit = B1TO6;
					else if (value[0][0] > value[1][0])
						sit = P1TO6;
					break;
				case BO6: case PO6:
				case YOU_PASS: case BOT_PASS:
				case YOU_WINALL: case YOU_WINPLAY:
				case BOT_WINALL: case BOT_WINPLAY:
				case BAT_BOTWIN: case BAT_YOUWIN:
				case SPLIT:
					sit = START;
					break;
				case B1TO6:
					if (input == 'p')
						sit = YOU_PASS;
					else if (input == 'm')
						sit = YOU_TRY;
					break;
				case YOU_TRY: case YOU_RETRY:
					if (value[0][0] + value[0][1] > value[1][0])
						sit = YOU_SUCCEED;
					else if (value[0][0] + value[0][1] < value[1][0])
						sit = YOU_FAIL;
					else if (value[0][0] + value[0][1] == value[1][0])
						sit = BATAILLE;
					break;
				case YOU_FAIL: case YOU_SUCCEED:
					sit = BOT_DICE;
					break;
				case BOT_DICE:
					if (value[1][1] == value[0][1])
						sit = REINITIALISATION;
					else if (value[0][0] + value[0][1] > value[1][0])
					{
						if (value[1][1] > value[0][1])
							sit = YOU_WINPLAY;
						else if (value[1][1] < value[0][1])
							sit = YOU_WINALL;
					}
					else if (value[0][0] + value[0][1] < value[1][0])
					{
						if (value[1][1] > value[0][1])
							sit = BOT_WINALL;
						else if (value[1][1] < value[0][1])
							sit = BOT_WINPLAY;
					}
					break;
				case P1TO6:
					if (input == 'p')
						sit = BOT_PASS;
					else if (input == 'm')
						sit = BOT_TRY;
					break;
				case BOT_TRY: case BOT_RETRY:
					if (value[1][0] + value[1][1] > value[0][0])
						sit = BOT_SUCCEED;
					else if (value[1][0] + value[1][1] < value[0][0])
						sit = BOT_FAIL;
					else if (value[1][0] + value[1][1] == value[0][0])
						sit = BATAILLE;
				       	break;
				case BOT_FAIL: case BOT_SUCCEED:
					sit = YOU_DICE;
			 		break;
				case YOU_DICE:
					//if (input == 'm')
					//{
						if (value[0][1] == value[1][1])
							sit = REINITIALISATION;
						else if (value[1][0] + value[1][1] > value[0][0])
						{
							if (value[0][1] > value[1][1])
								sit = BOT_WINPLAY;
							else if (value[0][1] < value[1][1])
								sit = BOT_WINALL;
						}
						else if (value[1][0] + value[1][1] < value[0][0])
						{
							if (value[0][1] > value[1][1])
								sit = YOU_WINALL;
							else if (value[0][1] < value[1][1])
								sit = YOU_WINPLAY;
						}
					//}
					break;
				case REINITIALISATION:
					if (value[0][0] > value[1][0])
						sit = BOT_RETRY;
					else if (value[0][0] < value[1][0])
						sit = YOU_RETRY;
					break;
				case BOT_NOTRY:
				       	sit = BOT_PASS;
					break;
			 	case YOU_NOTRY:
					sit = YOU_PASS;
					break;
				case BATAILLE:
					sit = BATAILLE_BET;
					break;
				case BATAILLE_BET: case BAT_YOUBETALL: case BAT_BOTBETALL:
					if (value[0][1] > value[1][1])
						sit = BAT_YOUWIN;
					else if (value[0][1] < value[1][1])
						sit = BAT_BOTWIN;
					else if (value[0][1] == value[1][1])
						sit = BATAILLE;
					break;
			}
	}
	input = '\n';
}

