################################################
# Auto-generated as part of running getlibs 
################################################

# List of local libraries 
SEARCH_TARGET_CY8CKIT-145-40XX=./libs/TARGET_CY8CKIT-145-40XX

# List of shared libraries 
SEARCH_capsense=../mtb_shared/capsense/release-v3.0.1
SEARCH_core-lib=../mtb_shared/core-lib/release-v1.4.1
SEARCH_core-make=../mtb_shared/core-make/release-v1.9.1
SEARCH_mtb-hal-cat2=../mtb_shared/mtb-hal-cat2/release-v2.0.0
SEARCH_mtb-pdl-cat2=../mtb_shared/mtb-pdl-cat2/release-v1.6.1
SEARCH_recipe-make-cat2=../mtb_shared/recipe-make-cat2/release-v1.2.2

# Shared libraries added to build 
SEARCH+=$(SEARCH_capsense)
SEARCH+=$(SEARCH_core-lib)
SEARCH+=$(SEARCH_core-make)
SEARCH+=$(SEARCH_mtb-hal-cat2)
SEARCH+=$(SEARCH_mtb-pdl-cat2)
SEARCH+=$(SEARCH_recipe-make-cat2)
-include $(CY_INTERNAL_APP_PATH)/importedbsp.mk
