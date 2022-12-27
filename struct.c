#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

void list_print(const List *list) {
    printf("\"");
    Item *ptr = list -> head;
    while (ptr != NULL) {
        printf("%c", ptr -> value);
        ptr = ptr -> next;
    }
    printf("\"\n");
}

List *list_input() {
    List *list = (List *)malloc(1 * sizeof(List));
    Item *new = (Item *)malloc(1 * sizeof(Item));
    new -> value = getchar();
    if (new -> value == EOF) {
        free(new);
        free(list);
        return NULL;
    }
    list -> head = new;
    Item *prev = NULL;
    while (new -> value != '\n') {
        prev = new;
        new = malloc(1 * sizeof(Item));
        new -> value = getchar();
        prev -> next = new;
    }
    free(new);
    if (prev != NULL) {
        prev -> next = NULL;
        list -> tail = prev;
    }
    else {
        list -> head = NULL;
    }
    list -> tail -> next = NULL;
    return list;
}

void list_free(List *list) {
    Item *ptr = list -> head, *ptr_prev;
    while (ptr != NULL) {
        ptr_prev = ptr;
        ptr = ptr -> next;
        free(ptr_prev);
    }
    free(list);
}

