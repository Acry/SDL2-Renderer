CFLAGS   = -Wall -Wextra -mtune=native -no-pie `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2_image -lm

.SUFFIXES:
.SUFFIXES: .c .o

srcdir	 =src/
TARGETS	 = 1 1a 1b 2 3 4 5 6 7 8

.PHONY: all
all: $(TARGETS)

# render a png
1: $(srcdir)helper.c $(srcdir)1.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

# scale
1a: $(srcdir)helper_1.c $(srcdir)1a.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

# scale with pause
1b: $(srcdir)helper_1.c $(srcdir)1b.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

# render a png flipped/mirrored
2: $(srcdir)helper.c $(srcdir)2.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

# rotate a png
3: $(srcdir)helper.c $(srcdir)3.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

# rotate a png with center
4: $(srcdir)helper.c $(srcdir)4.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

# make screenshot with s
5: $(srcdir)helper.c $(srcdir)5.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

6: $(srcdir)helper.c $(srcdir)6.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

7: $(srcdir)helper.c $(srcdir)7.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

8: $(srcdir)helper.c $(srcdir)8.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

.PHONY: clean
clean:
	@rm $(TARGETS) out.jpg 2>/dev/null || true

