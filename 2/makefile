include ../common.mk

default: 2a.$(ARCH) 2b.$(ARCH)

.PHONY: check clean

check: 2a.$(ARCH) 2b.$(ARCH) input.test
	@$(CHECK) 2a.$(ARCH) input.test output_2a.test
	@$(CHECK) 2b.$(ARCH) input.test output_2b.test

clean:
	@- rm *.$(ARCH) *.o