// BST.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h" // defines 'Item' structure

typedef struct BSTNode* link;
struct BSTNode { Item item; link pLeft, pRight; };

// The null item to represent children of leaf nodes
static Item NullItem;

static link head; // 'head' points to root (private var)

// NEW() function creates a new tree node using malloc()
link NEW(Item item, link left, link right) 
{
    link pNew = (link)malloc(sizeof(*pNew));
    pNew->item = item;
    pNew->pLeft = left;
    pNew->pRight = right;
    return pNew;
}

// Create an empty Binary Search Tree
void BSTInit(void)
{
    head = NULL;
    NullItem.buff = NULL;
}

// Search for a key in the BST (using szKey in struct Item)
Item BSTSearch(link h, char* szSearchKey)
{
    int rc;
    if (h == NULL) return NullItem; // Got to end & not found
    rc = strcmp(szSearchKey, h->item.buff);
    if (rc == 0) return h->item; // Found it
    if (rc < 0) return BSTSearch(h->pLeft, szSearchKey);
    else return BSTSearch(h->pRight, szSearchKey);
}

Item Search(char* szKey) 
{
    return BSTSearch(head, szKey);
}

// Insert a key in the BST. Uses szKey as before
link BSTInsert(link h, Item item) 
{
    int rc;
    if (h == NULL) return NEW(item, NULL, NULL); // insert pt
    rc = strcmp(item.buff, h->item.buff); // Go left or right?
    if (rc < 0) 
    {
        h->pLeft = BSTInsert(h->pLeft, item);
    }
    else 
    {
        h->pRight = BSTInsert(h->pRight, item);
    }
    return h; // pointer to (new/existing) child
}

void Insert(Item item)
{
    head = BSTInsert(head, item);
}

// Count Nodes in the BST
int BSTCountNodes(link h)
{
    if (h == NULL) return 0;
    return 1 + BSTCountNodes(h->pLeft) + BSTCountNodes(h->pRight);
}

int CountNodes()
{
    return BSTCountNodes(head);
}

// Determine Tree Height
int BSTTreeHeight(link h) 
{
    if (h == NULL) return -1;
    int leftHeight = BSTTreeHeight(h->pLeft);
    int rightHeight = BSTTreeHeight(h->pRight);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int TreeHeight() 
{
    return BSTTreeHeight(head);
}

// In-order traversal to print items in sorted order
void BSTInOrderTraversal(link h)
{
    if (h != NULL) 
    {
        BSTInOrderTraversal(h->pLeft);
        printf("%s ", h->item.buff);
        BSTInOrderTraversal(h->pRight);
    }
}
// Printing Binary Search Tree Elements in Sorted Order
void PrintSortedOrder() 
{
    printf("Chars in sorted order: ");
    BSTInOrderTraversal(head);
    printf("\n");
}
