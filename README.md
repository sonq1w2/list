
typedef struct node{
	void* data_ptr;
	struct node* next;
}NODE;
typedef struct{
	NODE* front;
	NODE* rear;
	NODE* pos;
	int count;
	int (*cmp_func)(void* x,void* y);
	void (*print_func)(void* x);
}LLIST;


LLIST* create_list(int (*cmp_func)(void* x,void* y),void (*print_func)(void* x))  
-리스트를 생성하면서 리스트 내부에서 ->로 사용가능한 함수도 정의  
  
bool add_node_at(LLIST* list,unsigned int index,void* data){    
-true나 false로 데이터 입력이 제대로 되었는지 확인한다.  
if ((list->count)==0)       
-리스트에 노드가 하나도 없을 때는 front와 rear가 둘다 newnode가 된다.  
if (index==0)               
-만약 처음 위치에 삽입한다면 front를 newnode로 바꾸고 이전 front를 뒤에 연결한다.  
else if (index==(list->count))    
-맨 뒤에 삽입할때는 rear를 바꾸어준다.  
-이 외에는 iter_i라는 상수와 index를 비교해서 삽입할 위치를 찾는다  
  
bool del_node_at(LLIST* list,unsigned int index){   
if (list->count==0)      
-노드가 하나도 없을 때는 false 반환  
if (list->count==1)       
-1개밖에 없을 때는 front와 rear를 다 NULL로 초기화한다  
if (index==0){            
-맨 앞의 노드를 제거하는 경우  
else if (iter_i==(list->count)-1){     
-맨 뒤의 노드를 제거하는 경우  
  
void* get_data_at(LLIST* list,unsigned int index)  
-iter_i를 이용하여 내가 원하는 노드의 위치를 찾은 후에 노드의 데이터를 반환  
  
int find_data(LLIST* list,void* search_data){  
-처음 리스트를 생성하는 함수에서 정의한 cmp_func함수를 이용해서 내가 찾는 데이터와 노드의 데이터를 비교한다.  
