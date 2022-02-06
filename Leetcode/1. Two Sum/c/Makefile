INCLUDE := "../../include"

main:
	mkdir -p build
	gcc-11 twoSum.c main.c -I$(INCLUDE) -o build/main -DOJ_LOCAL -O2 -g

clean:
	rm -rf build
