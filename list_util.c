#include "include/list_util.h"


/* A list_element must at least contain a link to the next
 * element, as well as a uint64_t data value */
struct list_element {
    uint64_t data;
    struct list_element *next;
};

/* Allocate "len" linked elements and initialize them
 * with random data.
 * Return list head */
struct list_element *list_init(size_t len) {
    srand((unsigned) 1991);
    struct list_element *head = (struct list_element *) malloc(sizeof(struct list_element));
    head->data = rand();
    head->next = NULL;
    size_t i;
    struct list_element *current = head;
    for (i = 0; i < len; i++) {
        current->next = (struct list_element *) malloc(sizeof(struct list_element));
        current = current->next;
        current->next = NULL;
        current->data = rand();
    }
    return head;
}

/* Liberate list memory */
void list_clear(struct list_element *head) {
    struct list_element *next = head;
    struct list_element *nextNext;
    while (next != NULL) {
        nextNext = next->next;
        free(next);
        next = nextNext;
    }
}

/*this function print the list*/
void print_list(struct list_element *head) {
    struct list_element *next = head;
    printf("{");
    do {
        next = next->next;
    } while (next != NULL && printf(","));
    printf("}\n");
}

/* function to swap data of two nodes a and b*/
void swap(struct list_element *a, struct list_element *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/* Arrange a list in increasing order of value */
void list_sort(struct list_element *start) {
    int swapped;
    struct list_element *ptr1;
    struct list_element *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

