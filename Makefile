SOURCE_FOLDER=src/
OBJ_FOLDER=obj/
TEST_FOLDER=test/
BUILD_FOLDER=build/
TEST_EXE=tests.exe

_compile_obj:
	gcc -c $(SOURCE_FOLDER)node.c -o $(OBJ_FOLDER)node.o
	gcc -c $(SOURCE_FOLDER)iterator.c -o $(OBJ_FOLDER)iterator.o
	gcc -c $(SOURCE_FOLDER)linked_list.c -o $(OBJ_FOLDER)linked_list.o

_compile_test_obj:
	gcc -c $(TEST_FOLDER)$(SOURCE_FOLDER)test_node.c -o $(TEST_FOLDER)$(OBJ_FOLDER)test_node.o
	gcc -c $(TEST_FOLDER)$(SOURCE_FOLDER)test_linked_list.c -o $(TEST_FOLDER)$(OBJ_FOLDER)test_linked_list.o
	gcc -c $(TEST_FOLDER)$(SOURCE_FOLDER)test_iterator.c -o $(TEST_FOLDER)$(OBJ_FOLDER)test_iterator.o

build_object:
	make _compile_obj
	ar cr data_structures.a $(BUILD_FOLDER)*.o

build_test:
	make _compile_obj
	make _compile_test_obj
	ar cr $(TEST_FOLDER)$(OBJ_FOLDER)tests.a $(OBJ_FOLDER)*.o $(TEST_FOLDER)$(OBJ_FOLDER)*.o
	gcc $(TEST_FOLDER)main.c -o $(TEST_EXE) $(TEST_FOLDER)$(OBJ_FOLDER)tests.a

rm_obj:
	rm $(OBJ_FOLDER)*.o
	rm $(TEST_FOLDER)$(OBJ_FOLDER)*.o
	rm $(TEST_FOLDER)$(OBJ_FOLDER)*.a

win_rm_obj:
	del obj\*.o
	del test\obj\*.o
	del test\obj\*.a
