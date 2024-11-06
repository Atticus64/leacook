SILENT:=@

# name your program however you want it to be named
PROJECT:=learnc

CC:=gcc

GDB_FLAGS:=-Og -ggdb
OPT_FLAGS:=-O2 -march=native
LIB_FLAGS:=

CC_FLAGS:=-c -I./
LD_FLAGS:=$(LIB_FLAGS)
TEST_FLAGS:=-lcunit

LIB_SRC:=$(wildcard lib/*.c)
CORE_SRC:=$(wildcard src/*.c)
TEST_SRC:=$(wildcard test/*.c)

LIB_OBJ=$(patsubst lib/%.c, obj/lib.%.c.o, $(LIB_SRC))
CORE_OBJ=$(patsubst src/%.c, obj/src.%.c.o, $(CORE_SRC))
TEST_OBJ=$(patsubst test/%.c, obj/test.%.c.o, $(TEST_SRC))

.PHONY: clean debug release test

usage:
	$(SILENT) printf "Usage: make [options]\n"
	$(SILENT) printf "Options: \n\n"
	$(SILENT) printf "clean:   removes every object file from 'obj/' directory\n"
	$(SILENT) printf "test:    generates test build\n"
	$(SILENT) printf "debug:   optimizes code build for debug with GDB\n"
	$(SILENT) printf "release: optimizes code for performance\n\n"

clean:
	$(SILENT) printf "RM obj/*.o\n"
	$(SILENT) rm -rf obj/*.o

debug: CC_FLAGS+=$(GDB_FLAGS)
debug: $(LIB_OBJ) $(CORE_OBJ)
	$(SILENT) printf "LD obj/lib.*.o obj/src.*.o\n"
	$(SILENT) $(CC) $(LD_FLAGS) $(LIB_OBJ) $(CORE_OBJ) -o $(PROJECT)

release: CC_FLAGS+=$(OPT_FLAGS)					
release: $(LIB_OBJ) $(CORE_OBJ)					
	$(SILENT) printf "LD obj/lib.*.o obj/src.*.o\n"	
	$(SILENT) $(CC) $(LD_FLAGS) $(LIB_OBJ) $(CORE_OBJ) -o $(PROJECT)

test: $(LIB_OBJ) $(TEST_OBJ)					
	$(SILENT) printf "LD obj/lib.*.o obj/test.*.o\n"	
	$(SILENT) $(CC) $(TEST_FLAGS) $(LD_FLAGS) $(LIB_OBJ) $(TEST_OBJ) -o $(PROJECT)-test

obj/lib.%.c.o: lib/%.c
	$(SILENT) printf "CC $@\n"
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/src.%.c.o: src/%.c
	$(SILENT) printf "CC $@\n"
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/test.%.c.o: test/%.c
	$(SILENT) printf "CC $@\n"
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

