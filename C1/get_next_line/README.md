*This project has been created as part of the 42 curriculum by mbihti*

# Description

`get_next_line` is a useful function that reads a file or input stream one line at a time.

The goal of this project is to create a function that returns the next line from a file descriptor each time it is called, without reading the entire file at once.

Unlike standard functions that read large amounts of data at once, `get_next_line` allows us to process a file line by line. This makes it useful when working with large files or when we only need to process specific lines.

The function uses the `read()` system call to retrieve data from a file descriptor in chunks determined by `BUFFER_SIZE`. It then searches for a newline character (`\n`) to determine where the current line ends.

Each call returns a dynamically allocated string containing the next line, including the newline character if one exists. When there is no more data to read, or an error occurs, the function returns `NULL`.

One of the main challenges of this project is preserving the data that has already been read but does not belong to the current line. This is handled using a static variable (stash), which keeps the remaining data between function calls.

The project also introduces several important concepts in C:
- File descriptors and file operations.
- Reading data using the `read()` system call.
- Static variables and data persistence between function calls.
- Dynamic memory allocation using `malloc()`.
- String manipulation and memory management.
- Handling EOF (End Of File) and reading errors.

The bonus part adds support for multiple file descriptors, allowing several files to be read independently without mixing their contents.

# Instructions

## Compilation

To compile the project, use:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c -o gnl
```

`BUFFER_SIZE` determines how many bytes are read during each call to `read()`. You can change its value to test different buffer sizes.

## Execution

Run the program with:

```bash
./gnl
```

To test the function, open a file using `open()` and pass its file descriptor to `get_next_line()`, you cant also use a default stdin file descriptor to pass the file.txt.

Example:

```c
int fd = open("test.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

# Algorithm

The function uses a static variable (stash) to preserve unread data between calls.

1. Read `BUFFER_SIZE` bytes using `read()`.
2. Append the data to the stash until a newline (`\n`) is found or EOF is reached.
3. Extract and return the next line, including the newline if present.
4. Keep the remaining data in the stash for the next call.

This approach allows the function to read files progressively and handle lines of any length without loading the entire file into memory.

# Bonus Part

The bonus part extends `get_next_line_bonus` to support multiple file descriptors simultaneously.

Instead of using one static variable for all file descriptors, the bonus implementation uses a separate stash for each file descriptor.

This allows the function to read from multiple files independently without mixing their contents.

For example, you can alternate between calls to different file descriptors:

```c
line1 = get_next_line_bonus(fd1);
line2 = get_next_line_bonus(fd2);
line3 = get_next_line_bonus(fd1);
line4 = get_next_line_bonus(fd2);
```

Each file keeps its own reading position and remaining data, allowing independent reading.

# Resources

- [read() - Linux manual] — Reading data from file descriptors.
- [open() - Linux manual] — Opening files.
- [close() - Linux manual] — Closing file descriptors.
- [malloc() - Linux manual] — Dynamic memory allocation.
- [Static variables in C] — Understanding static storage duration.

## AI Usage

AI was used as a learning and documentation assistant during this project.

It helped with:
- Structuring and improving the README.
- Explaining the algorithm and static variables.
- Clarifying concepts related to file descriptors and memory management.


