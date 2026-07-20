# Makefile for rlecompress and rledecompress
# Both compiled to this same directory.
CXX      = g++
CXXFLAGS = -O2 -Wall -std=c++17

TARGETS = rlecompress rledecompress

all: $(TARGETS)

rlecompress: rlecompress.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

rledecompress: rledecompress.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGETS) *.o
