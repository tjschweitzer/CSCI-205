#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>


typedef struct Item_Struct
{
	char data [20];
	struct Item_Struct* nextNodePtr;
} item;


#endif