EXE=ipcli

SRC=$(wildcard *.cpp)
CXXFLAGS=-Wall -Wextra -MMD -Wno-unknown-pragmas -Dcimg_display=0 -Dcimg_use_openmp=0
LDFLAGS=

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(OBJ:.o=.d)

.PHONY: all
all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf build/

-include $(DEP)
