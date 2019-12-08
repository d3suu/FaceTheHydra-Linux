#include "cards.h"
#include <stdio.h>
void dumpBattlefield(int* battlefield){
	printf("Battlefield:\r\n");
	for(int i = 0; i<20; i++){
		switch(battlefield[i]){
			case CARD_HYDRAHEAD:
				printf("%2d: Hydra Head\r\n", i);
				break;
			case CARD_BRUTEHEAD:
				printf("%2d: Ravenous Brute Head\r\n", i);
				break;
			case CARD_VIGORHEAD:
				printf("%2d: Savage Vigor Head\r\n", i);
				break;
			case CARD_FANGHEAD:
				printf("%2d: Snapping Fang Head\r\n", i);
				break;
			case CARD_TITANHEAD:
				printf("%2d: Shrieking Titan Head\r\n", i);
				break;
			default:
				break;
		}
	}
}
void dumpLibrary(int* library){
	printf("Library dump:\r\n");
	for(int i = 0; i<60; i++){
		switch(library[i]){
			case CARD_NOCARD:
				printf("%2d: No card\r\n", i);
				break;
			case CARD_HYDRAHEAD:
				printf("%2d: Hydra Head\r\n", i);
				break;
			case CARD_BRUTEHEAD:
				printf("%2d: Ravenous Brute Head\r\n", i);
				break;
			case CARD_VIGORHEAD:
				printf("%2d: Savage Vigor Head\r\n", i);
				break;
			case CARD_FANGHEAD:
				printf("%2d: Snapping Fang Head\r\n", i);
				break;
			case CARD_TITANHEAD:
				printf("%2d: Shrieking Titan Head\r\n", i);
				break;
			case CARD_GLOWER:
				printf("%2d: Disorienting Glower\r\n", i);
				break;
			case CARD_DISTRACT:
				printf("%2d: Distract the Hydra\r\n", i);
				break;
			case CARD_GROWN:
				printf("%2d: Grown from the Stump\r\n", i);
				break;
			case CARD_HIDE:
				printf("%2d: Hydra's Impenetrable Hide\r\n", i);
				break;
			case CARD_TANGLE:
				printf("%2d: Neck Tangle\r\n", i);
				break;
			case CARD_BREATH:
				printf("%2d: Noxious Hydra Breath\r\n", i);
				break;
			case CARD_WEAKSPOT:
				printf("%2d: Strike the Weak Spot\r\n", i);
				break;
			case CARD_SWALLOW:
				printf("%2d: Swallow the Hero Whole\r\n", i);
				break;
			case CARD_TORN:
				printf("%2d: Torn Between Heads\r\n", i);
				break;
			case CARD_LUNGE:
				printf("%2d: Unified Lunge\r\n", i);
				break;
		}
	}
}

char* cardIDtoString(int id){
	switch(id){
		case CARD_HYDRAHEAD:
			return "Hydra Head";
		case CARD_BRUTEHEAD:
			return "Ravenous Brute Head";
		case CARD_VIGORHEAD:
			return "Savage Vigor Head";
		case CARD_FANGHEAD:
			return "Snapping Fang Head";
		case CARD_TITANHEAD:
			return "Shrieking Titan Head";
		case CARD_GLOWER:
			return "Disorienting Glower";
		case CARD_DISTRACT:
			return "Distract the Hydra";
		case CARD_GROWN:
			return "Grown from the Stump";
		case CARD_HIDE:
			return "Hydra's Impenetrable Hide";
		case CARD_TANGLE:
			return "Neck Tangle";
		case CARD_BREATH:
			return "Noxious Hydra Breath";
		case CARD_WEAKSPOT:
			return "Strike the Weak Spot";
		case CARD_SWALLOW:
			return "Swallow the Hero Whole";
		case CARD_TORN:
			return "Torn Between Heads";
		case CARD_LUNGE:
			return "Unified Lunge";
	}
}

char* cardIDtoTextbox(int id){
	switch(id){
		case CARD_HYDRAHEAD:
			return "Hero's Reward - When Hydra Head leaves the battlefield, each player gains 2 life.";
		case CARD_BRUTEHEAD:
			return "Hero's Reward - When Ravenous Brute Head leaves the battlefield, each player gains 2 life and draws a card.";
		case CARD_VIGORHEAD:
			return "At the beginning of the Hydra's end step, reveal the top card of the Hydra's library and the Hydra casts that card.\r\n\r\nHero's Reward - When Savage Vigor Head leaves the battlefield, each player gains 4 life and draws a card."; // TODO BATTLE FUNCTION
		case CARD_FANGHEAD:
			return "At the beginning of the Hydra'ss end step, Snapping Fang Head deals 1 damage to each player.\r\n\r\nHero'ss Reward - When Snapping Fang Head leaves the battlefield, each player gains 4 life and draws a card."; // TODO BATTLE FUNCTION
		case CARD_TITANHEAD:
			return "At the beginning of the Hydra's end step, each player discards a card.\r\n\r\nHero'ss Reward - When Shrieking Titan Head leaves the battlefield, each player gains 4 life and draws a card.";
		case CARD_GLOWER:
			return "Players can't cast spells until the Hydra's next turn.";
		case CARD_DISTRACT:
			return "Each player may sacrifice a creature. Each player who sacrificed a creature this way chooses a Head and taps it. Each player who didn't sacrifice a creature loses 3 life."; // TODO Multiple head kill
		case CARD_GROWN:
			return "Place exactly two cards named Hydra Head onto the battlefield from the Hydra's graveyard. If you can't, reveal cards from the top of the Hydra's library until you reveal a Head card. Put that card onto the battlefield and the rest into the Hydra's graveyard."; // TODO Graveyard, TODO BATTLE FUNCTION - add head
		case CARD_HIDE:
			return "Each head gains indestructible until the end of the Hydra's next turn.";
		case CARD_TANGLE:
			return "If there are five or more Heads on the battlefield, tap two of them and they don't untap during the Hydra's next untap step. Otherwise, reveal the top card of the Hydra's library and the Hydra casts that card."; // TODO BATTLE FUNCTION - next card
		case CARD_BREATH:
			return "Choose one - Noxious Hydra Breath deals 5 damage to each player; or destroy each tapped non-Head creature.";
		case CARD_WEAKSPOT:
			return "Destroy target Head. If that Head was elite, the Hydra takes an extra turn after this one."; // TODO Select head, extra turn for hydra
		case CARD_SWALLOW:
			return "Each player exiles a creature they control. Until the Hydra's next turn, when a Head leaves the battlefield, return the exiled cards to the battlefield under their owners' control.";
		case CARD_TORN:
			return "Tap up to two Heads. They don't untap during the Hydra's next untap step. Torn Between Heads deals 5 damage to each player."; // TODO Tap status on cards
		case CARD_LUNGE:
			return "Unified Lunge deals X damage to each player, where X is the number of Heads on the battlefield.";
	}
}
