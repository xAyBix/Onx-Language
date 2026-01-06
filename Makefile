all:
	gcc -Iinclude src/onxc.c src/commands/*.c -o build/onxc
clean:
	rm build/onxc
