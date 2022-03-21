#include "brc.h"
#include "var_extern.h"

void	ft_message(char message[2][26])
{
	switch (sit)
	{
		case START:
			ft_strcpy_message(message,
				       	"____Let's go already!____", 
					"");
			break;
		case PO6:
			ft_strcpy_message(message,
				       	"________PLAYER > 6_______",
				       	"You win");
			break;
		case BO6:
			ft_strcpy_message(message,
				       	"_________BOT > 6_________",
				       	"                 Bot win");
			break;
		case B1TO6:
			ft_strcpy_message(message,
				       	"________BOT 1 TO 6_______",
				       	"What do you do?");
			break;

		case P1TO6:
			ft_strcpy_message(message,
				       	"______PLAYER 1 TO 6______",
				       	"            Bot thinking");
			break;
		case YOU_PASS:
			ft_strcpy_message(message,
				       	"YOU PASS_________________",
				       	"                  Bot win");
			break;
		case BOT_PASS:
			ft_strcpy_message(message,
				       	"_________________BOT PASS",
				       	"You win");
			break;
		case BOT_SUCCEED:
			ft_strcpy_message(message,
				       	"_________BOT SUCCEED DICE",
				       	"Your turn");
			break;
		case BOT_FAIL:
			ft_strcpy_message(message,
				       	"____________BOT FAIL DICE",
				       	"Your turn");
			break;
		case BATAILLE:
			ft_strcpy_message(message,
				       	"________BATAILLE_________",
				       	"");
			break;
		case BATAILLE_BET:
			ft_strcpy_message(message,
				       	"________BATAILLE_________",
				       	"Mise et lance le de");
			break;
		case YOU_SUCCEED:
			ft_strcpy_message(message,
				       	"YOU SUCCEED DICE_________",
				       	"                 Bot turn");
			break;
		case YOU_FAIL:
			ft_strcpy_message(message,
				       	"YOU FAIL DICE____________",
				       	"                 Bot turn");
			break;
		case BOT_DICE: case BOT_TRY:
			ft_strcpy_message(message,
				       	"_________________________",
				       	"           Bot throw dice");
			break;
		case YOU_DICE: case YOU_TRY:
			ft_strcpy_message(message,
				       	"_________________________",
				       	"You throw dice");
			break;
		case REINITIALISATION:
			ft_strcpy_message(message,
				       	"____REINITIALISATION_____",
				       	"");
			break;
		case BOT_WINALL:
			ft_strcpy_message(message,
				       	"______________BOT WIN ALL",
				       	"");
			break;
		case BOT_WINPLAY:
			ft_strcpy_message(message,
				       	"_____________BOT WIN PLAY",
				       	"        BET OUT");
			break;
		case YOU_WINPLAY:
			ft_strcpy_message(message,
				       	"YOU WIN PLAY_____________",
				       	"        BET OUT");
			break;
		case YOU_WINALL:
			ft_strcpy_message(message,
				       	"YOU WIN ALL______________",
				       	"");
			break;
		case BAT_BOTBETALL:
			ft_strcpy_message(message,
				       	"YOU DON'T HAVE CARD______",
				       	"          BOT BET FOR YOU");
			break;
		case BAT_YOUBETALL:
			ft_strcpy_message(message,
				       	"______BOT DON'T HAVE CARD",
				       	"YOU BET FOR HIM");
			break;
		case SPLIT:
			ft_strcpy_message(message,
				       	"_NO MORE CARD EACH SIDE__",
				       	"    THE CARD ARE SPLIT   ");
			break;
		case BAT_BOTWIN:
			ft_strcpy_message(message,
				       	"_____BOT WIN THE BATAILLE",
				       	"              BOT WIN ALL");
			break;
		case BAT_YOUWIN:
			ft_strcpy_message(message,
				       	"YOU WIN THE BATAILLE_____",
				       	"YOU WIN ALL");
			break;
		case YOU_LOSEGAME:
			ft_strcpy_message(message,
				       	"______YOU LOST GAME______",
				       	"");
			break;
		case YOU_WINGAME:
			ft_strcpy_message(message,
				       	"_______YOU WIN GAME______",
				       	"");
			break;
		case BOT_NOTRY:
			ft_strcpy_message(message,
				       	"____________BOT CAN'T BET",
				       	"");
			break;
		case YOU_NOTRY:
			ft_strcpy_message(message,
				       	"YOU CAN'T BET____________",
				       	"");
			break;
		case BOT_RETRY:
			ft_strcpy_message(message,
				       	"____REINITIALISATION_____",
				       	" BOT RETRY AND THROW DICE");
			break;
		case YOU_RETRY:
			ft_strcpy_message(message,
				       	"____REINITIALISATION_____",
				       	"THROW AGAIN");
			break;
		default:
			ft_strcpy_message(message, "", "");
	}		
}

void	ft_strcpy_message(char message[2][26], char line1[26], char line2[26])
{
	ft_strcpy(line1, message[0]);
	ft_strcpy(line2, message[1]);
}



