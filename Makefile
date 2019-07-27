CFLAGS   = -Wall -Wextra -mtune=native -no-pie `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2_image -lm

.SUFFIXES:
.SUFFIXES: .c .o

srcdir	 =src/
TARGETS	 = 1 1a 1b 1c 1d 2 3 4

.PHONY: all
all: $(TARGETS)

#render png
1: $(srcdir)helper.c $(srcdir)1.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

#render png flipped/mirrored
1a: $(srcdir)helper.c $(srcdir)1a.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

#render and rotate png
1b: $(srcdir)helper.c $(srcdir)1b.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

#render and rotate png with center
1c: $(srcdir)helper.c $(srcdir)1c.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

#render png and make screenshot with s
1d: $(srcdir)helper.c $(srcdir)1d.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

2: $(srcdir)helper.c $(srcdir)2.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

3: $(srcdir)helper.c $(srcdir)3.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

4: $(srcdir)helper.c $(srcdir)4.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

.PHONY: clean
clean:
	@rm $(TARGETS) out.jpg 2>/dev/null || true

