a:
	gcc -Iinclude src/onxc.c src/commands/*.c src/io/*.c src/orchestration/*.c src/tokenizer/*.c -o build/onxc
c:
	rm build/onxc
