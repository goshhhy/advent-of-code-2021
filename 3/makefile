include ../common.mk

default: 3a.$(ARCH) 3b.$(ARCH)

.PHONY: check clean

check: input.test 3a.$(ARCH) 3b.$(ARCH) 
	@$(CHECK) 3a.$(ARCH) input.test output_3a.test
	@$(CHECK) 3b.$(ARCH) input.test output_3b.test

clean:
	@- rm *.$(ARCH) *.o