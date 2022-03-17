.PHONY: build test


build:
	mkdir build
	cd build && cmake .. && cmake --build .
	
	
test:
	"./build/tests/test_roads"

clean:
	rm -rf build