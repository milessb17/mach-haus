#include <stdio.h>

/*---Data Types---*/

typedef struct contact{
	char name[20];
	char email[35];
	char nmb[14];
	struct contact* prx;
}cnt;


typedef struct header{
	struct contact* first;
	struct contact* last;
}hdr;

//end Data Types


/*---Functions---*/

hdr* create(); // - done

void lblist(hdr* addb); // - done

void insert(hdr* addb); // -done

void sortng(hdr* addb);

void remv(hdr* addb); // - done

void shw(hdr* addb); // - done

void list(hdr* addb); // - done

int srch(hdr* addb, char name[20]); // - done

void edt(hdr* addb); // - done

//end Functions