# Utilities Module (`lib/utils/`)

This module provides utility functions for hexadecimal conversion and string manipulation.

---

## 1. Hexadecimal Utilities (`hex.h`)

Functions for converting hexadecimal strings to integers and character case manipulation.

### Mermaid Diagram: Hex Conversion Flow

```mermaid
flowchart TD
    A["from_hex(hex[])"] --> B["val = 0"]
    B --> C["Read character hex[i]"]
    C --> D{"Is valid hex char?"}
    D -->|No| E["Return val"]
    D -->|Yes| F["val_hxchar(hex[i])"]
    F --> G["val = val * 16 + digit_value"]
    G --> C
```

```mermaid
flowchart TD
    A["val_hxchar(arg)"] --> B{"arg in '0'-'9'?"}
    B -->|Yes| C["return arg - '0'"]
    B -->|No| D["upper(arg)"]
    D --> E{"switch: A-F?"}
    E -->|A| F["return 10"]
    E -->|B| G["return 11"]
    E -->|C| H["return 12"]
    E -->|D| I["return 13"]
    E -->|E| J["return 14"]
    E -->|F| K["return 15"]
    E -->|default| L["return 0"]
```

### API Reference

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `val_hxchar(arg)` | Converts a hex character to its integer value (0-15) | `char arg` - hex digit | `int` - value 0-15 |
| `upper(c)` | Converts lowercase to uppercase | `int c` - character | `int` - uppercase char |
| `from_hex(hex[])` | Converts hex string to integer | `char hex[]` - hex string | `int` - decimal value |
| `is_letter(c)` | Checks if character is alphabetic | `char c` - character | `int` - 1 if letter, 0 otherwise |
| `hex_app()` | Interactive hex converter (reads from stdin) | none | `int` - 0 on success |

### Character Mapping

```mermaid
flowchart LR
    subgraph "Hex Digit → Value"
        A["'0'-'9'"] --> A1["0-9"]
        B["'a'/'A'"] --> B1["10"]
        C["'b'/'B'"] --> C1["11"]
        D["'c'/'C'"] --> D1["12"]
        E["'d'/'D'"] --> E1["13"]
        F["'e'/'E'"] --> F1["14"]
        G["'f'/'F'"] --> G1["15"]
    end
```

### Usage Example

```c
// Convert hex string to integer
int val = from_hex("0x40");  // Returns 64
int val2 = from_hex("0xa2"); // Returns 162

// Character conversion
char upper = upper('a');     // Returns 'A'
int digit = val_hxchar('f'); // Returns 15

// Interactive mode
hex_app();  // Prompts user for hex input
```

### `upper()` Function Detail

```mermaid
flowchart TD
    A["upper(c)"] --> B{"c >= 'a' && c <= 'z'?"}
    B -->|Yes| C["return c - 32"]
    B -->|No| D["return c (unchanged)"]
```

---

## 2. String Utilities (`str.h`)

Manual implementations of common string operations.

### Mermaid Diagram: String Operations

```mermaid
flowchart TD
    subgraph "len(str)"
        A1["i = 0"] --> A2["str[i] != '\\0'?"}
        A2 -->|Yes| A3["i++"]
        A3 --> A2
        A2 -->|No| A4["return i"]
    end

    subgraph "cat(str1, str2)"
        B1["val_len = len(str1)"] --> B2["str1 += val_len"]
        B2 --> B3["*str2 != '\\0'?"}
        B3 -->|Yes| B4["*str1 = *str2"]
        B4 --> B5["str1++, str2++"]
        B5 --> B3
        B3 -->|No| B6["Done"]
    end
```

### API Reference

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `len(str)` | Calculates string length (like `strlen`) | `char* str` - null-terminated string | `int` - character count |
| `cat(str1, str2)` | Concatenates str2 to str1 (like `strcat`) | `char* str1` - destination (must have space)<br>`char* str2` - source | `void` |

### Memory Layout: `cat()` Operation

```mermaid
flowchart LR
    subgraph "Before cat(str1, str2)"
        A["str1: 'H' 'e' 'l' 'l' 'o' '\\0' ? ? ?"]
        B["str2: ' ' 'W' 'o' 'r' 'l' 'd' '\\0'"]
    end

    subgraph "After cat(str1, str2)"
        C["str1: 'H' 'e' 'l' 'l' 'o' ' ' 'W' 'o' 'r' 'l' 'd' '\\0'"]
    end

    A --> C
    B -.-> C
```

### Usage Example

```c
char buffer[50] = "Hello";
cat(buffer, " World");
// buffer now contains "Hello World"

int length = len(buffer);  // Returns 11
```

### Module Dependencies

```mermaid
flowchart TD
    A["utils/hex.h"] --> B["stdio.h"]
    C["utils/str.h"] --> D["No external dependencies"]

    A -.->|used by| E["lang/lexer.h"]
    A -.->|used by| F["test/utils/test_hex.c"]
    C -.->|used by| G["Potential future modules"]
```
