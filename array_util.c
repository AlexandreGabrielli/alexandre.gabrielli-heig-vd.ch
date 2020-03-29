#include "include/array_util.h"


/* Liberate array memory */
void array_clear(uint64_t *data) {
    free(data);
}


/* Allocate an array of size "len" and fill it
 * with random data.
 * Return the array pointer */
uint64_t *array_init(const size_t len) {
    srand((unsigned) 1991);
    uint64_t *ptr = (uint64_t *) malloc(len * sizeof(uint64_t));
    size_t i;
    for (i = 0; i < len; i++) {
        ptr[i] = rand();
    }
    return ptr;
}

/* Arrange a array in increasing order of value */
void array_sort(uint64_t *data, const size_t len) {
    size_t i = 0, j = 0, tmp;
    for (i = 0; i < len; i++) {   // loop n times - 1 per element
        for (j = 0; j < len - i - 1; j++) { // last i elements are sorted already
            if (data[j] > data[j + 1]) {  // swop if order is broken
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }

}

/*this function print the array */
void print_array(uint64_t *data, const size_t len) {
    printf("[");
    size_t i = 0;
    do {
        long unsigned int * pointeur = data;
        i++;
        printf("%lu",*pointeur);
    } while (i < len && printf(","));
    printf("]\n");

}