# Environment
CXXFLAGS=`fltk-config --cxxflags` --std=c++11 -g
LDFLAGS=`fltk-config --ldflags`
CXX=`fltk-config --cxx`

#The Apps
TARGETS=grid_test
all: $(TARGETS)
grid_test: grid_test.o grid_widget.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

#The Ingredients
grid_widget.o: grid_widget.cpp grid_widget.h
grid_test.o: grid_test.cpp grid_widget.h

#FLUID ingredient builds
%.h %.cxx: %.fl
	fluid -c $^

# utility
clean:
	rm -f *.o $(TARGETS)
