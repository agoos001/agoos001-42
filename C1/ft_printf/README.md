*This project has been created as part of the 42 curriculum by mbihti*

# Description

`ft_printf` is a re-implementation of the C standard library `printf` function.

The goal of this project is to understand and reproduce the behaviour of `printf`, one of the most used and most complex functions of the standard library. It introduces the concept of **variadic functions** — functions that accept a variable number of arguments — and forces us to parse a format string to determine how each argument should be printed.

Unlike a simple string output function, `ft_printf` must interpret a format string containing **conversion specifiers** (starting with `%`) and print the corresponding argument in the correct format. Each call returns the total number of characters printed, just like the original `printf`.

The mandatory part handles the specifiers `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

The function reads the format string character by character. When a `%` is encountered, it identifies the conversion specifier that follows and calls the appropriate printing function, retrieving the argument from the variadic argument list with `va_arg`.

The project also introduces several important concepts in C:
- Variadic functions and the `stdarg.h` macros (`va_list`, `va_start`, `va_arg`, `va_end`).
- Parsing a format string.
- Number conversion between bases (decimal, hexadecimal) for signed and unsigned integers.
- Printing memory addresses.
- Writing output using the `write()` system call.
- Handling special cases (`NULL` strings, `INT_MIN`, `(null)` pointer, `%` literal).

The bonus part extends the function with **formatting flags and options**: field width, precision, and the flags `-`, `0`, `#`, `+`, and ` ` (space), all combinable with the mandatory conversions.

# Instructions

## Compilation

To compile the project, use:

```bash
cc -Wall -Wextra -Werror \
ft_printf.c parser.c printers.c ft_printf_utils.c main.c -o ft_printf
```

Or, if you use a Makefile:

```bash
make            # (mandatory)
make bonus      # (mandatory + bonus)
make clean
make fclean
make re
```

## Execution


To test the function, include the header and call it like the standard `printf`:

```c
#include "ft_printf.h"

int main(void)
{
    int ret = ft_printf("Hello, %s! You are %d years old.\n", "Alice", 30);
    ft_printf("Characters printed: %d\n", ret);
    return (0);
}
```

Linking with the library:

```bash
cc main.c libftprintf.a -o ft_printf
```

# Algorithm


1. Initialize the variadic argument list with `va_list`.
2. Iterate over the format string character by character.
3. If the current character is not `%`, write it to stdout and increment the counter.
4. If the current character is `%`:
   - Parse the optional flags, field width, and precision (bonus).
   - Identify the conversion specifier.
   - Retrieve the corresponding argument with `va_arg`.
   - Dispatch to the matching printer function (`g_print_char`, `g_print_str`, `g_print_int`, `g_print_unsigned`, `g_print_hex`, `g_print_pointer`, `g_print_percent`).
   - Add the number of characters printed to the running counter.
5. End the variadic argument list with `va_end`.
6. Return the total number of characters printed.


# Bonus Part

The bonus part extends `ft_printf` with support for **format options**, all combinable with the mandatory conversions:

- **`-`** — left-justify the output within the given field width.
- **`0`** — left-pad the output with zeros instead of spaces (ignored when `-` is present).
- **`.` (precision)** — minimum number of digits for integers, maximum length for strings.
- **`#`** — add the `0x` / `0X` prefix to hexadecimal conversions.
- **`+`** — force a `+` or `-` sign before signed numbers.
- **` ` (space)** — print a space before a positive number if no sign is printed.
- **Width** — specify a minimum field width.

To support these options, the parser was extended before the conversion dispatch step:

1. Collect every flag into a small **bitmask** (each flag is one bit).
2. Parse the field width if present.
3. Parse the precision if a `.` is present.
4. Pass the collected options to the printer function, which applies padding, sign, and prefix logic accordingly.



# Data Structures

The project relies on **simple, stack-allocated types** and avoids heavy data structures, in line with the 42 Norm and the goal of keeping the implementation fast and memory-safe.

- **`t_flags` (bitmask)** — a single `int` stores all active flags. Each flag is one bit, which makes flag checking (e.g., `if (flags & FLAG_MINUS)`) extremely fast and avoids a struct with many `bool` members.
- **`t_format` (optional struct)** — groups `flags`, `width`, and `precision` for readability when passing formatting information to the printer functions.
- **`va_list`** — provided by `stdarg.h` to retrieve arguments in the order they appear in the format string.
- **No dynamic allocation** — the function prints directly with `write(1, ...)` and uses small local buffers for number conversion. This eliminates memory-leak risks and keeps the code aligned with the 42 philosophy.

# Resources

- [`printf(3) - Linux manual`] — Reference behaviour of the original function.
- [`stdarg(3) - Linux manual`] — Variadic functions and `va_list`, `va_start`, `va_arg`, `va_end`.
- [`write(2) - Linux manual`] — Writing output to a file descriptor.
- [`malloc(3) - Linux manual`] — Dynamic memory allocation (used only where needed).
- [`cppreference — printf`] — Detailed conversion specifier and flag reference.
- [`42 Norm`] — The official coding style guide of 42.

## AI Usage

AI was used as a learning and documentation assistant during this project.

It helped with:
- Structuring and improving the README.
- Explaining the algorithm and the role of variadic functions.
- Clarifying concepts related to parsing, bitmasks, and number conversion.
- Reviewing edge cases of `printf` formatting (e.g., `0` combined with precision, `+` with space).

All core code, function implementations, Makefile, and project structure were written manually.
```
