CC = gcc
TARGET = matrix
CFLAGS = -c -Wall -ansi -o
SOURCE_DIR = src/
INCLUDE = -I$(SOURCE_DIR)include
SOURCES = $(wildcard $(SOURCE_DIR)*.c)
OBJECTS = $(subst .c,.o,$(SOURCES))
LIBS = -lm
INSTALL_DIR = /usr/local/bin/

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $^ $(LIBS)

$(SOURCE_DIR)%.o: $(SOURCE_DIR)%.c
	$(CC) $(CFLAGS) $@ $< $(INCLUDE)

.PHONY: clean cleanall install

clean:
	-rm -f $(OBJECTS)

cleanall:
	-rm -f $(OBJECTS) $(TARGET)

install:
	@if [ ! -f "$(TARGET)" ]; then                                   \
	  echo $(TARGET) is not build yet.;                              \
	elif [ ! -w "$(INSTALL_DIR)" ]; then                             \
	  echo $(INSTALL_DIR) has no write permissions for $(USER).;     \
	elif [ "$(USER)" != "root" ]; then                               \
	  echo "You have no sudo rights. Try using 'sudo make install'.";\
	else                                                             \
	  cp $(TARGET) $(INSTALL_DIR);                                   \
	fi
