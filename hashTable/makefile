CFLAGS = -Wall -Wextra -Werror -Wfloat-equal -pedantic -ansi -lm
INCS = mybst.h

all: hash hash_d


hash:  bst.c hash.c $(INCS)
	$(CC) bst.c hash.c -o hash -O3 $(CFLAGS)

hash_d:  bst.c thread.c $(INCS)
	$(CC) bst.c hash.c -o hash_d -g -O $(CFLAGS)

run: all

	./hash

	
memchk: hash_d
	valgrind --error-exitcode=1 --quiet --leak-check=full ./hash
clean:
	rm -f hash hash_d 

.PHONY: clean run memchk all
