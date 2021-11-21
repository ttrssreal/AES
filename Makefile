target = bin/aes

LDFLAGS = -Wall -Iinclude/ -g
CC = g++

src =\
	main.cpp\
	aes.cpp\
	keySchedule.cpp\
	util.cpp

$(target): $(addprefix src/, $(src))
	$(CC) -o $@ $^ $(LDFLAGS)

tests =\
	test.cpp\
	test_keySchedule.cpp\
	test_aes.cpp

tests: $(filter-out src/main.cpp, $(addprefix src/, $(src))) $(addprefix test/, $(tests))
	$(CC) -o bin/tests $^ $(LDFLAGS)