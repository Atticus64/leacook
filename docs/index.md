# leacook — Learning C Notes

Repository with notes and examples of research of the C programming language, including notes from "The C Programming Language" book.

---

## Project Structure

```mermaid
flowchart TD
    subgraph "leacook"
        A["src/\nmain.c"] --> B["lib/"]
        B --> C["ds/Data Structures"]
        B --> D["utils/Utilities"]
        B --> E["lang/Lexer"]
        B --> F["examples/Examples"]

        G["test/Unit Tests"] --> H["ds/test_array, test_tree"]
        G --> I["utils/test_hex"]
        G --> J["test_main.c"]

        K["docs/Documentation"] --> L["ds.md"]
        K --> M["utils.md"]
        K --> N["lang.md"]
        K --> O["examples.md"]
    end

    style A fill:#f96,stroke:#333,stroke-width:2px
    style B fill:#9cf,stroke:#333
    style G fill:#cfc,stroke:#333
    style K fill:#fcf,stroke:#333
```

---

## Modules

| Module | Path | Description | Documentation |
|--------|------|-------------|---------------|
| **Data Structures** | `lib/ds/` | Array, Circular List, Stack, BST | [ds.md](ds.md) |
| **Utilities** | `lib/utils/` | Hex conversion, String operations | [utils.md](utils.md) |
| **Lexer** | `lib/lang/` | Tokenizer, Parenthesis validator | [lang.md](lang.md) |
| **Examples** | `lib/examples/` | Celsius table, Fibonacci | [examples.md](examples.md) |

---

## Module Dependency Graph

```mermaid
flowchart TD
    A["src/main.c"] --> B["lib/ds/array.h"]
    A --> C["lib/ds/stack.h"]

    D["lib/lang/lexer.h"] --> C

    E["lib/utils/hex.h"] --> F["stdio.h"]
    G["lib/utils/str.h"] --> H["No deps"]

    I["lib/examples/celsius.h"] --> F
    J["lib/examples/fibo.h"] --> H

    K["test/test_main.c"] --> E
    K --> B
    K --> L["lib/ds/tree.h"]

    style A fill:#f96,stroke:#333,stroke-width:2px
    style K fill:#cfc,stroke:#333
```

---

## Build System

### Makefile Targets

| Target | Description | Flags |
|--------|-------------|-------|
| `make` | Default build (no specific target) | - |
| `make debug` | Debug build with GDB support | `-Wall -Wextra -Werror -Og -ggdb` |
| `make release` | Optimized release build | `-Wall -Wextra -Werror -O2 -march=native` |
| `make test` | Build test suite (requires CUnit) | `-lcunit` |
| `make clean` | Remove all object files | - |
| `make usage` | Show help message | - |

### Build Flow

```mermaid
flowchart TD
    A["make release"] --> B["Compile lib/ds/*.c → obj/"]
    A --> C["Compile lib/utils/*.c → obj/"]
    A --> D["Compile lib/lang/*.c → obj/"]
    A --> E["Compile lib/examples/*.c → obj/"]
    A --> F["Compile src/*.c → obj/"]
    B --> G["Link all objects → learnc"]
    C --> G
    D --> G
    E --> G
    F --> G

    H["make test"] --> I["Compile lib/*.c → obj/"]
    H --> J["Compile test/ds/*.c → obj/"]
    H --> K["Compile test/utils/*.c → obj/"]
    H --> L["Compile test/test_main.c → obj/"]
    I --> M["Link with -lcunit → learnc-test"]
    J --> M
    K --> M
    L --> M
```

### Quick Start

```bash
# Build and run
./run.sh

# Or manually
make release
./learnc

# Run tests
make test
./learnc-test
```

---

## Testing

The project uses **CUnit** for unit testing.

### Test Suites

```mermaid
flowchart TD
    A["CUnit Test Registry"] --> B["Core Suite"]
    A --> C["Array Suite"]
    A --> D["Tree Suite"]

    B --> B1["test_val_hxchar"]
    B --> B2["test_from_hex"]
    B --> B3["test_upper"]

    C --> C1["test_new_array_valid"]
    C --> C2["test_new_array_invalid"]
    C --> C3["test_array_append_single"]
    C --> C4["test_array_append_multiple"]
    C --> C5["test_array_append_resize"]
    C --> C6["test_array_count_tracking"]
    C --> C7["test_array_no_leak"]

    D --> D1["test_tree_new"]
    D --> D2["test_tree_add_single"]
    D --> D3["test_tree_add_multiple"]
    D --> D4["test_tree_add_duplicate"]
    D --> D5["test_tree_items_count"]
    D --> D6["test_tree_inorder_sorted"]
    D --> D7["test_tree_preorder"]
    D --> D8["test_tree_delete"]
    D --> D9["test_tree_no_leak"]
```

### Test Coverage

| Module | Tests | Coverage |
|--------|-------|----------|
| **utils/hex** | 3 | `val_hxchar`, `from_hex`, `upper` |
| **ds/array** | 7 | Creation, append, resize, count, memory leak |
| **ds/tree** | 9 | Creation, insertion, counting, traversal, deletion, memory leak |

---

## Doxygen Documentation

All header files include Doxygen-style comments. To generate HTML documentation:

```bash
# Install doxygen
# Ubuntu/Debian: sudo apt install doxygen
# macOS: brew install doxygen

# Generate docs (if Doxyfile exists)
doxygen Doxyfile
```

### Doxygen Comment Format

```c
/**
 * @brief Brief description of the function.
 *
 * Detailed description of what the function does,
 * its behavior, and any important notes.
 *
 * @param param_name Description of the parameter.
 * @return Description of the return value.
 */
```

---

## CI/CD

The project uses GitHub Actions for continuous integration.

```mermaid
flowchart LR
    A["Push to GitHub"] --> B["GitHub Actions"]
    B --> C["Run make test"]
    C --> D{"Tests pass?"}
    D -->|Yes| E["Success"]
    D -->|No| F["Failure notification"]
```

See `.github/workflows/tests.yml` for configuration.

---

## License

This project is for educational purposes — learning C programming.
