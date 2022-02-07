INCLUDE := "../../include"

main:
	mkdir -p build
	gcc twoSum.c main.c -I$(INCLUDE) -o build/main -DOJ_LOCAL -O1 -std=c99 -g

clean:
	rm -rf build
