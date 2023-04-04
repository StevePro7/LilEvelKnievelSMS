#include "font_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/bank2.h"

#define TEXT_ROOT	32		// 32 is " " in ASCII.
#define DATA_ROOT	16		// 16 is "0" (48=16+32)
#define UNIT_ROOT	10		// 10 is decimal
#define DATA_LONG	5		// 5 placeholder
#define SING_LONG	1		// 1 placeholder

static void print_data( unsigned wide, unsigned int data, unsigned char x, unsigned char y );

void engine_font_manager_char( unsigned char ch, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = bggame_tiles__tilemap__bin;
	unsigned char tile = ch - TEXT_ROOT;

	devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
	devkit_SMS_setNextTileatXY( x, y );
	devkit_SMS_setTile( *pnt + tile );
}

void engine_font_manager_text( unsigned char *text, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = bggame_tiles__tilemap__bin;
	unsigned char idx = 0;

	devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
	while( '\0' != text[ idx ] )
	{
		unsigned char tile = text[ idx ] - TEXT_ROOT;
		devkit_SMS_setNextTileatXY( x++, y );
		devkit_SMS_setTile( *pnt + tile );
		idx++;
	}
}

void engine_font_manager_data( unsigned int data, unsigned char x, unsigned char y )
{
	print_data( DATA_LONG, data, x, y );
}

void engine_font_manager_valu( unsigned int data, unsigned char x, unsigned char y )
{
	print_data( SING_LONG, data, x, y );
}

static void print_data( unsigned wide, unsigned int data, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = bggame_tiles__tilemap__bin;
	unsigned char idx;
	signed char tile;

	unsigned int quotient = 0;
	unsigned char remainder = 0;

	unsigned char hold[ DATA_LONG ];
	devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
	for( idx = 0; idx < wide; ++idx )
	{
		quotient = data / UNIT_ROOT;
		remainder = data % UNIT_ROOT;

		hold[ idx ] = remainder;
		data /= UNIT_ROOT;

		tile = hold[ idx ] + DATA_ROOT;
		if( 0 == quotient && 0 == remainder && idx > 0 )
		{
			// Replace with space!
			tile = 0;
		}

		devkit_SMS_setNextTileatXY( x--, y );
		devkit_SMS_setTile( *pnt + tile );
	}
}
