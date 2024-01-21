CC=clang++
CFLAGS=-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++17
OUTS=$(patsubst %.cpp,%.out,$(wildcard *.cpp))

.PHONY: clean

all: $(OUTS) 

$(OUTS): %.out: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.out

run: $(OUTS)
	for file in $^ ; do \
		echo "=============================================" ; \
		echo "Testing '$${file}'" ; \
		echo "---------------------------------------------" ; \
		./$${file} ; \
	done

