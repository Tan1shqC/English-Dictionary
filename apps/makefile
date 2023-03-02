wSHELL = /bin/sh
CC = gcc

maxchain:
	gcc -Wall -o max maxchain.c -I../trie -I../utils -L../trie -L../utils -ltrie -lwordutils
	export LD_LIBRARY_PATH"=../trie:../utils"; ./max

subwords:
	gcc -Wall -o sub subwords.c -I../trie -I../utils -L../trie -L../utils -ltrie -lwordutils
	export LD_LIBRARY_PATH"=../trie:../utils"; ./sub