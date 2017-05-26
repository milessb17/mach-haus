#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

hdr* create(){
	hdr* ptr = (hdr*) malloc(sizeof(hdr));

		if(ptr==NULL){
			printf("\n\nAllocation Failed\n\n");
			exit(1);
		}

	ptr->first = NULL;
	ptr->last = NULL;

	return ptr;

}

void lblist(hdr* addb){
	cnt* axl;

	axl = addb->first;	

		while(axl!=NULL){
			addb->first = addb->first->prx;
			free(axl);
			axl = addb->first;
		}

	free(addb);
}

void insert(hdr* addb){
	cnt* new = (cnt*) malloc(sizeof(cnt));
	char opc;
	/*--Filling the spaces--*/

	printf("\nName: ");
	scanf("%[^\n]s%*c",new->name);
	getchar();

	printf("Email:" );
	scanf("%[^\n]s%*c",new->email);
	getchar();

	printf("Phone: ");
	scanf("%[^\n]s%*c",new->nmb);
	getchar();

	opc = srch(addb, new->name);
	
	if(opc!=-1){
		printf("\nContato ja existente. Se trata da mesma pessoa?\n");
		scanf("%c",&opc);

		if(opc == 'N' || opc == 'n'){
			printf("\nO novo contato sera adicionado.\n");
		}
		else{
			printf("Deseja editar o contato?");
			scanf("%c",&opc);

			if(opc == 'S' || opc == 's')
				edt(addb);
		}
	}

	if(addb->first == NULL){
		addb->first = new;
		addb->last = new;
		new->prx = NULL;
	}

	else{
		addb->last->prx = new;
		addb->last = new;
		new->prx = NULL;
	}

}

void remv(hdr* addb){
	
	cnt* axl = addb->first;
	
	char nxl[20];
	
	int src = 0, i = 0;

	printf("Informe o nome do contato a ser deletado: ");
	scanf("%[^\n]s%*c",nxl);
	getchar();
	
	src = srch(addb, nxl);

	if(src == -1){
		printf("\n\nContato inexistente! Retornando ao menu...\n\n");
	}
	else{
		for(i=0; i<=src; i++, axl = axl->prx){
			if(strcmp(axl->name, nxl) == 0){
				free(axl);
				printf("\n%s removido da lista de contatos.\n",nxl);
				break;}
											}
		}
}

void list(hdr* addb){
	cnt* axl;

	for(axl = addb->first; axl != NULL; axl = axl->prx){
		printf("--------------\n");
		printf("\nName: %s\n",axl->name);
		printf("Email: %s\n",axl->email);
		printf("Phone: %s\n",axl->nmb);
		printf("--------------\n");
	}
}

void edt(hdr* addb){
	int opt = 0;
	int i,src;
	cnt* axl = addb->first;
	char nxl[20];

	printf("Insira o nome do contato a ser editado: ");
	scanf("%[^\n]s%*c",nxl);

	src = srch(addb,nxl);

	if(src==-1){
		printf("\n\nContato inexistente!\n\n");
		return;
	}

	else{
		for (i=0; i<=src; i++, axl=axl->prx){
			if(strcmp(axl->name, nxl) == 0){
				printf("Informe o novo nome do contato: ");
				scanf(" %[^\n]s%*c",axl->name);
				getchar();

				printf("Informe o novo numero do contato: ");
				scanf("%[^\n]s%*c",axl->nmb);
				getchar();

				printf("Informe o novo email do contato: ");
				scanf("%[^\n]s%*c",axl->email);
				getchar();

				break;
			}	
		}
	}
	
	
}

int srch(hdr* addb, char name[20]){
	cnt* axl;
	int cont = 0;

	axl = addb->first;

	while(axl!=NULL){
		if(strcmp(axl->name, name) == 0){
			return cont;
			}	
		else{
			axl = axl->prx;
			cont++;}
					}
		return -1;
}

void shw(hdr* addb){

	cnt* axl = addb->first;

	char nxl[20];
	char resp = 'k';
	
	int src = 0, i  = 0;

	printf("\nQual contato você quer consultar?");
	scanf("%[^\n]s%*c",nxl);

	src = srch(addb, nxl);

	if(src==-1){
		printf("\nContato inexistente!. Deseja fazer outra consulta?:");
		scanf("%c",&resp);
			
			if(resp == 'S' || resp == 's')
				shw(addb);
			else
				return;
	}
	else{
		printf("\nContato encontrado!\n"); //pra isso ja vai ta sorted
		do{;
			if(strcmp(axl->name, nxl) == 0){
				printf("--------------\n");
				printf("\nName: %s\n",axl->name);
				printf("Email: %s\n",axl->email);
				printf("Phone: %s\n",axl->nmb);
				printf("--------------\n");
			}
		}while(strcmp(axl->name, nxl) != 0);
	}

}