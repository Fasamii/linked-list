#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
    char *data;
    struct linked_list *next;
} linked_list;

void add_to_linkedlist(linked_list *parent, linked_list *new) {
    while(parent->next != NULL) { parent = parent->next; }
    parent->next = new;
}

void make_link(char *name, linked_list *parent) {
    
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

    linked_list *new = malloc(sizeof(linked_list));
    new->data = "fasa";
    new->next = NULL;
    add_to_linkedlist(parent, new);


    new = malloc(sizeof(linked_list));
    new->data = "misa";
    new->next = NULL;
    add_to_linkedlist(parent, new);

    new = malloc(sizeof(linked_list));
    new->data = "misa";
    new->next = NULL;
    add_to_linkedlist(parent, new);

    new = malloc(sizeof(linked_list));
    new->data = "misa";
    new->next = NULL;
    add_to_linkedlist(parent, new);

    new = malloc(sizeof(linked_list));
    new->data = "misa";
    new->next = NULL;
    add_to_linkedlist(parent, new);

    new = malloc(sizeof(linked_list));
    new->data = "misa";
    new->next = NULL;
    add_to_linkedlist(parent, new);

    print_linkedlist(parent);

    free_linkedlist(parent);
}