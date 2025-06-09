
typedef struct Node node_t;

typedef struct Node {
  int value;
  node_t *next;
} node_t;

typedef struct List list_t;

typedef struct List {
	int count;
	node_t *head;
} list_t;

node_t* new_node(int val);

list_t* new_list(void);

void list_insert_node(list_t* list, int value);

void list_delete_node(list_t* list, int value);

void list_log(list_t *list);

void add_node(node_t *n1, node_t *n2);

void add_end(node_t* init, node_t* new_node);

void delete_node(node_t *root, int value);

void list_search(list_t *list, int value);

void print_list(node_t *last);

void del_list(list_t *list);

void delete_list(node_t* elem);

void log_node(node_t *node, const char *tag);
