CXX = g++
CXXFLAGS = -O -std=c++11

all : test_newton kepler

test_newton : newton.o test_newton.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

kepler : matrix.o kepler.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

newton.o : newton.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

matrix.o : matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean :
	\rm -f *.txt
