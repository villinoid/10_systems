#ifndef MATERIAL_H
#define MATERIAL_H

struct material {
	char name[50];
	int density;
	struct material *next;
};

void print_material(struct material*);
struct material *new_material(char *, int);
void update_density(struct material*, int);
void print_list(struct material *);
struct material * insert_front(struct material *,char *, int);
struct material * free_list(struct material *);
struct material * remove_node(struct material *, char*, int);
#endif
