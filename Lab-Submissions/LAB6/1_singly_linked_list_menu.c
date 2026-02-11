#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin() {
    int x;
    struct node *n = malloc(sizeof(struct node));
    scanf("%d", &x);
    n->data = x;
    n->next = head;
    head = n;
}

void insert_end() {
    int x;
    struct node *n = malloc(sizeof(struct node));
    scanf("%d", &x);
    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    struct node *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = n;
}

void insert_pos() {
    int x, pos, i = 1;
    scanf("%d %d", &x, &pos);

    if (pos == 1) {
        insert_begin();
        return;
    }

    struct node *n = malloc(sizeof(struct node));
    n->data = x;

    struct node *t = head;
    while (i < pos - 1 && t != NULL) {
        t = t->next;
        i++;
    }

    if (t == NULL)
        return;

    n->next = t->next;
    t->next = n;
}

void delete_begin() {
    if (head == NULL)
        return;
    struct node *t = head;
    head = head->next;
    free(t);
}

void delete_end() {
    if (head == NULL)
        return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *t = head;
    while (t->next->next != NULL)
        t = t->next;

    free(t->next);
    t->next = NULL;
}

void delete_pos() {
    int pos, i = 1;
    scanf("%d", &pos);

    if (pos == 1) {
        delete_begin();
        return;
    }

    struct node *t = head;
    while (i < pos - 1 && t != NULL) {
        t = t->next;
        i++;
    }

    if (t == NULL || t->next == NULL)
        return;

    struct node *d = t->next;
    t->next = d->next;
    free(d);
}

void display() {
    struct node *t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void modify_by_value() {
    int oldv, newv;
    scanf("%d %d", &oldv, &newv);

    struct node *t = head;
    while (t != NULL) {
        if (t->data == oldv) {
            t->data = newv;
            return;
        }
        t = t->next;
    }
}

void modify_by_pos() {
    int pos, newv, i = 1;
    scanf("%d %d", &pos, &newv);

    struct node *t = head;
    while (i < pos && t != NULL) {
        t = t->next;
        i++;
    }

    if (t != NULL)
        t->data = newv;
}

int main() {
    int ch;
    while (1) {
        scanf("%d", &ch);

        if (ch == 1) insert_begin();
        else if (ch == 2) insert_end();
        else if (ch == 3) insert_pos();
        else if (ch == 4) delete_begin();
        else if (ch == 5) delete_end();
        else if (ch == 6) delete_pos();
        else if (ch == 7) display();
        else if (ch == 8) modify_by_value();
        else if (ch == 9) modify_by_pos();
        else break;
    }
    return 0;
}
