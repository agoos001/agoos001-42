
```markdown
*This project has been created as part of the 42 curriculum by <mbihti>.*

# Libft

## Description

A collection of the most commonly used C functions — with the twist that this libft offers more customization than the standard library versions.

## Instructions

To compile the library, you first need to compile the source files into object files using the `cc` compiler (or `gcc`). After that, you can link all the object files into a library using `ar` with the `-rcs` flags.

To make things easier, you can simply run `make` inside the root directory — the make utility will take care of everything for you.

This produces `libft.a`. To use it in your own code:

```c
#include "libft.h"
```

```bash
cc your_file.c libft.a -o your_program
```

Available make rules: `all`, `bonus`, `clean`, `fclean`, `re`.

## The library

The library has three parts.

**Libc reimplementations** — match the standard functions' return values and edge cases. 
- Character checks & case: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- Strings: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- Memory: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- Conversion & output: `ft_atoi`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

**Additional functions** — allocate and return new objects the caller must free.
- `ft_substr` (substring, empty if index out of range)
- `ft_strjoin` (concatenate two strings)
- `ft_strtrim` (trim a set of chars from both ends)
- `ft_split` (split on a delimiter into a NULL-terminated array; frees all and returns NULL on failure)
- `ft_itoa` (int to string, handles `INT_MIN`)
- `ft_strmapi` (new string from applying a function to each char with its index)
- `ft_striteri` (in-place iteration with index and char pointer)

**linked lists functions** (`t_list` with `content` and `next`)
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`
- `ft_lstiter` (apply function to each node's content)
- `ft_lstmap` (new list from applying function to each content; cleans up on failure)
- `ft_lstdelone` (free one node's content via `del` then the node)
- `ft_lstclear` (free all nodes and set list pointer to NULL)

## Resources

- The 42 Libft subject PDF
- `man 3` pages for the original libc functions
- Norminette, the 42 coding-style checker
- The C standard (C89/C99) for edge-case behaviour
- Other students’ libft repositories for comparison and test ideas

**AI usage:** While creating this libft, I had trouble understanding some of the functions. AI helped me understand where the problem was and how to fix it — though I fixed the issues myself. AI was not used to write the code, only to explain concepts and point out mistakes.
```
