CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g -O0 -Iinclude

SRC_DIR=src
BUILD_DIR=build

TARGET=./codedna

SRC = $(shell find $(SRC_DIR) -name "*.c")
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

all: prepare $(TARGET)

prepare:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/similarity
	mkdir -p $(BUILD_DIR)/lexical_metrics
	mkdir -p $(BUILD_DIR)/structural_metrics

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) -lm

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

run: all
	$(TARGET)

debug: all
	gdb $(TARGET)

.PHONY: all clean run debug prepare