#include <stdio.h>
#include "board.h"

int main(){
	hdr* bkk1;

	bkk1 = create();

	insert(bkk1);
	insert(bkk1);
	//insert(bkk1);

	//insert(bkk1);
	
	remv(bkk1);

	edt(bkk1);
	shw(bkk1);
	
	insert(bkk1); //inserir um contato
	remv(bkk1); //remove-lo
	shw(bkk1); //tentar encontra-lo

	list(bkk1);

	lblist(bkk1);

	/*- problems: pegar o caracter
				  funcao shw 		-*/

	printf("\n\nit's done bro\n");
	return 0;
}