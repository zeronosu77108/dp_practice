CXX=clang++
CXXFLAGS=-std=c++17 -Wall

all: subset_sum knapsack LCS Levenshtein_distance

subset_sum: subset_sum.cpp
	$(CXX) $(CXXFLAGS) -o subset_sum subset_sum.cpp


knapsack: knapsack.cpp
	$(CXX) $(CXXFLAGS) -o knapsack knapsack.cpp


LCS: LCS.cpp
	$(CXX) $(CXXFLAGS) -o LCS LCS.cpp

Levenshtein_distance: Levenshtein_distance.cpp
	$(CXX) $(CXXFLAGS) -o Levenshtein_distance Levenshtein_distance.cpp

clean:
	rm -rf Levenshtein_distance LCS subset_sum knapsack a.out
