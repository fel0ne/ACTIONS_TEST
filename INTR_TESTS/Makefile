
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
	@for target in $(TARGETS); do \
		echo "------------------------------------"; \
		echo "Running $$target..."; \
		LD_LIBRARY_PATH=$(BLAS_PATH) ./$$target; \
	done


clean:
	@for dir in $(SUBDIRS); do \
		rm -f $$dir/*[!.cpp]; \
	done
	rm -f $(TARGETS)