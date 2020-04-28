#include "list.h"

Path_List initList()
{
	//先初始化头节点
	Path_List head = (Path_List)malloc(sizeof(node));
	if(head != NULL){
		//头结点的初始化，它两个指针，指向它自己
		head->next=head;
		head->pre=head;
	}
	return head;
}

Path_List newNode()
{
	Path_List new_node = (Path_List)malloc(sizeof(node));
	if(new_node != NULL)
	{
		//创建新的节点，初始化数据域，还有两个指针指向空
		new_node->next = NULL;
		new_node->pre = NULL;
		return new_node;
	}
	return new_node;
}
void list_add_tail(Path_List new_node,Path_List head)
{
	//添加节点，把节点添加到链表的末尾，尾插
	new_node->pre = head->pre;
	new_node->next = head;
	head->pre->next = new_node;
	head->pre = new_node;
}
/*
void show_list(Path_List head)
{
	//head->next 指向第一个节点，因为头节点里面是没有数据的。
	//p是一个指针，这个指针指向各个节点
	Path_List p = head->next;
	//显示节点里面的数据，结束的条件是指向头节点
	while( p != head ){
		printf("%d\t",p->data);
		if(p->data == 10)
		p=p->next;
	}
	printf("\n");
}*/