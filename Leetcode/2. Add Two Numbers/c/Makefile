INCLUDE := "../../include"

main:
	mkdir -p build
	gcc addTwoNumbers.c main.c -I$(INCLUDE) -o build/main -DOJ_LOCAL -O1 -std=c99 -g

clean:
	rm -rf build
