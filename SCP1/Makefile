# makefile targets
all : proj1_a proj1_b proj1_c

proj1_a : nest.o matrix.o proj1_a.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

proj1_b : proj1_b.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

proj1_c : proj1_c.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

nest.o : nest.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

matrix.o : matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	\rm -f *.txt

####### End of Makefile #######
