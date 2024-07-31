
.PHONY: all
all: build
	cd build && \
	cmake --build .

build: CMakeLists.txt $(wildcard */CMakeLists.txt)
	mkdir -p build && \
	cd build && \
	cmake ..


.PHONY: clean
clean:
	@rm -vfr --preserve-root -- build
