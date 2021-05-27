CC = g++
PARAMS = -std=c++17 -Wall -o
OUTNAME = d2h
FILE = main.cpp

d2hmake:
	$(CC) $(PARAMS) $(OUTNAME) $(FILE)
