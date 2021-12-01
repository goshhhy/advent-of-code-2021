include ../common.mk

default: 1a.$(ARCH) 1b.$(ARCH)

.PHONY: check clean

check: 1a.$(ARCH) 1b.$(ARCH) input.test
	@$(CHECK) 1a.$(ARCH) input.test output_1a.test
	@$(CHECK) 1b.$(ARCH) input.test output_1b.test

clean:
	@- rm *.$(ARCH) *.o