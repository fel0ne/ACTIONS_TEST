# Укажи здесь полный путь к папке, где лежит собранный OpenBLAS
# Например: /home/pavel/OpenBLAS
BLAS_PATH = $(CURDIR)/../OpenBLAS-0.3.31

CXX = g++
# -O3 для максимальной скорости, -fopenmp для параллельности (+20 баллов)
CXXFLAGS = -O3 -I$(BLAS_PATH) -fopenmp
LDFLAGS = -L$(BLAS_PATH) -lopenblas -lpthread -lgfortran

TARGET = trmm_test
SOURCE = trmm_lab.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

# Запуск с прописыванием пути к библиотеке, чтобы Linux её нашел
run: all
	@echo "------------------------------------"
	@echo "Running $(TARGET)..."
	LD_LIBRARY_PATH=$(BLAS_PATH):$(LD_LIBRARY_PATH) ./$(TARGET)

clean:
	rm -f $(TARGET)