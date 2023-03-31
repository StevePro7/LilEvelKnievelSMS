#include "util_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include "../banks/bank2.h"
#include <stdlib.h>

#define LOCALE_ROM_BANK		2
#define BYTE_NIBBLE_MASK	0x0F

// Locale Manager.
void engine_util_manager_locale_texts( unsigned char index, unsigned char x, unsigned char y )
{
	unsigned char *text;
	devkit_SMS_mapROMBank( LOCALE_ROM_BANK );
	text = ( unsigned char * ) locale_object_texts[ index ];
	engine_font_manager_text( text, x, y );
}

void engine_util_manager_locale_blank( unsigned char index, unsigned char x, unsigned char y )
{
	unsigned char *blank;
	devkit_SMS_mapROMBank( LOCALE_ROM_BANK );
	blank = ( unsigned char * ) locale_object_blank[ index ];
	engine_font_manager_text( blank, x, y );
}

// Maths Manager.
// TODO delete - is causing issue!	Corrupting game level value in memory
//unsigned char engine_util_manager_calculate_level( unsigned char world, unsigned char round )
//{
//	// TODO test.
//	return world * MAX_ROUNDS + round;
//}
void engine_util_manager_convertByteToNibbles( unsigned char byte, unsigned char *upper_nibble, unsigned char *lower_nibble )
{
	*upper_nibble = ( byte >> 4 ) & BYTE_NIBBLE_MASK;
	*lower_nibble = byte & BYTE_NIBBLE_MASK;
}
void engine_util_manager_convertNibblesToByte( unsigned char upper_nibble, unsigned char lower_nibble, unsigned char *byte )
{
	*byte = lower_nibble | ( upper_nibble << 4 );
}

// Random Manager.
void engine_random_manager_rand()
{
	rand();
}
unsigned char engine_random_manager_next( unsigned int max )
{
	return rand() % max;
}