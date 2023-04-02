#ifndef _SCROLL_OBJECT_H_
#define _SCROLL_OBJECT_H_

typedef struct tag_struct_scroll_object
{
	// Full scroll.
	unsigned char scrollLeftX;
	unsigned char scrollRight;
	unsigned int scrollColumn;
	unsigned int scrollChecks;
	//unsigned int scrollDeltaX;
	unsigned int scrollPoints;
	unsigned int scrollFinish;

	// Para scroll.
	unsigned char scrollLeftX0;
	unsigned char scrollLeftX1;
	unsigned char scrollLeftX2;
	unsigned char scrollLeftX3;
	unsigned char scrollLeftX4;
	unsigned char scrollLeftX5;
	unsigned char scroll_half;
	unsigned char lineCnt;

} struct_scroll_object;

#endif//_SCROLL_OBJECT_H_