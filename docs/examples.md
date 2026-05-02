# Examples Module (`lib/examples/`)

This module contains educational examples demonstrating fundamental C programming concepts.

---

## 1. Celsius Conversion (`celsius.h`)

Prints a Fahrenheit-to-Celsius conversion table. This is a classic example from "The C Programming Language" by Kernighan & Ritchie (K&R).

### Mermaid Diagram: Algorithm Flow

```mermaid
flowchart TD
    A["calc_celsius()"] --> B["lower = 0, upper = 300, step = 20"]
    B --> C["fahr = lower"]
    C --> D["Print header"]
    D --> E{"fahr <= upper?"}
    E -->|No| F["return 0"]
    E -->|Yes| G["celsius = 5 * (fahr - 32) / 9"]
    G --> H["Print fahr, celsius"]
    H --> I["fahr = fahr + step"]
    I --> E
```

### API Reference

| Function | Description | Return |
|----------|-------------|--------|
| `calc_celsius()` | Prints Fahrenheit-Celsius table from 0°F to 300°F in steps of 20°F | `int` - 0 on success |

### Output Example

```
	Fahrenheit	Celsious
	  0		  -17
	  20		  -6
	  40		  4
	  60		  15
	  80		  26
	  100		  37
	  ...
	  300		  148
```

### Conversion Formula

```mermaid
flowchart LR
    A["celsius"] --> B["="]
    B --> C["5"]
    C --> D["*"]
    D --> E["(fahr - 32)"]
    E --> F["/"]
    F --> G["9"]
```

### Usage

```c
#include "lib/examples/celsius.h"

calc_celsius();
```

---

## 2. Fibonacci (`fibo.h`)

Calculates the nth Fibonacci number using an iterative (non-recursive) approach.

### Mermaid Diagram: Algorithm Flow

```mermaid
flowchart TD
    A["fibo(num)"] --> B["a = 0, b = 1, fib = 0"]
    B --> C["i = 0"]
    C --> D{"i < num - 1?"}
    D -->|No| E["return fib"]
    D -->|Yes| F["fib = a + b"]
    F --> G["a = b"]
    G --> H["b = fib"]
    H --> I["i++"]
    I --> D
```

### API Reference

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `fibo(num)` | Calculates the nth Fibonacci number iteratively | `int num` - position in sequence (1-based) | `int` - nth Fibonacci number |

### State Evolution

```mermaid
flowchart LR
    subgraph "fibo(6) — Iteration Trace"
        A["i=0: fib=1, a=1, b=1"] --> B["i=1: fib=2, a=1, b=2"]
        B --> C["i=2: fib=3, a=2, b=3"]
        C --> D["i=3: fib=5, a=3, b=5"]
        D --> E["i=4: fib=8, a=5, b=8"]
        E --> F["return 8"]
    end
```

### Fibonacci Sequence

```mermaid
flowchart LR
    A["F(1)=0"] --> B["F(2)=1"]
    B --> C["F(3)=1"]
    C --> D["F(4)=2"]
    D --> E["F(5)=3"]
    E --> F["F(6)=5"]
    F --> G["F(7)=8"]
    G --> H["F(8)=13"]
    H --> I["F(9)=21"]
    I --> J["F(10)=34"]
```

### Complexity

| Metric | Value |
|--------|-------|
| Time Complexity | O(n) |
| Space Complexity | O(1) |

### Usage

```c
#include "lib/examples/fibo.h"

int result = fibo(10);  // Returns 34
```

---

## Module Overview

```mermaid
flowchart TD
    subgraph "lib/examples/ — Educational Examples"
        A["celsius.h\nFahrenheit → Celsius\nK&R Example"]
        B["fibo.h\nFonacci Sequence\nIterative O(n)"]
    end

    A -->|demonstrates| A1["while loops\narithmetic\nprintf formatting"]
    B -->|demonstrates| B1["for loops\nvariable swapping\niterative algorithms"]
```
