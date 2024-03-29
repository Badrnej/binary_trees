# Makefile for all tasks
# usage
# make task TASK_NUM=<task_number> && ./binary_trees && make -s clean

# the compiler to be used
CC = gcc
# Common files
COMMON = 0-binary_tree_node.c binary_tree_print.c 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c 3-binary_tree_delete.c 14-binary_tree_balance.c 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c 111-bst_insert.c 112-array_to_bst.c 121-avl_insert.c 122-array_to_avl.c 123-avl_remove.c 131-heap_insert.c 132-array_to_heap.c 133-heap_extract.c

# Task files - the rest are in common due to repetitive use
0 = main_files/0-main.c
1 = main_files/1-main.c #
...

TASK_NUM ?= 0
TASK_VAR := $(shell echo '$($(TASK_NUM))')
MAIN := $(if $(TASK_VAR),$(TASK_VAR),invalid_task)

# the .c files
SRC = $(COMMON) $(MAIN)
# the .o files
# the name of the executable
NAME = binary_trees
# the program to delete files
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -pedantic

.PHONY: all binary_trees clean re task
# builds executable
# recompile only the updated source files
all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME) *~ .*~ *.swp

re: clean task

task:
	@if [ "$(MAIN)" = "invalid_task" ]; then \
		echo "Invalid task number: $(TASK_NUM)"; \
	else \
		echo -e "Building for task $(TASK_NUM): $(MAIN)\n\n"; \
		$(MAKE) all MAIN="$(MAIN)"; \
	fi

debug:
	@echo "TASK_NUM=$(TASK_NUM)"
	@echo "TASK_VAR=$(TASK_VAR)"
	@echo "MAIN=$(MAIN)"
