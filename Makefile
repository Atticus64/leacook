SILENT:=@
PROJECT:=learnc
CC:=gcc
GDB_FLAGS:=-Wall -Wextra -Werror -Og -ggdb
OPT_FLAGS:=-O2 -march=native
LIB_FLAGS:=-Wall -Wextra -Werror
CC_FLAGS:=-c -I./
LD_FLAGS:=$(LIB_FLAGS)
TEST_LIBS:=-lcunit

LIB_SRC:=$(wildcard lib/*.c)
CORE_SRC:=$(wildcard src/*.c)
TEST_SRC:=$(wildcard test/*.c)

LIB_OBJ=$(patsubst lib/%.c,  obj/lib.%.c.o,  $(LIB_SRC))
CORE_OBJ=$(patsubst src/%.c,  obj/src.%.c.o,  $(CORE_SRC))
TEST_OBJ=$(patsubst test/%.c, obj/test.%.c.o, $(TEST_SRC))

.PHONY: clean debug release test usage

usage:
	$(SILENT) printf "Usage: make [options]\n"
	$(SILENT) printf "Options:\n\n"
	$(SILENT) printf "  clean:   removes every object file from 'obj/'\n"
	$(SILENT) printf "  test:    generates test build\n"
	$(SILENT) printf "  debug:   optimizes build for GDB\n"
	$(SILENT) printf "  release: optimizes build for performance\n\n"

clean:
	$(SILENT) printf "RM obj/*.o\n"
	$(SILENT) rm -rf obj/*.o

debug: CC_FLAGS+=$(GDB_FLAGS)
debug: $(LIB_OBJ) $(CORE_OBJ)
	$(SILENT) printf "LD obj/lib.*.o obj/src.*.o -> $(PROJECT)\n"
	$(SILENT) printf "flags: $(LD_FLAGS)\n"
	$(SILENT) $(CC) $(LD_FLAGS) $(LIB_OBJ) $(CORE_OBJ) -o $(PROJECT)

release: CC_FLAGS+=$(OPT_FLAGS)
release: $(LIB_OBJ) $(CORE_OBJ)
	$(SILENT) printf "LD obj/lib.*.o obj/src.*.o -> $(PROJECT)\n"
	$(SILENT) $(CC) $(LD_FLAGS) $(LIB_OBJ) $(CORE_OBJ) -o $(PROJECT)

# -lcunit va AL FINAL, después de los .o
test: $(LIB_OBJ) $(TEST_OBJ)
	$(SILENT) printf "LD obj/lib.*.o obj/test.*.o -> $(PROJECT)-test\n"
	$(SILENT) $(CC) $(LD_FLAGS) $(LIB_OBJ) $(TEST_OBJ) -o $(PROJECT)-test $(TEST_LIBS)

obj/lib.%.c.o: lib/%.c
	$(SILENT) printf "CC $@\n"
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/src.%.c.o: src/%.c
	$(SILENT) printf "CC $@\n"
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/test.%.c.o: test/%.c
	$(SILENT) printf "CC $@\n"
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

