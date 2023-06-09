CC=clang++
FLAGS=-Wall -std=c++20 -I ./
TESTS_BIN=tests_out

.DEFAULT_GOAL:=tests
.PHONY: tests

tests:
	${CC} ${FLAGS} tests/tests.cpp -o ${TESTS_BIN}
	@./${TESTS_BIN}
	@rm ${TESTS_BIN}

clean:
	rm ${TESTS_BIN}