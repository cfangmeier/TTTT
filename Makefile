CC=clang++
CFLAGS=`root-config --libs --cflags` -Wall
CFLAGS_DEBUG=$(CFLAGS) -g3 -O0
INCLUDEDIR=-I.

TTTT_Analysis: TTTT_Analysis.cpp
		clear
		$(CC) -o main TTTT_Analysis.cpp $(CFLAGS_DEBUG) $(INCLUDEDIR)
		# $(CC) -o main TTTT_Analysis.cpp $(CFLAGS) $(INCLUDEDIR)
