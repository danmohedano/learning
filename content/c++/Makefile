CC=clang++
CFLAGS=-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++17
EXES=$(patsubst %.cpp,%.exe,$(wildcard *.cpp))

.PHONY: clean

all: $(EXES) 

$(EXES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.exe
