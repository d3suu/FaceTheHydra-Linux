// Definiton of all cards, so its easier to read the code
// #define NAME ID

#define CARD_NOCARD	0	// No card, null, nothing, void

#define CARD_HYDRAHEAD	1	// Hydra Head (standard)
#define CARD_BRUTEHEAD	2	// Ravenous Brute Head
#define CARD_VIGORHEAD	3	// Savage Vigor Head
#define CARD_FANGHEAD	4	// Snapping Fang Head
#define CARD_TITANHEAD	5	// Shrieking Titan Head

#define CARD_GLOWER	6	// Disorienting Glower
#define CARD_DISTRACT	7	// Distract the Hydra
#define CARD_GROWN	8	// Grown from the Stump
#define CARD_HIDE	9	// Hydra's Impenetrable Hide
#define CARD_TANGLE	10	// Neck Tangle
#define CARD_BREATH	11	// Noxious Hydra Breath
#define CARD_WEAKSPOT	12	// Strike the Weak Spot
#define CARD_SWALLOW	13	// Swallow the Hero Whole
#define CARD_TORN	14	// Torn Between Heads
#define CARD_LUNGE	15	// Unified Lunge

void dumpBattlefield(int* battlefield);
void dumpLibrary(int* library);
char* cardIDtoString(int id);
char* cardIDtoTextbox(int id);
