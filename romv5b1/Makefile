.SUFFIXES:			# delete all suffixes
.SUFFIXES: .180 .rel

SRCS = rom.180

OBJS = rom.rel

#OBJS = $(filter %.rel,$(SRCS:.180=.rel) $(SRCS:.z80=.rel))

PROG = rom.hex

all:	$(PROG) tb

tb: tbp112.mac
	zxcc m80 -"="$</L/Z
	echo 'N' | zxcc l80 -"/P:3000,/D:3000,tbp112,tb/n:p/y/x/e"

$(OBJS): $(SRCS)
	zxcc m80 -"="$</L

$(PROG): $(OBJS)
	echo 'N' | zxcc l80 -"/P:0,/D:fe00,rom,rom/n:p/y/x/e"

clean:
	rm -f $(OBJS) $(PROG) *.rel *.prn tb*.hex *.sym core *~ *.\$$\$$\$$
