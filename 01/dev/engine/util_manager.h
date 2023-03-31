#ifndef _UTIL_MANAGER_H_
#define _UTIL_MANAGER_H_

// Locale Manager.
//void engine_util_manager_locale_texts( unsigned char *text, unsigned char x, unsigned char y );
void engine_util_manager_locale_texts( unsigned char index, unsigned char x, unsigned char y );
void engine_util_manager_locale_blank( unsigned char index, unsigned char x, unsigned char y );

// Maths Manager.
//unsigned char engine_util_manager_calculate_level( unsigned char world, unsigned char round );
void engine_util_manager_convertByteToNibbles( unsigned char byte, unsigned char *upper_nibble, unsigned char *lower_nibble );
void engine_util_manager_convertNibblesToByte( unsigned char upper_nibble, unsigned char lower_nibble, unsigned char *byte );

// Random Manager.
void engine_random_manager_rand();
unsigned char engine_random_manager_next( unsigned int max );

#endif//#define _MATHS_MANAGER_H_