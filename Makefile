# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Find all .c files recursively
SRCS = $(shell find $(SRC_DIR) -name '*.c')
# Replace src/.. with build/.. and .c with .o
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Target binary
TARGET = $(BUILD_DIR)/Spl1_CodeDNA++

# Default rule
all: $(BUILD_DIR) $(TARGET)

# Create build folder if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link all .o files into final binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean build folder
clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean
