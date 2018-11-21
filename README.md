<pre>
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
<code>

<pre>LLIST* create_list(int (*cmp_func)(void* x,void* y),void (*print_func)(void* x)) <code>   
-리스트를 생성하면서 리스트 내부에서 ->로 사용가능한 함수도 정의  
  
<pre>bool add_node_at(LLIST* list,unsigned int index,void* data){    <code>
-true나 false로 데이터 입력이 제대로 되었는지 확인한다.  
<pre>if ((list->count)==0)       <code>
-리스트에 노드가 하나도 없을 때는 front와 rear가 둘다 newnode가 된다.  
<pre>if (index==0)               <code>
-만약 처음 위치에 삽입한다면 front를 newnode로 바꾸고 이전 front를 뒤에 연결한다.  
<pre>else if (index==(list->count))    <code>
-맨 뒤에 삽입할때는 rear를 바꾸어준다.  
-이 외에는 iter_i라는 상수와 index를 비교해서 삽입할 위치를 찾는다  
  
<pre>bool del_node_at(LLIST* list,unsigned int index){   <code>
<pre>if (list->count==0)      <code>
-노드가 하나도 없을 때는 false 반환  
<pre>if (list->count==1)       <code>
-1개밖에 없을 때는 front와 rear를 다 NULL로 초기화한다  
<pre>if (index==0){          <code>  
-맨 앞의 노드를 제거하는 경우  
<pre>else if (iter_i==(list->count)-1){   <code>  
-맨 뒤의 노드를 제거하는 경우  
  
<pre>void* get_data_at(LLIST* list,unsigned int index)  <code>
-iter_i를 이용하여 내가 원하는 노드의 위치를 찾은 후에 노드의 데이터를 반환  
  
<pre>int find_data(LLIST* list,void* search_data){  <code>
-처음 리스트를 생성하는 함수에서 정의한 cmp_func함수를 이용해서 내가 찾는 데이터와 노드의 데이터를 비교한다.  
