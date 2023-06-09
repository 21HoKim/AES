all : AES

AES : main.c
		gcc -o AES main.c gmult.c aes.c

clean:
		rm -f AES
