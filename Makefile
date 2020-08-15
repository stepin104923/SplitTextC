SRC = unity/unity.c\
src/factorial.c\
test/test_factorial.c\
main.c

INC = -Iunity\
-Iinc\
-Itest

EXEC_FILE = test.out
UNITY_LOG = unity.log
VALGRIND_LOG = valgrind.log

.PHONY: build test testmem testall gdb doc clean

$(EXEC_FILE): $(SRC)
	gcc $^ $(INC) -o $@

build: $(EXEC_FILE)

test: build
	./${EXEC_FILE}

testmem: build
	valgrind ./${EXEC_FILE}

testall: build
	valgrind -v --log-file=${VALGRIND_LOG} ./${EXEC_FILE} | tee ${UNITY_LOG}

gdb: build
	gdb ${EXEC_FILE}

doc:
	make -C documentation

clean:
	rm -rf *.out *.log documentation/html
