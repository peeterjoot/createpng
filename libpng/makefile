CXXFLAGS += -std=c++17
CXXFLAGS += -MMD
#OPTIMIZE := 1
ifdef OPTIMIZE
CXXFLAGS += -O2
else
CXXFLAGS += -g
endif
CXX := g++

#LDFLAGS +=
LOADLIBES += -lpng

TARGETS += pngtry

all : $(TARGETS)

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(filter %.cc,$^) -c -o $@

pngtry : pngtry.o
	$(CXX) $(CXXFLAGS) $(filter %.o,$^) -o $@ $(LDFLAGS) $(LOADLIBES) 

clean:
	rm -f $(TARGETS) *.o *.d *.png

-include $(wildcard *.d)
