all:
	cc -O3 src/csv.c src/lake.c src/main.c src/seed.c
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
