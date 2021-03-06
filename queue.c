/*
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q)
    {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
    }
    return q;
}


/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* Free queue structure */
    if (!q) return;
    list_ele_t* t;
    while (q->head)
    {
        t = q->head->next;
        free(q->head->value);
        free(q->head);
        q->head = t;
    }
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh = malloc(sizeof(list_ele_t));
    int len = strlen(s);
    if (!q) goto error;
    if (!newh) goto error;
    newh->value = malloc((len + 1) * sizeof(char));
    if (!newh->value) goto error;
    strncpy(newh->value, s, len);
    newh->value[len] = '\0';
    newh->next = q->head;

    if (!q->head)
    {
        q->tail = newh;
    }
    q->head = newh;
    q->size++;
    return true;
error:
    if (newh) free(newh);
    return false;
}

/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newh = malloc(sizeof(list_ele_t));
    int len = strlen(s);
    if (!q) goto error;
    if (!newh) goto error;
    newh->value = malloc((len + 1) * sizeof(char));
    if (!newh->value) goto error;
    strncpy(newh->value, s, len);
    newh->value[len] = '\0';
    newh->next = NULL;

    if (!q->tail)
    {
        q->head = newh;
        q->tail = newh;
    }

    q->tail->next = newh;
    q->tail = newh;
    q->size++;
    return true;
error:
    if (newh) free(newh);
    return false;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (!q || !q->head) goto error;
    char* str = q->head->value;
    if (sp)
    {
        strncpy(sp, str, bufsize - 1);
        sp[bufsize - 1] = '\0';
    }
    list_ele_t* t = q->head;
    q->head = q->head->next;
    free(t->value);
    free(t);
    q->size--;
    if (q->size == 0) q->tail = NULL;
    return true;
error:
    return false;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (!q || !q->head) return 0;
    return q->size;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (!q || !q->head || !q->head->next) return;
    if (q->head == q->tail) return;

    q->tail = q->head;
    q->head = q->head->next;

    list_ele_t* back = q->tail, *curr = q->head->next;

    while (curr != NULL)
    {
        q->head->next = back;
        back = q->head;
        q->head = curr;
        curr = curr->next;
    }
    q->head->next = back;
    q->tail->next = NULL;
}
