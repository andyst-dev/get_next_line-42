# get_next_line

A custom line-reading function developed as part of the 42 curriculum.
`get_next_line` is a small C function that reads from a file descriptor and returns one line at a time while keeping the unread remainder between calls.

It was a good way to build solid foundations in file descriptor I/O, dynamic memory management and the use of static variables to preserve state between function calls.

## Features
- Reads a file or input stream line by line
- Uses a static variable to preserve unread data between calls
- Supports configurable buffer sizes through `BUFFER_SIZE`
- Includes bonus support for multiple file descriptors

## Project structure
- `get_next_line.h` — header file for the mandatory part
- `get_next_line.c` — main line-reading logic
- `get_next_line_utils.c` — helper functions for string handling
- `get_next_line_bonus.h` — header file for the bonus part
- `get_next_line_bonus.c` — multi-file-descriptor version
- `get_next_line_utils_bonus.c` — helper functions for the bonus part

## Mandatory part
The mandatory part focuses on the line-reading logic required to return one line at a time from a file descriptor.

### Main function
- `get_next_line` — reads from a file descriptor and returns the next available line, including the trailing newline when present

### Helper functions
- `ft_strlen` — returns the length of a string
- `ft_strchr` — locates a character inside a string
- `ft_strdup` — duplicates a string using dynamic allocation
- `ft_strjoin` — joins two strings into a newly allocated buffer

## Bonus part
The bonus version extends the project to handle multiple file descriptors at the same time.

### Bonus features
- support for multiple file descriptors without losing state between calls
- separate unread buffers tracked per file descriptor
- same line-by-line behavior as the mandatory version

## Build
The project is generally compiled with a buffer size definition, for example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Bonus version:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Notes
This project does not build a standalone executable on its own.
It provides source files meant to be compiled and used inside a test program or another C project.

## Learning outcomes
This project was my first real introduction to stateful file reading in C.
It helped build solid foundations in:
- file descriptor handling
- buffered reading with `read`
- static variable usage
- memory allocation and cleanup
- newline detection and leftover storage
- incremental parsing logic
