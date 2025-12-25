CC=gcc
CFLAGS=-Wall -Wextra -std=c99
SRC_DIR=src
BUILD_DIR=build
INCLUDE=-Iinclude

SRC=$(shell find $(SRC_DIR) -name "*.c")
OBJ=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

TARGET=$(BUILD_DIR)/codedna

all: $(BUILD_DIR) $(TARGET)

# Create build directory and subfolders
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/lexical_metrics
	mkdir -p $(BUILD_DIR)/structural_metrics
	mkdir -p $(BUILD_DIR)/similarity

# Compile and link
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) -lm

# Compile each .c into corresponding .o in build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean
