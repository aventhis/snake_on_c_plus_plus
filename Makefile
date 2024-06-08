# Имя исполняемого файла
TARGET = snake_game

# Компилятор
CC = g++

# Флаги компиляции
CFLAGS = -std=c++17 -g -Wall -Werror -Wextra 

# Флаги для линковки
LDFLAGS = -lncurses

# Файлы исходного кода
SOURCES = snake_game_model.cpp snake_game_view.cpp snake_game_controller.cpp  main.cpp

# Цель по умолчанию
all: $(TARGET)

$(TARGET): 
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	$(RM) $(TARGET) *.o
# $(RM) - rm -f

rebuild: clean all