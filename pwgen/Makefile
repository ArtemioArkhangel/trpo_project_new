CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
TEST_DIR = tests

TARGET = $(BIN_DIR)/pwgen
TEST_TARGET = $(BIN_DIR)/test_runner

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/pwgenfunc.c
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/pwgenfunc.o

TEST_SRCS = $(TEST_DIR)/test_main.c $(TEST_DIR)/test_pwgenfunc.c $(SRC_DIR)/pwgenfunc.c
TEST_OBJS = $(BUILD_DIR)/test_main.o $(BUILD_DIR)/test_pwgenfunc.o $(BUILD_DIR)/pwgenfunc_test.o

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	@echo "Запуск юнит-тестов"
	@$(TEST_TARGET)
	@echo " Все тесты пройдены"

$(TEST_TARGET): $(TEST_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/test_main.o: $(TEST_DIR)/test_main.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test_pwgenfunc.o: $(TEST_DIR)/test_pwgenfunc.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/pwgenfunc_test.o: $(SRC_DIR)/pwgenfunc.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)