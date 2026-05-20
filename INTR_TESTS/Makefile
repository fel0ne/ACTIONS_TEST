BLAS_PATH = $(CURDIR)/../OpenBLAS-0.3.31
#BLAS_PATH = $(CURDIR)/OpenBLAS-0.3.31_crushed
CXX = g++
CXXFLAGS = -I$(BLAS_PATH)
LDFLAGS = -L$(BLAS_PATH) -lopenblas

SUBDIRS = gemv ger hemv symv trmv trsv ger geru gerc syr her syr2 her2

SOURCES = $(wildcard $(addsuffix /*.cpp, $(SUBDIRS)))

TARGETS = $(SOURCES:.cpp=)

all: $(TARGETS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

run: all
	@FAILED=0; \
	for target in $(TARGETS); do \
		echo "------------------------------------"; \
		echo "Running $$target..."; \
		if ! LD_LIBRARY_PATH=$(BLAS_PATH) ./$$target; then \
			echo " $$target FAILED!"; \
			FAILED=1; \
		else \
			echo " $$target PASSED."; \
		fi; \
	done; \
	if [ $$FAILED -ne 0 ]; then \
		echo "===================================="; \
		echo "Some tests failed!"; \
		exit 1; \
	fi

clean:
	@for dir in $(SUBDIRS); do \
		rm -f $$dir/*[!.cpp]; \
	done
	rm -f $(TARGETS)