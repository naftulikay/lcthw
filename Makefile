#!/usr/bin/make -f

.PHONY: clean

all:
	find exercises -mindepth 1 -maxdepth 1 -type d | while read dir ; do \
		$(MAKE) -C $$dir ; \
	done

clean:
	find exercises -mindepth 1 -maxdepth 1 -type d | while read dir ; do \
		$(MAKE) -C $$dir clean ; \
	done
