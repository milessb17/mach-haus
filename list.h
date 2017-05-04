#include<stdio.h>

typedef struct block{
    int vlu;
    struct block *prx;
}blk;

typedef struct{
    blk *first;
    blk *last;
}hdr;

hdr* create();

void clr_list(hdr* list);

void insert(hdr* list, int pos);

void insert_ini(hdr* list);

void insert_end(hdr* list);

void remv(hdr* list, int vlu);

void print(hdr* list, int vlu);