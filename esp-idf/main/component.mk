#
# Main Makefile. This is basically the same as a component makefile.
#
COMPONENT_DEPENDS := mrubyc
COMPONENT_EXTRA_CLEAN = SRCFILES

MRBC = mrbc
SRCDIR = $(PROJECT_PATH)/mrblib
SRCFILES = $(wildcard $(SRCDIR)/*.rb) $(wildcard $(SRCDIR)/**/*.rb)
OBJS = $(patsubst %.rb,%.h,$(SRCFILES))

main.o: $(OBJS)

$(SRCDIR)/%.h: $(SRCDIR)/%.rb
	@if [ ! -d $(dir $(subst $(SRCDIR),$(COMPONENT_BUILD_DIR),$@)) ]; \
		then echo "mkdir -p $(dir $(subst $(SRCDIR),$(COMPONENT_BUILD_DIR),$@))"; mkdir -p $(dir $(subst $(SRCDIR),$(COMPONENT_BUILD_DIR),$@)); \
		fi
	@echo $(MRBC) -E -B $(basename $(notdir $@)) -o $(subst $(SRCDIR),$(COMPONENT_BUILD_DIR),$@) $^
	$(MRBC) -E -B $(basename $(notdir $@)) -o $(subst $(SRCDIR),$(COMPONENT_BUILD_DIR),$@) $^
