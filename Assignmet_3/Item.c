// Item.c

#include <stdlib.h>
#include <string.h>
#include "Item.h"

// Function to create a new Item with a copy of the given string
Item createItem(char* str) 
{
    Item newItem;
    newItem.buff = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy_s(newItem.buff, strlen(str) + 1, str);
    return newItem;
}


// Function to free memory allocated for the Item's string
void freeItem(Item* item)
{
    free(item->buff);
    item->buff = NULL;
}
