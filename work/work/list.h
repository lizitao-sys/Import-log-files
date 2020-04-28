#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#pragma warning(disable:4996)



typedef struct path{
	char file_path[50];
	struct path *next,*pre;
}node,*Path_List;

Path_List initList();
Path_List newNode();
void list_add_tail(Path_List new_node,Path_List head);
void show_list(Path_List head);




#endif