typedef struct Elem elem_t;

typedef struct Elem {
	char value;
	elem_t* next;
} elem_t;


typedef struct Stack {
	int count;
	elem_t* top;
} stack_t;


stack_t* create_stack();

void push(stack_t* stack, char elem);
char peek(stack_t* stack);
char pop(stack_t* stack);

void show_stack(stack_t* stack);

void del_stack(stack_t* stack);
