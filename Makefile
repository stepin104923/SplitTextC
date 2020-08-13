SRC = unity/unity.c\
src/factorial.c\
test/test_factorial.c\
main.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME = FACTORIAL.out

$(PROJECT_NAME): $(SRC)
	gcc -g $(SRC) $(INC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}

gdb:$(PROJECT_NAME)
	gdb ${PROJECT_NAME}

doc:
	make -C documentation

clean:
	rm -rf $(PROJECT_NAME) documentation/html
