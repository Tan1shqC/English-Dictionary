SHELL = /bin/sh
CC = gcc

apps: libraries
	cd apps; make maxchain
	cd apps; make subwords

libraries:
	cd trie; make
	cd utils; make

clean:
	cd trie; rm -rf trie.o
	cd utils; rm -rf dictload.o dictutils.o

complete_clean:
	cd trie; rm -rf trie.o libtrie.so
	cd utils; rm -rf dictload.o dictutils.o libwordutils.so
	cd apps; rm -rf ./max ./sub