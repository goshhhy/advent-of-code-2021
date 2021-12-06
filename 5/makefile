include ../common.mk

default: 5a.$(ARCH) 5b.$(ARCH)

.PHONY: check clean

check: 5a.$(ARCH) 5b.$(ARCH) input.test
	@$(CHECK) 5a.$(ARCH) input.test output_5a.test
	@$(CHECK) 5b.$(ARCH) input.test output_5b.test

clean:
	@- rm *.$(ARCH) *.o