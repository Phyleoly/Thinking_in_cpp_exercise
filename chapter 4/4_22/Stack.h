#ifndef _STACK_H
#define _STACK_H

struct Stack {
    struct Link {
        void *data;
        Link *next;
        void initialize(void *dat, Link *nxt);
    } *head;
    void initialize();
    void push(void *dat);
    void *peek();
    void *pop();
    void cleanup();
};

#endif