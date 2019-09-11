SOURCES = src/matrix/matrix.cpp \
		  src/matrix/banded_matrix.hpp \
		  src/main/main.cpp

CFLAGS = -std=c++17

%.o: %.cpp
	g++ -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

solvant : $(SOURCES)
	g++ $(CFLAGS) -o solvant $(SOURCES)
