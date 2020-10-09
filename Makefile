SHARED_OBJ=_vector`python3-config --extension-suffix`

CXXFLAGS=-Wall -shared -std=c++11 -fPIC \
	`python3 -m pybind11 --includes`

LDFLAGS=`python3-config --ldflags`

SRC=main.cpp

$(SHARED_OBJ): $(SRC)
	g++ $(CXXFLAGS) -o $(SHARED_OBJ) $^ $(LDFLAGS)

clean:
	rm -rf $(SHARED_OBJ)

.PHONY: clean
