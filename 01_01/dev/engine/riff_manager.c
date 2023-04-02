#include "riff_manager.h"
#include "hack_manager.h"
#include "sample_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"

const unsigned char psgInit[] =
{
	0x9F, 0xBF, 0xDF, 0xFF, 0x81, 0x00, 0xA1, 0x00, 0x00, 0xC1, 0x00
};

void engine_riff_manager_init()
{
	engine_sample_manager_init( psgInit );
}

void engine_riff_manager_loop( unsigned char index )
{
	// Generic function that loops an entire riff.
	unsigned char loops, count, value;

	engine_riff_manager_init();
	value = riff_indexs[ index ];
	count = riff_counts[ index ];
	for( loops = 0; loops < count; loops++ )
	{
		engine_riff_manager_play( loops + value );
	}
}

void engine_riff_manager_play( unsigned char index )
{
	struct_hack_object *ho = &global_hack_object;
	const unsigned char *data;
	unsigned char bank;

	if( !ho->hack_riffs )
	{
		return;
	}

	devkit_SMS_mapROMBank( FIXED_BANK );
	data = riff_sample_data[ index ];
	bank = riff_sample_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	engine_sample_manager_play( data );
}