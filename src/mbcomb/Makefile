SRCS = $(wildcard Src/*.c)
OBJECTS = $(patsubst %.c,%.o,$(SRCS))
DEPS = $(patsubst %.c,%.d,$(SRCS))
EXSRCS = $(wildcard Examples/*.c)
EXAMPLES = $(patsubst %.c,%,$(EXSRCS))
ALL = libmbcomb.a $(EXAMPLES)

all : $(ALL)

.c.o :
	$(CC) $(CFLAGS) -I Include -c $< -o $@

%: %.c libmbcomb.a
	$(CC) $(CFLAGS) -I Include -L ./ -o $@ $< -lmbcomb

%.d : %.c
	@makedepend -I Include -f - $< | sed 's,\($*\.o\)[ :]*,\1 $@ : ,g' > $@

-include $(DEPS)

libmbcomb.a : $(OBJECTS)
	$(AR) -rcs $@ $(OBJECTS)

.PHONY : clean

clean:
	rm -f $(ALL)
	rm -f $(OBJECTS)
	rm -f $(DEPS)





