all: 1m-block

trie.o: trie.h trie.c

dict.o: dict.h dict.c

parse.o: parse.h parse.c

1m-block.o: ess_libnet.h 1m-block.c

1m-block: 1m-block.o trie.o dict.o parse.o
	gcc -o 1m-block 1m-block.o dict.o trie.o parse.o -lnetfilter_queue

clean:
	rm -f 1m-block *.o
