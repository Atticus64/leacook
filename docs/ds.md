# Data Structures Module (`lib/ds/`)

This module implements fundamental data structures in C, each with dynamic memory management and proper cleanup functions.

---

## 1. Dynamic Array (`array.h`)

A resizable array of integers that automatically doubles its capacity when full.

### Structure

```c
typedef struct {
    int *items;      // Dynamic array of integers
    size_t count;    // Current number of elements
    size_t capacity; // Allocated capacity
} Nums;
```

### Mermaid Diagram: Array Structure & Resize Flow

```mermaid
classDiagram
    class Nums {
        +int* items
        +size_t count
        +size_t capacity
        +new_array(capacity)
        +array_append(num)
        +show_array()
        +del_array()
    }
```

```mermaid
flowchart TD
    A["array_append(num, list)"] --> B{"count >= capacity?"}
    B -->|No| C["items[count] = num"]
    B -->|Yes| D["new_capacity = capacity * 2"]
    D --> E["realloc(items, new_capacity)"]
    E --> F{"realloc success?"}
    F -->|No| G["Print error, return"]
    F -->|Yes| H["items = temp, capacity = new_capacity"]
    H --> C
    C --> I["count++"]
```

### API Reference

| Function | Description |
|----------|-------------|
| `new_array(capacity)` | Creates a new array with initial capacity. Returns `NULL` if capacity < 1. |
| `array_append(num, list)` | Appends an integer. Auto-resizes if full (doubles capacity). |
| `show_array(list)` | Prints all elements in format `[ 1, 2, 3 ]`. |
| `del_array(list)` | Frees the items array and the Nums struct. |

### Usage Example

```c
Nums* list = new_array(5);
array_append(10, list);
array_append(20, list);
array_append(30, list);
show_array(list);  // [ 10, 20, 30 ]
del_array(list);
```

### Memory Behavior

```mermaid
sequenceDiagram
    participant User
    participant Array
    participant Heap

    User->>Array: new_array(5)
    Array->>Heap: malloc(sizeof(Nums))
    Array->>Heap: malloc(5 * sizeof(int))
    Array-->>User: Nums*

    User->>Array: array_append(10)
    Array->>Array: items[0] = 10, count=1

    User->>Array: array_append(20)
    Array->>Array: items[1] = 20, count=2

    User->>Array: del_array(list)
    Array->>Heap: free(items)
    Array->>Heap: free(list)
```

---

## 2. Circular Linked List (`circular.h`)

A singly-linked list where the last node points back to the first, forming a cycle.

### Structures

```c
typedef struct Node {
    int value;
    node_t *next;
} node_t;

typedef struct List {
    int count;
    node_t *head;
} list_t;
```

### Mermaid Diagram: Circular List Structure

```mermaid
flowchart LR
    subgraph Circular List
        A["Node 1\nvalue: 10"] --> B["Node 2\nvalue: 20"]
        B --> C["Node 3\nvalue: 30"]
        C --> A
    end

    L["list_t\ncount: 3\nhead: → Node 1"] -.-> A
```

```mermaid
classDiagram
    class node_t {
        +int value
        +node_t* next
    }
    class list_t {
        +int count
        +node_t* head
        +new_list()
        +list_insert_node(value)
        +list_delete_node(value)
        +list_get_elem(index)
        +list_exist_elem(elem)
        +list_search(value)
        +list_log()
        +del_list()
    }
    list_t *-- node_t : contains
```

### API Reference

| Function | Description |
|----------|-------------|
| `new_node(val)` | Creates a new node with the given value. |
| `new_list()` | Creates an empty circular list. |
| `list_insert_node(list, value)` | Inserts a new node at the end of the circular list. |
| `list_delete_node(list, value)` | Deletes the first node with the matching value. |
| `list_get_elem(list, index)` | Returns element at 1-based index, or -1 if out of bounds. |
| `list_exist_elem(list, elem)` | Returns 1 if element exists, 0 otherwise. |
| `list_search(list, value)` | Searches and prints position of value. |
| `list_log(list)` | Prints all elements and count. |
| `list_get_items(list)` | Returns a new array with all elements (caller must free). |
| `del_list(list)` | Frees all nodes and the list container. |

### Insert Operation Flow

```mermaid
flowchart TD
    A["list_insert_node(list, value)"] --> B{"head == NULL?"}
    B -->|Yes| C["head = new_node(value)"]
    B -->|No| D["add_end(head, new_node)"]
    C --> E["count++"]
    D --> E
```

---

## 3. Stack (`stack.h`)

A LIFO (Last In, First Out) stack implemented with a linked list, designed for character storage. Includes standard and automaton variants of push/pop.

### Structures

```c
typedef struct Elem {
    char value;
    elem_t* next;
} elem_t;

typedef struct Stack {
    int count;
    elem_t* top;
} stack_t;
```

### Mermaid Diagram: Stack Operations

```mermaid
flowchart TD
    subgraph "Stack (top → bottom)"
        T["top: 'C'"] --> M["'B'"]
        M --> B["'A'"]
        B --> S["sentinel: 'Z'"]
        S --> NULL["NULL"]
    end

    Push["push('D')"] --> T
    Pop["pop() → returns 'C'"] -.-> T
```

```mermaid
classDiagram
    class elem_t {
        +char value
        +elem_t* next
    }
    class stack_t {
        +int count
        +elem_t* top
        +create_stack()
        +push(elem)
        +pop() → char
        +peek() → char
        +empty_stack() → int
        +show_stack()
        +del_stack()
    }
    stack_t *-- elem_t : contains
```

### Standard vs Automaton Operations

```mermaid
flowchart LR
    subgraph "Standard push/pop"
        A1["push()"] --> A2["Inserts at TOP"]
        A3["pop()"] --> A4["Removes from TOP"]
    end

    subgraph "Automaton push/pop"
        B1["automaton_push()"] --> B2["Appends at END"]
        B3["automaton_pop()"] --> B4["Removes from END + validates"]
    end
```

### API Reference

| Function | Description |
|----------|-------------|
| `create_stack()` | Creates a new stack with a sentinel element ('Z'). |
| `push(stack, elem)` | Pushes a character onto the top. |
| `pop(stack)` | Removes and returns the top character. |
| `peek(stack)` | Returns the top character without removing it. |
| `empty_stack(stack)` | Returns 1 if stack is empty, 0 otherwise. |
| `automaton_push(stack, elem)` | Appends to the end (for parenthesis automaton). |
| `automaton_pop(stack, elem, position)` | Pops from end, validates expected char, reports errors. |
| `show_stack(stack)` | Prints all stack elements. |
| `del_stack(stack)` | Frees all elements and the stack container. |

### Usage Example

```c
stack_t* st = create_stack();
push(st, 'A');
push(st, 'B');
push(st, 'C');
show_stack(st);    // stack -> { C, B, A, Z }
char top = peek(st);  // 'C'
pop(st);           // removes 'C'
del_stack(st);
```

---

## 4. Binary Search Tree (`tree.h`)

A binary search tree (BST) where left children contain lesser values and right children contain greater or equal values.

### Structures

```c
typedef struct TreeNode {
    int value;
    tree_node_t* right;
    tree_node_t* left;
} tree_node_t;

typedef struct Tree {
    tree_node_t* root;
    int items;
} tree_t;
```

### Mermaid Diagram: BST Structure

```mermaid
flowchart TD
    A["50"] --> B["30"]
    A --> C["70"]
    B --> D["20"]
    B --> E["40"]
    C --> F["60"]
    C --> G["80"]

    style A fill:#f96,stroke:#333,stroke-width:2px
    style B fill:#9cf,stroke:#333
    style C fill:#9cf,stroke:#333
    style D fill:#cfc,stroke:#333
    style E fill:#cfc,stroke:#333
    style F fill:#cfc,stroke:#333
    style G fill:#cfc,stroke:#333
```

```mermaid
classDiagram
    class tree_node_t {
        +int value
        +tree_node_t* right
        +tree_node_t* left
    }
    class tree_t {
        +tree_node_t* root
        +int items
        +tree_new(init_value)
        +tree_add_node(new_value)
        +tree_preorder()
        +tree_inorder()
        +tree_print()
        +tree_delete()
    }
    tree_t *-- tree_node_t : contains
```

### Traversal Orders

```mermaid
flowchart TD
    subgraph "Inorder (left → root → right)"
        A1["20 30 40 50 60 70 80"]
    end

    subgraph "Preorder (root → left → right)"
        A2["50 30 20 40 70 60 80"]
    end
```

### Insert Algorithm

```mermaid
flowchart TD
    A["tree_add_node(tree, new_value)"] --> B["Start at root"]
    B --> C{"new_value < current.value?"}
    C -->|Yes| D{"left == NULL?"}
    C -->|No| E{"right == NULL?"}
    D -->|Yes| F["left = new_node"]
    D -->|No| G["current = left, repeat"]
    E -->|Yes| H["right = new_node"]
    E -->|No| I["current = right, repeat"]
    F --> J["items++"]
    H --> J
    G --> C
    I --> C
```

### API Reference

| Function | Description |
|----------|-------------|
| `tree_new(init_value)` | Creates a new tree with root containing init_value. |
| `tree_add_node(tree, new_value)` | Inserts a new node following BST rules. |
| `tree_preorder(tree)` | Prints tree in preorder traversal. |
| `tree_inorder(tree)` | Prints tree in inorder (sorted for BST). |
| `tree_print(tree)` | Prints visual tree with branch characters (├──, └──). |
| `tree_delete(tree)` | Recursively frees all nodes and the tree container. |

### Usage Example

```c
tree_t* tree = tree_new(50);
tree_add_node(tree, 30);
tree_add_node(tree, 70);
tree_add_node(tree, 20);
tree_add_node(tree, 40);

tree_inorder(tree);   // 20 30 40 50 70
tree_preorder(tree);  // 50 30 20 40 70
tree_print(tree);     // Visual tree output
tree_delete(tree);
```

---

## Module Overview Diagram

```mermaid
flowchart TD
    subgraph "lib/ds/ — Data Structures"
        A["array.h\nDynamic Array\nNums"]
        B["circular.h\nCircular List\nlist_t, node_t"]
        C["stack.h\nLIFO Stack\nstack_t, elem_t"]
        D["tree.h\nBinary Search Tree\ntree_t, tree_node_t"]
    end

    A -->|auto-resize| A1["realloc()"]
    B -->|circular links| B1["node.next → head"]
    C -->|linked list| C1["elem_t chain"]
    D -->|BST property| D1["left < root <= right"]

    C -.->|used by| E["lang/lexer.h"]
```
