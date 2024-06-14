.PHONY:clean
CXX = g++
CXXFLAGS = -Wall #-DMAP
#LDFLAGS

# Liste des fichiers source
SRCS = $(wildcard *.cpp)

# Liste des fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Nom de l'exécutable final
EXEC = AirWatcher

# Règle par défaut pour construire l'exécutable
all: $(EXEC)

# Règle pour construire l'exécutable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	echo "Executable construit"

# Règle générique pour générer les fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)
	echo "objets et executable supprimés"
