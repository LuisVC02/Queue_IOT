
CC ?= gcc

APP_NAME_1 = queue_send
OBJ_FILES_1  = queue_send.o

APP_NAME_2  = queue_rcv
OBJ_FILES_2 = queue_rcv.o

LIBS = .
LIB = rt

all: $(APP_NAME_1) $(APP_NAME_2)

$(APP_NAME_1): $(OBJ_FILES_1)
	$(CC) $^ -o $@ -L$(LIBS) -l$(LIB)


$(APP_NAME_2): $(OBJ_FILES_2)
	$(CC) $^ -o $@ -L$(LIBS) -l$(LIB)

%.o: %.c
	$(CC) -o $@ -c $^ -g


clean:
	rm *.o $(APP_NAME_1) $(APP_NAME_2)

fresh:
	make clean
	make all
