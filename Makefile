SRC = unity/unity.c\
src/split_text.c\
test/test_split_text.c\
main.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME = split_text.out

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
