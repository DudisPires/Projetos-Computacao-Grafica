# Nome do executável
TARGET = casinha2

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall

# Bibliotecas necessárias para OpenGL + GLUT
LIBS = -lGL -lGLU -lglut -lm

# Arquivos fonte
SRC = casinha2.c

# Regra padrão
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Para rodar
run: $(TARGET)
	./$(TARGET)

# Para limpar arquivos gerados
clean:
	rm -f $(TARGET)