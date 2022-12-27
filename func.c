#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void linb(List *list, char c) {
    Item *pr = (Item *)malloc(1 * sizeof(Item));
    pr -> value = c;
    list -> tail -> next = pr;
    list -> tail = pr;
}

int func(List *list) {
    Item *p = list -> head;
    char z = '+';
    int res = 0;
    int op = 0;
    int e1 = 0, e2 = 0;
    while (e1 == 0) {
        op = 0;
        while ((p -> value != ' ') && e2 == 0) {
            op = (int)(p -> value) - 48 + op * 10;
            //printf("\nop = %d",op);
            if (p -> next == NULL) e2 = 1;
            else p = p -> next;
        }
        if (z == '-') res = res - op;
        else if (z == '+') res = res + op;
        else return 1;
            if (p != list -> tail) {
                p = p -> next;
                z = p -> value;
                p = p -> next;
                p = p -> next;
            }
            else e1 = 1;  
    }
    linb(list, ' ');
    linb(list, '=');
    linb(list, ' ');
    if (res == 0) {
        linb(list, '0');
        return 0;
    }
    if (res < 0) linb(list, '-');
    res = abs(res);
    p = list -> tail;
    int e = 0;
    while (res != 0) {
        z = (char)((res % 10) + 48);
        Item *in = (Item *)malloc(1 * sizeof(Item));
        in -> next = p -> next;
        p -> next = in;
        in -> value = z;
        if (e != 1) {
            list -> tail = in;
            e = 1;
        }
        res = res / 10;
    }
    return 0;
}
