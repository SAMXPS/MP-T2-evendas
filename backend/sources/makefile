
INCLUDES=-I../headers -I../headers/classes -I../tests/
CC=g++
CFLAGS=$(INCLUDES) -ljsoncpp $(shell mysql_config --cflags) -ftest-coverage -fprofile-arcs
GTEST_FLAGS=-lgtest -lpthread

ODIR :=../bin/obj	# Diretório de objetos.
LDIR :=../lib		# Diretório de libs.

LIBS=-lm $(shell mysql_config --libs)

# Arquivos de codigo fonte comuns.
COMMON_SRC_FILES := ../sources/JsonModule.cpp ../sources/DatabaseModule.cpp ../sources/UserManager.cpp ../sources/ProductManager.cpp $(wildcard ../sources/classes/*.cpp)

# Arquivos de código fonte exclusivos do deploy do backend.
BACKEND_SRC_FILES := $(COMMON_SRC_FILES) ../sources/Backend.cpp
BACKEND_OBJ_FILES := $(patsubst ./%.cpp,$(ODIR)/%.o,$(BACKEND_SRC_FILES))

# Arquivos de código fonte exclusivos para testes unitários.
TEST_SRC_FILES := $(COMMON_SRC_FILES) $(wildcard ../tests/*.cpp)
TEST_OBJ_FILES := $(patsubst ./%.cpp,$(ODIR)/%.o,$(TEST_SRC_FILES))

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TEST_OBJ_FILES)
	$(CC) -o ../bin/$@ $^ $(CFLAGS) $(LIBS) $(GTEST_FLAGS) -g

backend:  $(BACKEND_OBJ_FILES)
	$(CC) -o ../bin/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean cleanTest

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 