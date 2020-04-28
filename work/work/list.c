#include "list.h"

Path_List initList()
{
	//�ȳ�ʼ��ͷ�ڵ�
	Path_List head = (Path_List)malloc(sizeof(node));
	if(head != NULL){
		//ͷ���ĳ�ʼ����������ָ�룬ָ�����Լ�
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
		//�����µĽڵ㣬��ʼ�������򣬻�������ָ��ָ���
		new_node->next = NULL;
		new_node->pre = NULL;
		return new_node;
	}
	return new_node;
}
void list_add_tail(Path_List new_node,Path_List head)
{
	//��ӽڵ㣬�ѽڵ���ӵ������ĩβ��β��
	new_node->pre = head->pre;
	new_node->next = head;
	head->pre->next = new_node;
	head->pre = new_node;
}
/*
void show_list(Path_List head)
{
	//head->next ָ���һ���ڵ㣬��Ϊͷ�ڵ�������û�����ݵġ�
	//p��һ��ָ�룬���ָ��ָ������ڵ�
	Path_List p = head->next;
	//��ʾ�ڵ���������ݣ�������������ָ��ͷ�ڵ�
	while( p != head ){
		printf("%d\t",p->data);
		if(p->data == 10)
		p=p->next;
	}
	printf("\n");
}*/