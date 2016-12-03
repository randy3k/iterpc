# modified by Randy Lai (2016)

SRCS = $(wildcard Src/*.c)
OBJECTS = $(patsubst %.c,%.o,$(SRCS))
EXSRCS = $(wildcard Examples/*.c)
EXAMPLES = $(patsubst %.c,%,$(EXSRCS))
ALL = libmbcomb.a $(EXAMPLES)

all : $(ALL)

.c.o :
	$(CC) $(CFLAGS) $(CPICFLAGS) -I Include -c $< -o $@

%: %.c libmbcomb.a
	$(CC) $(CFLAGS) $(CPICFLAGS) -I Include -L ./ -o $@ $< -lmbcomb


libmbcomb.a : $(OBJECTS)
	$(AR) -rcs $@ $(OBJECTS)

.PHONY : clean

clean:
	rm -f $(ALL)
	rm -f $(OBJECTS)
	rm -f $(DEPS)
