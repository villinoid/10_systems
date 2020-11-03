#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "material.h"

void main(){
	int i;
	char st[20]="Material ";
	char let[2]="A";
	struct material* test=new_material("Material A",0);
	for(i=1;i<10;i++){
		let[0]=65+i;
		strcat(st,let);
		test=insert_front(test,st,i);
		st[9]=0;
	}
	printf("Printing material list\n");
	print_list(test);
	printf("Removing material J\n");
	test=remove_node(test,"Material J", 9);
	print_list(test);	
	printf("Removing material C\n");
	test=remove_node(test,"Material C", 2);
	print_list(test);
	printf("Removing material A\n");
	test=remove_node(test,"Material A", 0);
	print_list(test);
	printf("Removing material asdjklsajdlkjaskjd\n");
	test=remove_node(test,"Material asdjklsajdlkjaskjd", 27129012);
	print_list(test);
	printf("freeing list\n");
	test=free_list(test);
	print_list(test);
}