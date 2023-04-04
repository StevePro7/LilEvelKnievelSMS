#include "scroll_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "sprite_manager.h"
#include "../devkit/_sms_manager.h"

//#define PARALLAX_SCROLLING		0
#define SCROLL_COLUMNS			8
#define SCROLL_PARA_ARRAY		6
#define SCROLL_LINE_COUNT		30

// Global variable.
struct_scroll_object global_scroll_object;

#ifdef _CONSOLE
#else
#pragma disable_warning 126
#pragma disable_warning 158
#endif

// Private helper function.
static void lineScrollHandler( void );

void engine_scroll_manager_load( unsigned char screen, int scrollPoints, int scrollFinish )
{
	engine_scroll_manager_full_load( screen, scrollPoints, scrollFinish );
}

enum_scroll_state engine_scroll_manager_update( unsigned char delta )
{
	return engine_scroll_manager_full_update( delta );
}

void engine_scroll_manager_full_load( unsigned char screen, int scrollPoints, int scrollFinish )
{
	struct_scroll_object *so = &global_scroll_object;
	so->scrollLeftX = 0;
	so->scrollRight = 0;
	
	so->scrollColumn = ( screen * SCREEN_WIDE ) + SCREEN_LESS_ONE;
	so->scrollChecks = 0;
	so->scrollPoints = scrollPoints;
	so->scrollFinish = scrollFinish;
	devkit_SMS_setBGScrollX( so->scrollLeftX );
	devkit_SMS_disableLineInterrupt();
}
enum_scroll_state engine_scroll_manager_full_update( unsigned char delta )
{
	struct_scroll_object *so = &global_scroll_object;
	enum_scroll_state scroll_state;

	so->scrollLeftX -= delta;
	so->scrollRight += delta;
	scroll_state = scroll_state_none;

	// Scroll pixel by pixel.
	devkit_SMS_setBGScrollX( so->scrollLeftX );

	if( so->scrollRight >= SCROLL_COLUMNS )
	{
		so->scrollRight = 0;
		if( so->scrollColumn == so->scrollFinish )
		{
			scroll_state = scroll_state_comp;
		}
		if( so->scrollChecks == so->scrollPoints )
		{
			so->scrollChecks = 0;
			scroll_state = scroll_state_line;
		}
	}

	if( delta > 0 )
	{
		if( delta == so->scrollRight )
		{
			scroll_state = scroll_state_tile;
			so->scrollColumn++;
			so->scrollChecks++;
		}
	}

	return scroll_state;
}

void engine_scroll_manager_para_load( unsigned char screen, int scrollFinish )
{
	struct_scroll_object *so = &global_scroll_object;
	so->scrollLeftX = 0;
	so->scrollRight = 0;
	so->scrollColumn = ( screen * SCREEN_WIDE ) + SCREEN_LESS_ONE;
	so->scrollChecks = 0;
	so->scrollPoints = 0;		// not used here.
	so->scrollFinish = scrollFinish;
	devkit_SMS_setBGScrollX( so->scrollLeftX );

	so->scrollLeftX0 = 0;
	so->scrollLeftX1 = 0;
	so->scrollLeftX2 = 0;
	so->scrollLeftX3 = 0;
	so->scrollLeftX4 = 0;
	so->scrollLeftX5 = 0;
	so->scroll_half = 0;
	so->lineCnt = 0;

	devkit_SMS_setLineInterruptHandler( &lineScrollHandler );
	devkit_SMS_setLineCounter( SCROLL_LINE_COUNT );
	devkit_SMS_enableLineInterrupt();
}
enum_scroll_state engine_scroll_manager_para_update( unsigned char delta )
{
	struct_scroll_object *so = &global_scroll_object;
	enum_scroll_state scroll_state;

	so->scrollLeftX -= delta;
	so->scrollRight += delta;
	scroll_state = scroll_state_none;

	if( so->scrollRight >= SCROLL_COLUMNS )
	{
		so->scrollRight = 0;
		if( so->scrollColumn == so->scrollFinish )
		{
			scroll_state = scroll_state_comp;
		}
	}

	if( delta > 0 )
	{
		if( delta == so->scrollRight )
		{
			scroll_state = scroll_state_tile;
			so->scrollColumn++;
		}
	}

	// Scroll game screen at full pace.
	so->scrollLeftX1 -= delta;
	so->scrollLeftX2 -= delta;
	so->scrollLeftX3 -= delta;
	so->scrollLeftX4 -= delta;
	so->scrollLeftX5 -= 0;
	so->lineCnt = 0;

	return scroll_state;
}

enum_scroll_state engine_scroll_manager_demo_update( unsigned char delta )
{
	struct_scroll_object *so = &global_scroll_object;
	enum_scroll_state scroll_state;

	so->scrollLeftX -= delta;
	so->scrollRight += delta;
	scroll_state = scroll_state_none;

	if( so->scrollRight >= SCROLL_COLUMNS )
	{
		so->scrollRight = 0;
		if( so->scrollColumn == so->scrollFinish )
		{
			scroll_state = scroll_state_comp;
		}
	}

	if( delta > 0 )
	{
		if( delta == so->scrollRight )
		{
			scroll_state = scroll_state_tile;
			so->scrollColumn++;
		}

		// Scroll cloud section at half pace.
		so->scroll_half = 1 - so->scroll_half;
		so->scrollLeftX0 -= so->scroll_half;
	}

	// Scroll game screen at full pace.
	so->scrollLeftX1 -= delta;
	so->scrollLeftX2 -= delta;
	so->scrollLeftX3 -= delta;
	so->scrollLeftX4 -= delta;
	so->scrollLeftX5 -= 0;
	so->lineCnt = 0;

	return scroll_state;
}

static void lineScrollHandler( void )
{
	struct_scroll_object *so = &global_scroll_object;
	unsigned char index, value;

	index = so->lineCnt;
	value = 0;
	if( index < SCROLL_PARA_ARRAY )
	{
		if( 0 == so->lineCnt )
		{
			value = so->scrollLeftX0;
		}
		else if( 1 == so->lineCnt )
		{
			value = so->scrollLeftX1;
		}
		else if( 2 == so->lineCnt )
		{
			value = so->scrollLeftX2;
		}
		else if( 3 == so->lineCnt )
		{
			value = so->scrollLeftX3;
		}
		else if( 4 == so->lineCnt )
		{
			value = so->scrollLeftX4;
		}
		else if( 5 == so->lineCnt )
		{
			value = so->scrollLeftX5;
		}

		so->lineCnt++;
		devkit_SMS_setBGScrollX( value );
	}
}
