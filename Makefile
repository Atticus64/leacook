SILENT:=@
PROJECT:=learnc
CC:=gcc
GDB_FLAGS:=-Wall -Wextra -Werror -Og -ggdb
OPT_FLAGS:=-O2 -march=native
LIB_FLAGS:=-Wall -Wextra -Werror
CC_FLAGS:=-c -I./
LD_FLAGS:=$(LIB_FLAGS)
TEST_LIBS:=-lcunit

LIB_DS_SRC:=$(wildcard lib/ds/*.c)
LIB_UTILS_SRC:=$(wildcard lib/utils/*.c)
LIB_LANG_SRC:=$(wildcard lib/lang/*.c)
LIB_EXAMPLES_SRC:=$(wildcard lib/examples/*.c)
CORE_SRC:=$(wildcard src/*.c)
TEST_DS_SRC:=$(wildcard test/ds/*.c)
TEST_UTILS_SRC:=$(wildcard test/utils/*.c)
TEST_MAIN_SRC:=$(wildcard test/test_main.c)

LIB_DS_OBJ:=$(patsubst lib/ds/%.c,obj/lib.ds.%.c.o,$(LIB_DS_SRC))
LIB_UTILS_OBJ:=$(patsubst lib/utils/%.c,obj/lib.utils.%.c.o,$(LIB_UTILS_SRC))
LIB_LANG_OBJ:=$(patsubst lib/lang/%.c,obj/lib.lang.%.c.o,$(LIB_LANG_SRC))
LIB_EXAMPLES_OBJ:=$(patsubst lib/examples/%.c,obj/lib.examples.%.c.o,$(LIB_EXAMPLES_SRC))
CORE_OBJ:=$(patsubst src/%.c,obj/src.%.c.o,$(CORE_SRC))
TEST_DS_OBJ:=$(patsubst test/ds/%.c,obj/test.ds.%.c.o,$(TEST_DS_SRC))
TEST_UTILS_OBJ:=$(patsubst test/utils/%.c,obj/test.utils.%.c.o,$(TEST_UTILS_SRC))
TEST_MAIN_OBJ:=$(patsubst test/%.c,obj/test.%.c.o,$(TEST_MAIN_SRC))

LIB_OBJ:=$(LIB_DS_OBJ) $(LIB_UTILS_OBJ) $(LIB_LANG_OBJ) $(LIB_EXAMPLES_OBJ)
TEST_OBJ:=$(TEST_DS_OBJ) $(TEST_UTILS_OBJ) $(TEST_MAIN_OBJ)

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
	$(SILENT) printf "LD $(PROJECT)\n"
	$(SILENT) $(CC) $(LD_FLAGS) $(LIB_OBJ) $(CORE_OBJ) -o $(PROJECT)

release: CC_FLAGS+=$(OPT_FLAGS)
release: $(LIB_OBJ) $(CORE_OBJ)
	$(SILENT) printf "LD $(PROJECT)\n"
	$(SILENT) $(CC) $(LD_FLAGS) $(LIB_OBJ) $(CORE_OBJ) -o $(PROJECT)

test: $(LIB_OBJ) $(TEST_OBJ)
	$(SILENT) printf "LD $(PROJECT)-test\n"
	$(SILENT) $(CC) $(LD_FLAGS) $(LIB_OBJ) $(TEST_OBJ) -o $(PROJECT)-test $(TEST_LIBS)

obj/lib.ds.%.c.o: lib/ds/%.c
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/lib.utils.%.c.o: lib/utils/%.c
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/lib.lang.%.c.o: lib/lang/%.c
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/lib.examples.%.c.o: lib/examples/%.c
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/src.%.c.o: src/%.c
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/test.ds.%.c.o: test/ds/%.c
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/test.utils.%.c.o: test/utils/%.c
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@

obj/test.%.c.o: test/%.c
	$(SILENT) $(CC) $(CC_FLAGS) $< -o $@
