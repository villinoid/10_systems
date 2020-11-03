#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "material.h"

void print_material(struct material *m){
	if (m){
		printf("material: %s\tdensity: %d\n", m->name, m->density);
	}
}

struct material *new_material(char *n, int d) {

  struct material *nm;

  nm = malloc( sizeof(struct material) );

  strncpy(nm->name, n, sizeof(nm->name)-1);
  nm->density = d;
  nm->next= 0;

  return nm;
}

void update_density(struct material *m, int nd){
	m->density=nd;
}

void print_list(struct material *node){
	if (node){
		while(node->next){
			print_material(node);
			node=node->next;
		}
		print_material(node);
	}
}
	;
	
struct material * insert_front(struct material *node,char *n, int d){
	struct material*f=new_material(n,d);
	f->next=node;
	return f;
}
struct material * free_list(struct material *node){
	while(node->next){
		free(node);
		node=node->next;
	}
	free(node);
	return 0;
}
	
struct material * remove_node(struct material *f, char *n, int d){
	struct material *node=f;
	if (d==node->density && !(strcmp(n,node->name))){
		return f->next;
	}
	while(node->next){
		if(d==node->next->density && !(strcmp(n,node->next->name))){
			node->next=node->next->next;
			return f;
		}
		node=node->next;
	}
	return f;
}
