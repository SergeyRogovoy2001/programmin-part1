CFLAGS = -Wall -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage
LDFLAGS = -L. -fprofile-arcs -ftest-coverage

# Вхідні файли
SRC = main.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = app

# Завдання за замовчуванням
.PHONY: all build x86 x86_64 asm clean doc debug

# Завдання
all: build

build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

x86:
	$(MAKE) CFLAGS="$(CFLAGS) -m32" LDFLAGS="$(LDFLAGS) -m32" build

x86_64:
	$(MAKE) CFLAGS="$(CFLAGS) -m64" LDFLAGS="$(LDFLAGS) -m64" build

asm: $(SRC)
	$(CC) $(CFLAGS) -S -masm=intel $< -o $(SRC:.c=.s)

clean:
	rm -f $(OBJ) $(EXECUTABLE) *.s

doc:
	@echo "Generating documentation..."
	pandoc -o report.pdf report.md || echo "Install pandoc to generate documentation."

debug: build
	gdb ./$(EXECUTABLE)
