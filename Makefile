CC=gcc
CFLAGS=-Wall

SRC=src
OBJ=obj
AMALGAMATION=data_structures
BUILD=build

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

TEST=tests
TESTS=$(wildcard $(TEST)/$(SRC)/*.c)
TESTOBJS=$(patsubst $(TEST)/$(SRC)/%.c, $(TEST)/$(OBJ)/%.o, $(TESTS))
TESTBIN=$(TEST)/$(OBJ)/tests.a

ifeq ($(OS),Windows_NT)
	CLEAR=del $(OBJ)\*.o $(TEST)\$(OBJ)\*.o $(TEST)\$(OBJ)\tests.a && rmdir $(OBJ) $(TEST)\$(OBJ)
	MKDIR_OBJ=IF exist $(OBJ) (echo "ok") ELSE (mkdir $(OBJ))
	MKDIR_BUILD=IF exist $(BUILD) (echo "ok") ELSE (mkdir $(BUILD))
	MKDIR_TEST_OBJ=IF exist $(TEST)\$(OBJ) (echo "ok") ELSE (mkdir $(TEST)\$(OBJ))
else
	CLEAR=rm $(OBJ)/*.o $(TEST)/$(OBJ)/*.o $(TESTBIN) && rmdir $(OBJ) $(TEST)/$(OBJ)
	MKDIR_OBJ=if test -d $(OBJ); then echo "ok"; else mkdir $(OBJ); fi
	MKDIR_BUILD=if test -d $(BUILD); then echo "ok"; else mkdir $(BUILD); fi
	MKDIR_TEST_OBJ=if test -d $(TEST)/$(OBJ); then echo "ok"; else mkdir $(TEST)/$(OBJ); fi
endif

$(OBJ)/%.o: $(SRC)/%.c
	$(MKDIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/$(OBJ)/%.o: $(TEST)/$(SRC)/%.c
	$(MKDIR_TEST_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/$(AMALGAMATION).c:
	$(MKDIR_BUILD)
	python tools/amalgamator.py

$(TESTBIN): $(OBJS) $(TESTOBJS)
	ar cr $@ $(OBJS) $(TESTOBJS)

test: $(TESTBIN)
	$(CC) $(CFLAGS) $(TEST)/main.c -o $@ $(TESTBIN)

clean:
	$(CLEAR)
