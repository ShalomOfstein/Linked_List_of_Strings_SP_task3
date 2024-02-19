#include <stdio.h>
#include <string.h>
#include "StrList.h"
/*
 * StrList represents a StrList data structure.
 */


//---------------------------------------------------------------------------------
// defining the node structure
//---------------------------------------------------------------------------------
typedef struct _StrListNode {
    char* _data;
    struct _StrListNode* _next;
}StrListNode;

StrListNode* StrListNode_alloc(const char* data, StrListNode* next) {
    StrListNode* p= (StrListNode*)malloc(sizeof(StrListNode));
    p->_data= strdup(data);
    p->_next= next;
    return p;
}

void StrListNode_free(StrListNode* node) {
    free(node);
}



//---------------------------------------------------------------------------------
// defining the List structure
//---------------------------------------------------------------------------------

typedef struct _StrList {
    StrListNode* _head;
    size_t _size;
}StrList;



/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc(){
    StrList* p= (StrList*)malloc(sizeof(StrList));
    p->_head= NULL;
    p->_size= 0;
    return p;
}

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* StrList){
    if (StrList==NULL) return;
    StrListNode* p1= StrList->_head;
    StrListNode* p2;
    while(p1) {
        p2= p1;
        p1= p1->_next;
        StrListNode_free(p2);
    }
    free(StrList);
}

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList* StrList){
    return StrList->_size;
}

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList* StrList, const char* data){
    StrListNode* p= StrListNode_alloc(data,NULL);
    if (StrList->_head==NULL) {
        StrList->_head= p;
    } 
    else {
        StrListNode* q= StrList->_head;
        while(q->_next) {
            q= q->_next;
        }
        q->_next= p;
    }
    StrList->_size++;
}

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList,
	const char* data,int index){
    StrListNode* newNode= StrListNode_alloc(data,NULL);
        if (StrList->_head==NULL) {
        StrList->_head= newNode;
        } 
        else {
            StrListNode* q= StrList->_head;
            for(int i=0;i<index-1;i++){
                q= q->_next;
            }
            newNode->_next= q->_next;
            q->_next= newNode;
        }
        StrList->_size++;
    }

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList){
    return StrList->_head->_data;
}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList){
    StrListNode* p= StrList->_head;
    while(p) {
        printf("%s\n",p->_data); // is this right????????????????????????????????????????????????????
        p= p->_next;
    }

}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index){
    StrListNode* p= Strlist->_head;
    for(int i=0;i<index;i++){
        p= p->_next;
    }
    printf("%s\n",p->_data); // is this right????????????????????????????????????????????????????
}

/*
 * Return the amount of chars in the list.
*/
// int StrList_printLen(const StrList* Strlist){
//     StrListNode* n= Strlist->_head;
//     int count=0;
//     while(n){
//         count+= strlen(n->_data);
//         n= n->_next;
//     }
//     return count;
// }

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data){
    StrListNode* p= StrList->_head;
    int count=0;
    while(p) {
        if (strcmp(p->_data,data)==0) {
            count++;
        }
        p= p->_next;
    }
    return count;

}

/*
	Given a string and a list, remove all the appearences of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data){
    StrListNode* p= StrList->_head;
    StrListNode* q =NULL;
    while(p) {
        if (strcmp(p->_data,data)==0) {
            if(q==NULL){
                StrList->_head= p->_next;
            }
            else{
                q->_next= p->_next;
            }
            
            StrListNode_free(p);
            StrList->_size--;
            free(p->_data);
            free(p);
            p=q->_next;
        }
        else{
            q= p;
            p= p->_next;  
        }
        
    }
}

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index){
    
}


/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2);

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StrList);

/*
 * Reverces the given StrList. 
 */
void StrList_reverse( StrList* StrList);

/*
 * Sort the given list in lexicographical order 
 */
void StrList_sort( StrList* StrList);

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList);
