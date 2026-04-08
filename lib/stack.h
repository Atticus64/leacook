typedef struct Elem elem_t;

typedef struct Elem {
	char value;
	elem_t* next;
} elem_t;


typedef struct Stack {
	int count;
	elem_t* bottom;
} stack_t;


stack_t* create_st();
void push(stack_t* stack, char elem);
void pop(stack_t* stack, char elem, int position);
