#include <stdio.h>

#include "cards.h"
#include "stack.h"

char dummyChar;

#define COLOR_RED 1
#define COLOR_GREEN 2
#define COLOR_BLUE 3
void cprint(char* text, int color){
	// color print
	switch(color){
		case COLOR_RED:
			printf("\033[0;31m");
			break;
		case COLOR_GREEN:
			printf("\033[0;32m");
			break;
		case COLOR_BLUE:
			printf("\033[0;34m");
			break;
	}
	printf(text);
	printf("\033[0m");
}

int main(){
	// Hello
	cprint("Face The Hydra\r\n", COLOR_GREEN);

	system("/bin/stty raw"); // https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar

	int HydraLibrary[60] = {\
		CARD_HYDRAHEAD, CARD_HYDRAHEAD, CARD_HYDRAHEAD, CARD_HYDRAHEAD, CARD_HYDRAHEAD, CARD_HYDRAHEAD, CARD_HYDRAHEAD, CARD_HYDRAHEAD, CARD_HYDRAHEAD, CARD_HYDRAHEAD, CARD_HYDRAHEAD,\
		CARD_BRUTEHEAD, CARD_BRUTEHEAD, CARD_BRUTEHEAD, CARD_BRUTEHEAD,\
		CARD_VIGORHEAD,\
		CARD_FANGHEAD,\
		CARD_TITANHEAD,\
		CARD_GLOWER, CARD_GLOWER, CARD_GLOWER, CARD_GLOWER, CARD_GLOWER,\
		CARD_DISTRACT, CARD_DISTRACT, CARD_DISTRACT, CARD_DISTRACT, CARD_DISTRACT,\
		CARD_GROWN, CARD_GROWN, CARD_GROWN, CARD_GROWN,\
		CARD_HIDE, CARD_HIDE, CARD_HIDE, CARD_HIDE,\
		CARD_TANGLE, CARD_TANGLE, CARD_TANGLE,\
		CARD_BREATH, CARD_BREATH, CARD_BREATH, CARD_BREATH,\
		CARD_WEAKSPOT, CARD_WEAKSPOT,\
		CARD_SWALLOW, CARD_SWALLOW, CARD_SWALLOW, CARD_SWALLOW, CARD_SWALLOW,\
		CARD_TORN, CARD_TORN, CARD_TORN, CARD_TORN,\
		CARD_LUNGE, CARD_LUNGE, CARD_LUNGE, CARD_LUNGE, CARD_LUNGE, CARD_LUNGE};

	int Battlefield[20];
	for(int i = 0; i<20; i++){
		Battlefield[i] = CARD_NOCARD;
	}

	printf("Select difficulty:\r\n1. Easy - 2 Hydra heads\r\n2. Normal - 3 Hydra heads\r\n3. Hard - 4 Hydra heads\r\n\r\n[1-3]> ");
	char difficultyChar = getchar();
	int difficulty = atoi(&difficultyChar);
	if(difficulty > 3 || difficulty < 1){
		cprint("ERROR!", COLOR_RED);
		printf(" Wrong difficulty %d. Exiting...\r\n", difficulty);
		system("/bin/stty cooked");
		return 1;
	}

	printf("Drawing %d Hydra Head's on battlefield...\r\n", difficulty+1);
	for(int i = 0; i < difficulty+1; i++){
		Battlefield[i] = HydraLibrary[i];
		HydraLibrary[i] = CARD_NOCARD;
	}

	//printf("Cards in library: %d\r\n", sizeof(HydraLibrary)/sizeof(int));
	//dumpLibrary(HydraLibrary);

	printf("Shuffling library 3 times...\r\n");
	for(int i = 0; i<3; i++)
		shuffle(HydraLibrary);
	
	//dumpLibrary(HydraLibrary); // <---- debug
	dumpBattlefield(Battlefield);

	long long turnCounter = 0;
	while(1){ // game loop
		// Check if win
		int CardsOnBattlefield = 0;
		for(int i = 0; i<20; i++){
			if(Battlefield[i] != CARD_NOCARD)
				CardsOnBattlefield++;
		}
		if(CardsOnBattlefield <= 0){
			cprint("\r\n\r\nWIN!", COLOR_GREEN);
			printf(" All Hydra Head's defeated!\r\nGame took %d turns.\r\n", turnCounter);
			system("/bin/stty cooked");
			return 0;
		}

		// Your turn
		turnCounter++;
		cprint("\r\nYour turn", COLOR_BLUE);
		printf(" number %lld.\r\n", turnCounter);
		if(turnCounter > 1)
			printf("Draw a card.\r\n");

		// Show battlefield, give options
		dumpBattlefield(Battlefield);
		printf("What to do?\r\n1. Kill\r\n2. Pass turn\r\n[1,2]> ");
		char optionChar = getchar();
		printf("\r\n---------------------------------------------------------------------------------------\r\n");
		int CardBuffer = CARD_NOCARD;
		if(atoi(&optionChar)/10 == 1){
			printf("\r\nSelect head: ");
			optionChar = getchar();
			printf("\r\n---------------------------------------------------------------------------------------\r\n");
			Battlefield[atoi(&optionChar)/10] = CARD_NOCARD;
			printf("\r\nKilled, drawing two cards...\r\n");
			// Draw two cards, if its head, add it to Battlefield
			for(int i = 0; i<2; i++){
				for(int j = 0; CardBuffer == CARD_NOCARD; j++){ // draw cards, unless its something else than NOCARD
					CardBuffer = HydraLibrary[j];
					if(CardBuffer != CARD_NOCARD)
						HydraLibrary[j] = CARD_NOCARD;
				}
				printf("Card is: %s\r\n", cardIDtoString(CardBuffer));
				int doAddCard = 0; // false
				switch(CardBuffer){
					case CARD_HYDRAHEAD:
					case CARD_BRUTEHEAD:
					case CARD_VIGORHEAD:
					case CARD_FANGHEAD:
					case CARD_TITANHEAD:
						doAddCard = 1;
						break;
					default:
						break;
				}
				if(doAddCard){ // Find free space in Battlefield, put card there
					for(int j = 0; j<20; j++){
						if(Battlefield[j] == CARD_NOCARD){
							Battlefield[j] = CardBuffer;
							break;
						}
					}
				}
				CardBuffer = CARD_NOCARD; // cleanup
			}
		}
		cprint("\r\nHydra's Turn!\r\n", COLOR_BLUE);
		printf("Hydra draws a card...\r\n");
		for(int i = 0; CardBuffer == CARD_NOCARD; i++){
			CardBuffer = HydraLibrary[i];
			if(CardBuffer != CARD_NOCARD)
				HydraLibrary[i] = CARD_NOCARD;
		}
		cprint("\r\nDrawed card", COLOR_BLUE);
		printf(": %s\r\n%s\r\n\r\n", cardIDtoString(CardBuffer), cardIDtoTextbox(CardBuffer));
		//printf("\r\nDrawed card: %d\r\n", CardBuffer); // <-- debug
		// If Hydra drawed head, put it in battlefield
		int doAddCard = 0; // false
		switch(CardBuffer){
			case CARD_HYDRAHEAD:
			case CARD_BRUTEHEAD:
			case CARD_VIGORHEAD:
			case CARD_FANGHEAD:
			case CARD_TITANHEAD:
				doAddCard = 1;
				break;
			default:
				break;
		}
		if(doAddCard){ // Find free space in Battlefield, put card there
			for(int j = 0; j<20; j++){
				if(Battlefield[j] == CARD_NOCARD){
					Battlefield[j] = CardBuffer;
					break;
				}
			}
		}

		// Calculate hydra damage (or just show battlefield, and let player calculate it itself)
		cprint("Hydra Attack Phase!\r\n", COLOR_RED);
		dumpBattlefield(Battlefield);
		printf("End of Hydra turn.\r\n");
	}
	system ("/bin/stty cooked");
	return 0;
}
