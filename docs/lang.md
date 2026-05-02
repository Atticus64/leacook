# Language/Lexer Module (`lib/lang/`)

This module implements a basic lexical analyzer (lexer) for simple arithmetic expressions, with a stack-based automaton for parenthesis validation.

---

## Token Types

The lexer recognizes the following token types:

```c
typedef enum {
    L_PAREN,    // '('
    R_PAREN,    // ')'
    SYMBOL,     // Alphabetic or other symbols
    PLUS,       // '+'
    MINUS,      // '-'
    INT,        // '0'-'9'
    FLOAT       // Floating point (reserved)
} t_type;
```

### Mermaid Diagram: Token Classification

```mermaid
flowchart TD
    A["check_lexema(char)"] --> B{"char == '('?"}
    B -->|Yes| C["return L_PAREN"]
    B -->|No| D{"char == ')'?"}
    D -->|Yes| E["return R_PAREN"]
    D -->|No| F{"char in '0'-'9'?"}
    F -->|Yes| G["return INT"]
    F -->|No| H{"char == '+'?"}
    H -->|Yes| I["return PLUS"]
    H -->|No| J{"char == '-'?"}
    J -->|Yes| K["return MINUS"]
    J -->|No| L["return SYMBOL"]
```

### Token Type Mapping

```mermaid
flowchart LR
    subgraph "Character → Token Type"
        A["'('"] --> A1["L_PAREN"]
        B["')'"] --> B1["R_PAREN"]
        C["'0'-'9'"] --> C1["INT"]
        D["'+'"] --> D1["PLUS"]
        E["'-'"] --> E1["MINUS"]
        F["a-z, A-Z, etc."] --> F1["SYMBOL"]
    end
```

---

## Structures

```c
typedef struct Token {
    t_type type;
    char* value[60];
} t_token;
```

### Mermaid Diagram: Token Structure

```mermaid
classDiagram
    class t_type {
        <<enumeration>>
        L_PAREN
        R_PAREN
        SYMBOL
        PLUS
        MINUS
        INT
        FLOAT
    }
    class t_token {
        +t_type type
        +char* value[60]
    }
    t_token --> t_type : has
```

---

## Parenthesis Validation Automaton

The `check_program()` function uses a stack-based automaton to validate that parentheses in an input string are properly matched.

### Mermaid Diagram: Automaton Flow

```mermaid
flowchart TD
    A["check_program(input, stack)"] --> B["i = 0, ch = input[0]"]
    B --> C{"ch != '\\0'?"}
    C -->|No| D["automaton_pop(st, 'Z', i)"]
    C -->|Yes| E["t_lex = check_lexema(ch)"]
    E --> F{"t_lex == L_PAREN?"}
    F -->|Yes| G["automaton_push(st, '1')"]
    F -->|No| H{"t_lex == R_PAREN?"}
    H -->|Yes| I["automaton_pop(st, '1', i)"]
    H -->|No| J["Continue"]
    G --> K["Print: c => ch [type]"]
    I --> K
    J --> K
    K --> L["i++, ch = input[i]"]
    L --> C
    D --> M["Done"]
```

### Stack State During Parenthesis Matching

```mermaid
sequenceDiagram
    participant Input
    participant Lexer
    participant Stack

    Input->>Lexer: "(a + (b - c))"

    Lexer->>Lexer: ch = '('
    Lexer->>Stack: automaton_push('1')
    Note over Stack: ['1', 'Z']

    Lexer->>Lexer: ch = 'a'
    Note over Lexer: SYMBOL (ignored)

    Lexer->>Lexer: ch = '+'
    Note over Lexer: PLUS (ignored)

    Lexer->>Lexer: ch = '('
    Lexer->>Stack: automaton_push('1')
    Note over Stack: ['1', '1', 'Z']

    Lexer->>Lexer: ch = 'b'
    Note over Lexer: SYMBOL (ignored)

    Lexer->>Lexer: ch = ')'
    Lexer->>Stack: automaton_pop('1')
    Note over Stack: ['1', 'Z']

    Lexer->>Lexer: ch = ')'
    Lexer->>Stack: automaton_pop('1')
    Note over Stack: ['Z']

    Lexer->>Stack: automaton_pop('Z')
    Note over Stack: [] (empty - valid!)
```

---

## API Reference

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `check_lexema(lexema)` | Classifies a single character into its token type | `char lexema` - character to classify | `t_type` - token type enum |
| `check_program(input, st)` | Validates parenthesis matching using stack automaton | `char* input` - string to analyze<br>`stack_t* st` - stack for tracking | `void` |

### `lexema_str()` Helper (internal)

Converts a `t_type` enum to its string representation for logging:

| Token Type | String Output |
|------------|---------------|
| `L_PAREN` | `"L_PAREN"` |
| `R_PAREN` | `"R_PAREN"` |
| `SYMBOL` | `"SYMBOL"` |
| `PLUS` | `"PLUS"` |
| `MINUS` | `"MINUS"` |
| `INT` | `"INT"` |
| `FLOAT` | `"FLOAT"` |
| other | `"NIL"` |

---

## Usage Example

```c
#include "lib/lang/lexer.h"
#include "lib/ds/stack.h"

stack_t* st = create_stack();
char* input = "(a + (b - c))";

check_program(input, st);
// Output:
// c => ( [L_PAREN]
// c => a [SYMBOL]
// c =>   [SYMBOL]
// c => + [PLUS]
// c =>   [SYMBOL]
// c => ( [L_PAREN]
// c => b [SYMBOL]
// c =>   [SYMBOL]
// c => - [MINUS]
// c =>   [SYMBOL]
// c => c [SYMBOL]
// c => ) [R_PAREN]
// c => ) [R_PAREN]

del_stack(st);
```

### Error Case: Unmatched Parenthesis

```mermaid
flowchart TD
    A["Input: '(a + b'"] --> B["Process '('"]
    B --> C["push('1')"]
    C --> D["Process 'a', ' ', '+', ' ', 'b'"]
    D --> E["End of string"]
    E --> F["automaton_pop('Z')"]
    F --> G["ERROR: Expected parenthesis at position X"]
```

---

## Module Dependencies

```mermaid
flowchart TD
    A["lang/lexer.h"] --> B["ds/stack.h"]
    B --> C["ds/stack.c"]

    A -.->|uses| D["check_lexema()"]
    A -.->|uses| E["automaton_push()"]
    A -.->|uses| F["automaton_pop()"]

    style A fill:#f96,stroke:#333,stroke-width:2px
    style B fill:#9cf,stroke:#333
```
