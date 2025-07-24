# Libft - Improved Structure

A well-organized implementation of the 42 School libft project with a clean folder structure for better maintainability and reusability.

## 📁 Project Structure

```
libft_improved/
├── libft.h          # Main header file with all function prototypes
├── Makefile         # Enhanced Makefile with organized compilation
├── str/             # String manipulation functions
├── mem/             # Memory management functions
├── nbr/             # Number and character functions
├── lst/             # Linked list functions
├── printf/          # Printf implementation
└── get_next_line/   # Get next line implementation (bonus: multiple fd)
```

## 🚀 Quick Start

### Build the library
```bash
make
```

### Clean object files
```bash
make clean
```

### Complete clean (objects + library)
```bash
make fclean
```

### Rebuild everything
```bash
make re
```

### Show help
```bash
make help
```

## 📚 Function Categories

### String Functions (`str/`)
- `ft_strlen` - Calculate string length
- `ft_strchr` - Find character in string
- `ft_strrchr` - Find character from end
- `ft_strncmp` / `ft_strcmp` - Compare strings
- `ft_strlcpy` / `ft_strlcat` - Safe string copy/concatenation
- `ft_strnstr` - Find substring
- `ft_strdup` - Duplicate string
- `ft_substr` - Extract substring
- `ft_strjoin` - Join two strings
- `ft_strtrim` - Trim whitespace
- `ft_split` - Split string by delimiter
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Iterate with function

### Memory Functions (`mem/`)
- `ft_memset` - Fill memory with value
- `ft_bzero` - Zero out memory
- `ft_memcpy` - Copy memory
- `ft_memmove` - Safe memory move
- `ft_memchr` - Find byte in memory
- `ft_memcmp` - Compare memory
- `ft_calloc` - Allocate zeroed memory

### Number & Character Functions (`nbr/`)
- `ft_isalpha` / `ft_isdigit` / `ft_isalnum` - Character checks
- `ft_isascii` / `ft_isprint` - ASCII checks
- `ft_toupper` / `ft_tolower` - Case conversion
- `ft_atoi` - String to integer
- `ft_itoa` - Integer to string
- `ft_putchar_fd` / `ft_putstr_fd` - Output functions
- `ft_putendl_fd` / `ft_putnbr_fd` - Output with formatting

### List Functions (`lst/`)
- `ft_lstnew` - Create new node
- `ft_lstadd_front` / `ft_lstadd_back` - Add nodes
- `ft_lstsize` - Get list size
- `ft_lstlast` - Get last node
- `ft_lstdelone` - Delete single node
- `ft_lstclear` - Clear entire list
- `ft_lstiter` - Iterate with function
- `ft_lstmap` - Map function to new list

### Printf Functions (`printf/`)
- `ft_printf` - Printf implementation
- Supporting functions for various format specifiers

### Get Next Line Functions (`get_next_line/`)
- `get_next_line` - Read a file line by line (bonus: supports multiple file descriptors simultaneously)

## 🔧 Usage in Other Projects

1. Copy the entire `libft_improved` folder to your project
2. Include the header: `#include "libft_improved/libft.h"`
3. Add to your Makefile:
   ```makefile
   LIBFT_DIR = libft_improved
   LIBFT = $(LIBFT_DIR)/libft.a
   
   $(LIBFT):
   	$(MAKE) -C $(LIBFT_DIR)
   
   your_program: $(LIBFT) your_objects
   	$(CC) $(CFLAGS) your_objects -L$(LIBFT_DIR) -lft -o your_program
   ```

## 🎯 Future Additions

The structure is prepared for easy addition of:
- `get_next_line/` - For GNL functions
- `bonus/` - For additional bonus functions
- `utils/` - For utility functions

## 📝 Notes

- All functions maintain 42 School norminette compliance
- Enhanced Makefile with colored output and better organization
- Modular structure allows for easy maintenance and testing
- Compatible with existing projects using the original libft
