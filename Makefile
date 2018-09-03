.PHONY: clean mock test

test: mock
	make -C test

mock:
	make -C mock

clean:
	make -C mock clean
	make -C test clean