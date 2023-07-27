// main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "BST.h" // Including the declarations of BST functions

// Function to generate a random lowercase character between 'a' and 'z'
char getRandomChar() 
{
    return 'a' + rand() % 26;
}

// Function to generate a random string of length 'len'
char* getRandomString(int len) 
{
    char* str = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) 
    {
        str[i] = getRandomChar();
    }
    str[len] = '\0';
    return str;
}


int main() 
{
    srand((unsigned int)time(NULL));
    BSTInit(); // Initialize the Binary Search Tree

    int numOfChars = 11 + rand() % 10; // Generate random number of chars (between 11 and 20)
    printf("Number of chars to be inserted: %d\n", numOfChars);

    // Insert random characters into the tree
    for (int i = 0; i < numOfChars; i++) 
    {
        char* randomStr = getRandomString(1);
        Item item = { randomStr };
        Insert(item);
        // Note that we don't need to use createItem here.
        // The 'Item' structure has a 'char*' member, so we can directly assign the pointer.
    }

    // Print the chars inserted into the tree in sorted alphabetical order
    PrintSortedOrder();

    // Print the number of nodes in the tree
    int numNodes = CountNodes();
    printf("Number of nodes in the tree: %d\n", numNodes);

    // Print the tree height
    int height = TreeHeight();
    printf("Tree height: %d\n", height);

    return 0;
}
