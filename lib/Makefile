########       AVR Project Makefile       ########
#####                                        #####
#####      Makefile produit et ecrit par     #####
#####   Simon Barrette & Jerome Collin pour  #####
#####           INF1900 - 2016               #####
#####                                        #####
#####         Inspire de Pat Deegan -        #####
#####  Psychogenic Inc (www.psychogenic.com) #####
##################################################

# Ce Makefile vous permet de compiler des projets
# pour les microcontroleurs Atmel AVR sur 
# Linux ou Unix, en utilisant l'outil AVR-GCC. 
# Ce Makefile supporte C & C++


#####      Details specifique a la cible       #####
#####  Vous devez les adapter a votre projet   #####

# Nom du microcontroleur cible
# (exemple: 'at90s8515')
MCU=atmega324pa

# Nom de votre projet
# (utilisez un seul mot, exemple: 'monprojet')
PROJECTNAME=librobot

# Fichiers sources
# Utilisez le suffixe .cpp pour les fichiers C++
# Listez tous les fichiers a compiler, separes par
# un espace. exemple: 'tp1.c tp2.cpp':
PRJSRC=$(shell find . -name "*.cpp")

# Inclusions additionnels (ex: -I/path/to/mydir)
INC=$(shell find . -type d -exec echo -I{} \;)

# Libraires a lier (ex: -lmylib)
LIBS=

# Niveau d'optimization
# Utilisez s (size opt), 1, 2, 3 ou 0 (off)
OPTLEVEL=s




####################################################
#####         Configuration terminee           #####
#####                                          #####
#####  Le reste de cette section contient les  #####
##### details d'implementation vous permettant #####
##### de mieux comprendre le fonctionnement de ##### 
#####   ce Makefile en vue de sa modification  #####
####################################################



####### variables #######

#compilateur utilise
CC=avr-gcc
AR=avr-ar
#pour copier le contenu d'un fichier objet vers un autre
OBJCOPY=avr-objcopy
#pour supprimer les fichiers lorsque l'on appel make clean
REMOVE=rm -f



####### Options de compilation #######

# Définir la fréquence du CPU comme une variable
F_CPU = 8000000UL

# Flags pour le compilateur en C
CFLAGS=-I. -I/usr/include/simavr  -MMD $(INC) -g -mmcu=$(MCU) -O$(OPTLEVEL) \
	-std=c++14 -fshort-enums             \
	-funsigned-bitfields -funsigned-char    \
	-Wall -DF_CPU=$(F_CPU)
# Flags pour le compilateur en AR
ARFLAGS=-crs                                        

# Flags pour le compilateur en C++
CXXFLAGS=-fno-exceptions     

####### Cible (Target) #######

#Nom des cibles par defaut
LIBTRG=$(PROJECTNAME).a



####### Definition de tout les fichiers objets #######

# Cette fonction permet de differencier les fichiers .c
# des fichiers .cpp
# Fichier C
CFILES=$(filter %.c, $(PRJSRC))
# Fichier C++
CPPFILES=$(filter %.cpp, $(PRJSRC))

# Liste de tout les fichiers objet que nous devons creer
OBJDEPS=$(CFILES:.c=.o) \
	$(CPPFILES:.cpp=.o)
	
# Pour plus d'information sur cette section, consulter :
# http://bit.ly/257R53E	
# Les fonctions $(filter pattern…,text) &
# $(patsubst pattern,replacement,text) sont pertinentes
	


####### Creation des commandes du Makefile ####### 

# Creation des cibles Phony (Phony Target)
# En plus de la commande make qui permet de compiler
# votre projet, vous pouvez utilisez les commandes
# make all, make install et make clean
.PHONY: all clean build

# Make all permet simplement de compiler le projet
#
all: $(LIBTRG)

$(LIBTRG): $(OBJDEPS)
	$(AR) $(ARFLAGS) $(LIBTRG) $(OBJDEPS)


# Production des fichiers object
# De C a objet
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# De C++ a objet
%.o: %.cpp
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

# Verification des dependances (header dependencies)
-include *.d

# Pour plus d'information sur cette section, consulter:
# http://bit.ly/2580FU8


# Make install permet de compiler le projet puis
# d'ecrire le programme en memoire flash dans votre
# microcontroleur. Celui-ci doit etre branche par cable USB
#install: $(HEXROMTRG)				
#	$(AVRDUDE) -c $(AVRDUDE_PROGRAMMERID)   \
#	-p $(MCU) -P -e -U flash:w:$(HEXROMTRG)

# Make clean permet d'effacer tout les fichiers generes
# lors de la compilation
#$(REMOVE) $(TRG) $(TRG).map $(OBJDEPS) $(HEXTRG) *.d
clean:
# Permet de supprimer plus facilement les fichiers en .d, .o et .a
	find . \( -name '*.d' -o -name '*.o' -o -name '*.a' \) -type f -delete

# Pour plus d'information sur les phony target, consulter:
# http://bit.ly/1WBQe61

# De plus, pour mieux comprendre les makefiles et 
# leur fonctionnement, consulter la documentation de GNU Make:
# http://bit.ly/23Vpk8s

# Finalement, ce tutoriel en ligne constitut une bonne 
# introduction au Makefile:
# http://bit.ly/1XvxsN3

#####                    EOF                   #####

# Permet de compiler de façon clean.
build: clean all