/*
 * File: mylinkedlist.c
 * YOUR NAME ... 
 * YOU NEED TO IMPLEMENT THE FUNCTIONS  here
 * 
 * Pete Acevedo - ahu561
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"
 
/*
 * Function: NewStudentCell
 * Usage: student_cell_T *element;
 *        element = NewStudentCell(int id, double gpa, char *name);
 * --------------------------
 * This function allocates space for a student cell and intilize its fileds
 */
student_cell_T *NewStudentCell(int id, double gpa, char *name)
{
   student_cell_T *element;
  
   element = (student_cell_T *) malloc( sizeof(student_cell_T) );
   if( !element){
     fprintf(stderr,"NewStudentCell cannot allocate memory\n");
     return NULL;
   }
   element->id = id;
   element->gpa = gpa;
   element->name = name;

  return element;
}


/*
 * Function: NewLinkedList
 * Usage: linked_list_T *list;
 *        list = NewLinkedList();
 * --------------------------
 * This function allocates and returns an empty linked list.
 */
linked_list_T *NewLinkedList(void)
{
   linked_list_T *list;
  
   list = (linked_list_T *) malloc( sizeof(linked_list_T) );
   if( !list){
     fprintf(stderr,"NewLinkedList cannot allocate memory\n");
     return NULL;
   }

   list->head = NULL;
   list->tail = NULL;

  return list;
}


/*
 * Function: FreeLinkedList
 * Usage: FreeLinkedList(list);
 * ------------------------
 * This function frees the storage associated with list.
 */
void FreeLinkedList(linked_list_T *list)
{
    free(list);
}

/*
 * Function: Enlist
 * Usage: Enlist(list, element);
 * -------------------------------
 * This function adds a student cell pointed by element to the end of the list.
 */
void Enlist(linked_list_T *list, student_cell_T *element)
{
    if (list->head == NULL) {
        list->head = element;
    }
    
    else
    {
        struct student_cell_T *lastNode = element;
        while(element->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = element;
    }
}

/*
 * Function: Delist
 * Usage: element = Delist(list);
 * --------------------------------
 * This function removes the student cell at the head of the list
 * and returns its address to the caller (client).  If the list is empty, Delist
 * prints an Error with an appropriate message and returns NULL.
 */
student_cell_T *Delist(linked_list_T *list)
{
    if (list->head == NULL) {
        printf("ERROR: List is empty!");
        return 0;
    }
    else
    {
        struct student_cell_T* DelistNode = list->head;
        list->head = DelistNode->next;
        return DelistNode;
    }
    
}

/*
 * Functions: LinkedListIsEmpty, LinkedListIsFull
 * Usage: if (LinkedListIsEmpty(list)) . . .
 *        if (LinkedListIsFull(list)) . . .
 * -------------------------------------
 * These functions test whether the list is empty or full.
 */
int LinkedListIsEmpty(linked_list_T *list)
{
    if (list->head == NULL) {
        return 1;
    }
    else{
        return 0;
    }
}

int LinkedListIsFull(linked_list_T *list)
{
  return 0; // because we have linked list
}

/*
 * Function: LinkedListLength
 * Usage: n = LinkedListLength(list);
 * ------------------------------
 * This function returns the number of elements in the list.
 */
int LinkedListLength(linked_list_T  *list)
{
    int count = 0;

    struct student_cell_T *currentNode = list->head;
    while (currentNode != NULL){
        currentNode = currentNode->next;
        count++;
    }
    return count;
}

/*
 * Function: GetLinkedListElement
 * Usage: element = GetLinkedListElement(list, index);
 * -----------------------------------------------
 * This function returns the element at the specified index in the
 * list, where the head of the list is defined as index 0. For
 * example, calling GetLinkedListElement(list, 0) returns the initial
 * element from the list without removing it.  If the caller tries
 * to select an element that is out of range, GetLinkedListElement prints
 * Error and returns NULL.  Note: This function is not a fundamental list operation
 * and is instead provided mainly to facilitate debugging.
 */
student_cell_T *GetLinkedListElement(linked_list_T *list, int index)
{
    int count = 0;
   
    if(index == 0){
        return list->head;
    }

    struct student_cell_T *currentNode = list->head;
    while (currentNode != NULL){
        if (count == index)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
        count++;

    }
    return NULL;
}

void printList(linked_list_T* list, student_cell_T* element) {
    printf("Contents are as follows: %d, %f, %s \n", element->id, element->gpa, element->name);
}



/* OTHER FUNCTIONS YOU WOULD NEED....
 * EXPORT THEM HERE, BUT IMPLMENT THEM in mylinkedlist.c 
 */

  