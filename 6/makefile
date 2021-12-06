include ../common.mk

default: 6a.$(ARCH) 6b.$(ARCH)

.PHONY: check clean

check: 6a.$(ARCH) 6b.$(ARCH) input.test
	@$(CHECK) 6a.$(ARCH) input.test output_6a.test
	@$(CHECK) 6b.$(ARCH) input.test output_6b.test

clean:
	@- rm *.$(ARCH) *.o