#include <stdio.h>
#include <stdlib.h>

#include "func.h"
#include "struct.h"

int main() {
    int t = 0;
    List *list = list_input();
    while (list != NULL) {
        if (list -> head != NULL) {
            t = func(list);
            if (t == 0) list_print(list);
            else printf("Ошибка\n");
            list_free(list);
        }
        else free(list);   
        list = list_input();
    }
}
