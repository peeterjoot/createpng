CXXFLAGS += -std=c++17
CXXFLAGS += -MMD
#OPTIMIZE := 1
ifdef OPTIMIZE
CXXFLAGS += -O2
else
CXXFLAGS += -g
endif
CXXFLAGS += -I/usr/include/ImageMagick-6
CXX := g++

#LDFLAGS +=
#LOADLIBES += -lMagick++-6.Q16

TARGETS += p6

all : $(TARGETS)

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(filter %.cc,$^) -c -o $@

p6 : p6.o
	$(CXX) $(CXXFLAGS) $(filter %.o,$^) -o $@ $(LDFLAGS) $(LOADLIBES) 

clean:
	rm -f $(TARGETS) *.o *.d *.ppm *.png

-include $(wildcard *.d)
