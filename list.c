#include<stdio.h>
#include<stdlib.h>
#include"list.h"

hdr* create(){
    hdr* ptr = (hdr*) malloc(sizeof(hdr));

        if(ptr==NULL){
            printf("\nAllocation Failed\n\n");
            exit(1);
        }

        ptr->first = NULL;
        ptr->last = NULL;

    return ptr;
}

void clr_list(hdr* list){
    blk* ptr = list->first;

        while(ptr!=NULL){
            ptr->first = ptr->prx;
            free(ptr->prx);
            ptr = ptr->first;
        }
    free(ptr);
}
/*
void insert(hdr* list, int pos);

void insert_ini(hdr* list);

void insert_end(hdr* list);

void remv(hdr* list, int vlu);

void print(hdr* list, int vlu);*/