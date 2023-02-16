all:
	cc -O3 src/*.c

run:
	cc src/*.c 
	./a.out

debug:
	cc -g *.c
test:
	cc tests/test.c src/lake.c src/seed.c src/csv.c
	./a.out
graph:
	python3 scripts/graph.py
