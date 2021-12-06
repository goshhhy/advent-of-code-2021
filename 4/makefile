include ../common.mk

default: 4a.$(ARCH) 4b.$(ARCH)

.PHONY: check clean

check: 4a.$(ARCH) 4b.$(ARCH) input.test
	@$(CHECK) 4a.$(ARCH) input.test output_4a.test
	@$(CHECK) 4b.$(ARCH) input.test output_4b.test

clean:
	@- rm *.$(ARCH) *.o