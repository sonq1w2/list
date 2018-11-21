#include "ADT_llist.h"
LLIST* create_list(int (*cmp_func)(void* x,void* y),void (*print_func)(void* x)){
	LLIST* list=(LLIST*)malloc(sizeof(LLIST));
	list->count=0;
	list->front=NULL;
	list->rear=NULL;
	list->pos=NULL;
	list->cmp_func=cmp_func;
	list->print_func=print_func;
}
bool add_node_at(LLIST* list,unsigned int index,void* data){
	NODE* new_node=(NODE*)malloc(sizeof(NODE));
	new_node->data_ptr=data;
	new_node->next=NULL;
	if(index>(list->count)) return false;
	if ((list->count)==0){
		list->front=new_node;
		list->rear=new_node;
		(list->count)++;
		return true;
	}
	if (index==0){
		new_node->next=list->front;
		list->front=new_node;
		(list->count)++;
		return true;
	}
	else if (index==(list->count)){
		list->rear->next=new_node;
		list->rear=new_node;
		(list->count)++;
	}
	else {int iter_i=1;
	list->pos=list->front;
		while (index!=iter_i){
			list->pos=list->pos->next;
			iter_i++;
		}
		new_node->next=list->pos->next;
		list->pos->next=new_node;
		(list->count)++;
		return true;
	}
	return false;
}
bool del_node_at(LLIST* list,unsigned int index){
	if (index>=list->count) return false;
	if (list->count==0) return false;
	if (list->count==1){
		free(list->front);
		list->front=NULL;
		list->rear=NULL;
		list->count=0;
		return true;
	}
	NODE* pre=NULL;
	int iter_i=0;
	list->pos=list->front;
	while (iter_i!=index){
		pre=list->pos;
		list->pos=list->pos->next;
		iter_i++;
	}
	if (index==0){
		list->front=list->pos->next;
		free(list->pos);
		list->pos=NULL;
		(list->count)--;
		return true;
	}
	
	else if (iter_i==(list->count)-1){
		list->rear=pre;
		pre->next=NULL;
		free(list->pos);
		list->pos=NULL;
		(list->count)--;
		return true;
	}
	else {
		pre->next=list->pos->next;
		free(list->pos);
		list->pos=NULL;
		(list->count)--;
		return true;

	}
	return false;

}
void* get_data_at(LLIST* list,unsigned int index){
	if (index>=list->count) return NULL;
	int iter_i=0;
	list->pos=list->front;
	while (list->pos!=NULL){
		if (iter_i==index)
			return list->pos->data_ptr;
		list->pos=list->pos->next;
		iter_i++;
		
	}
	return NULL;
}
int find_data(LLIST* list,void* search_data){
	list->pos=list->front;
	int iter_i=0;
	while (list->pos!=NULL){
		if ((*(list->cmp_func))(search_data,list->pos->data_ptr))
			return iter_i;
		list->pos=list->pos->next;
		iter_i++;
	}
	return -1;
}
