.PHONY: build test getcov check clean


build:
	mkdir build
	cd build && cmake .. && cmake --build .
	
	
test:
	"./build/tests/test_roads"

getcov:
	cd build && lcov -t "tests/test_roads" -o coverage.info -c -d roads/ && genhtml -o report coverage.info

clean:
	rm -rf build
