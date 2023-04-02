// Fixed  bank.
#define FIXED_BANK	15

// TODO delete this
extern const unsigned char *steven_text[];
extern const unsigned char steven_data[];


// Command Manager.
extern unsigned int demo_command_frame_index[];
extern unsigned char demo_command_this_command[];
extern unsigned int beat_command_frame_index[];
extern unsigned char beat_command_this_command[];


// FIXED bank.
// Audio Manager.
extern const unsigned char *music_object_data[];
extern const unsigned char music_object_bank[];

extern const unsigned char *sound_object_data[];
extern const unsigned char sound_object_bank[];

extern const unsigned char *riff_sample_data[];
extern const unsigned char riff_sample_bank[];


// Locale Manager.
//extern const unsigned char my_splash_text[];
//#define LOCALE_SPLASH_SCREEN	"(C)1987"
//#define LOCALE_TITLE1_SCREEN	"A TRIBUTE TO THE"
//#define LOCALE_TITLE2_SCREEN	"GREATEST DAREDEVIL"

//#define LOCALE_INTRO_SCREEN			"INSERT COIN(S)"
//#define LOCALE_INTRO_SCREEN1		"PRESS START"
//#define LOCALE_BLANK14				"              "
//#define LOCALE_INTRO_SCREEN2	   "12345INSERT COIN(S)12345"
//extern const unsigned char *locale_object_texts[];

//#define LOCALE_BLANK16		"                "

// Level Manager.
extern const unsigned char *level_object_data[];
extern const unsigned int level_object_size[];
extern const unsigned char level_object_bank[];


// TODO re-instate in fixed bank
// Player Manager.
extern const unsigned char player_object_starts[];


// todo delete
extern const unsigned char *extra_object_data[];
extern const unsigned int extra_object_size[];
extern const unsigned char extra_object_bank[];