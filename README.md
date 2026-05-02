# Learning C notes

Repository with notes and examples of research of C programming language,
including notes of the C book

Puedes ver la documentacion del proyecto en  [![Static Badge](https://img.shields.io/badge/docs-local-green)](docs/index.md)  [![Static Badge](https://img.shields.io/badge/docs-deepwiki-blue)](https://deepwiki.com/Atticus64/leacook)

## Features

- **Data Structures**: Dynamic array (auto-resize), circular linked list, LIFO stack, binary search tree
- **Lexer**: Tokenizer for arithmetic expressions with parenthesis validation via stack automaton
- **Utilities**: Hex string conversion, manual string operations (len, cat)
- **Examples**: K&R celsius table, iterative fibonacci
- **Testing**: Unit tests with CUnit, CI via GitHub Actions
- **Memory safe**: All structures include proper cleanup functions

## Build app

```
make
```

## Build and Run

```
$ ./run.sh
```

## Run Tests

```
make test
./learnc-test
```

## Try Examples

The examples are included as library functions. To use them, include the header and call the function from your code:

### Celsius Table (K&R)

```c
#include "lib/examples/celsius.h"

int main() {
    calc_celsius();
    return 0;
}
```

### Fibonacci

```c
#include "lib/examples/fibo.h"
#include <stdio.h>

int main() {
    int result = fibo(10);
    printf("Fibonacci(10) = %d\n", result);
    return 0;
}
```

### Data Structures

**Dynamic Array**

```c
#include "lib/ds/array.h"

int main() {
    Nums* arr = new_array(5);
    array_append(10, arr);
    array_append(20, arr);
    array_append(30, arr);
    show_array(arr);  // [ 10, 20, 30 ]
    del_array(arr);
    return 0;
}
```

**Stack (LIFO)**

```c
#include "lib/ds/stack.h"

int main() {
    stack_t* st = create_stack();
    push(st, 'A');
    push(st, 'B');
    push(st, 'C');
    show_stack(st);       // stack -> { C, B, A, Z }
    printf("top: %c\n", peek(st));  // C
    pop(st);
    del_stack(st);
    return 0;
}
```

**Binary Search Tree**

```c
#include "lib/ds/tree.h"

int main() {
    tree_t* tree = tree_new(50);
    tree_add_node(tree, 30);
    tree_add_node(tree, 70);
    tree_add_node(tree, 20);
    tree_add_node(tree, 40);

    tree_inorder(tree);   // 20 30 40 50 70 (sorted)
    tree_preorder(tree);  // 50 30 20 40 70
    tree_print(tree);     // visual tree output
    tree_delete(tree);
    return 0;
}
```

**Circular Linked List**

```c
#include "lib/ds/circular.h"

int main() {
    list_t* list = new_list();
    list_insert_node(list, 10);
    list_insert_node(list, 20);
    list_insert_node(list, 30);
    list_log(list);               // prints all elements + count
    printf("exists 20? %d\n", list_exist_elem(list, 20));  // 1
    printf("elem at 2: %d\n", list_get_elem(list, 2));     // 20
    del_list(list);
    return 0;
}
```

### Utilities

**Hex Conversion**

```c
#include "lib/utils/hex.h"
#include <stdio.h>

int main() {
    printf("%d\n", from_hex("0x40"));   // 64
    printf("%d\n", from_hex("0xFF"));   // 255
    printf("%c\n", upper('a'));         // A
    printf("%d\n", val_hxchar('f'));    // 15
    return 0;
}
```

**String Operations**

```c
#include "lib/utils/str.h"
#include <stdio.h>

int main() {
    char buffer[50] = "Hello";
    cat(buffer, " World");
    printf("%s\n", buffer);  // Hello World
    printf("len: %d\n", len(buffer));  // 11
    return 0;
}
```

### Lexer

**Parenthesis Validation**

```c
#include "lib/lang/lexer.h"
#include "lib/ds/stack.h"

int main() {
    stack_t* st = create_stack();
    check_program(st, "(a + (b - c))");
    // Output:
    // c => ( [L_PAREN]
    // c => a [SYMBOL]
    // c =>   [SYMBOL]
    // c => + [PLUS]
    // ...
    del_stack(st);
    return 0;
}
```

**Token Classification**

```c
#include "lib/lang/lexer.h"
#include <stdio.h>

int main() {
    t_type t1 = check_lexema('(');  // L_PAREN
    t_type t2 = check_lexema('+');  // PLUS
    t_type t3 = check_lexema('5');  // INT
    t_type t4 = check_lexema('x');  // SYMBOL
    return 0;
}
```

## How to Use This Repository

1. **Clone**: `git clone https://github.com/Atticus64/leacook.git`
2. **Build**: `make release` or `make debug` for GDB support
3. **Explore**: Browse `lib/` for implementations, `docs/` for detailed module documentation
4. **Test**: `make test && ./learnc-test` to verify everything works
5. **Learn**: Each module in `lib/` is self-contained and can be used as reference for C patterns
