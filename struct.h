#ifndef STRUCT_H
#define STRUCT_H


typedef struct item {
    char value;
    struct item *next;
} Item;

typedef struct {
    Item *head;
    Item *tail;
} List;

List *list_input();
void list_print(const List *list);
void list_free(List *list);

#endif
