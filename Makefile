all: sort_algo

spoofing: sort_algo.c
	gcc -o sort_algo sort_algo.c

clean:
	rm sort_algo
