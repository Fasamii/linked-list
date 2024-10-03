#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
    char *data;
    struct linked_list *next;
} linked_list;

void add_to_linkedlist(linked_list *parent, char *data) {
    linked_list *node = malloc(sizeof(linked_list));
    node->data = data;
    node->next = NULL;
    while(parent->next != NULL) { parent = parent->next; }
    parent->next = node;
}

void print_linkedlist(linked_list *node) {
    printf("addr:<| %p |> - data:<| %s |>\n",node, node->data);
    while(node->next != NULL) {
        node = node->next;
        printf("addr:<| %p |> - data:<| %s |>\n",node, node->data);
    }
}

void free_linkedlist(linked_list *node) {
    if(node->next != NULL) {
        free_linkedlist(node->next);
    }
    free(node);
}

int main(void) {

    linked_list *parent = malloc(sizeof(linked_list));
    parent->data = "ajaj";
    parent->next = NULL;

    add_to_linkedlist(parent, "fasa");
    add_to_linkedlist(parent, "kasa");
    add_to_linkedlist(parent, "masa");

    print_linkedlist(parent);

    free_linkedlist(parent);
}