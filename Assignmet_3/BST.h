// BST.h

#ifndef BST_H
#define BST_H

// Function declarations for Binary Search Tree
void BSTInit(void);
Item Search(char* szKey);
void Insert(Item item);
int CountNodes();
int TreeHeight();
void PrintSortedOrder();

#endif 
