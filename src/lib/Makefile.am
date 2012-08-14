SUBDIRS = .

lib_LTLIBRARIES = libcryptaffinity.la

#bin_PROGRAMS = libulm.o

libcryptaffinity_la_SOURCES = 	alphabet.cpp \
	key.cpp \
	text.cpp \
	codec.cpp \
	letter.cpp \
	codec_affine.cpp \
	codec_vigenere.cpp \
	key_affine.cpp \
	key_vigenere.cpp \
	word_list.cpp \
	math_tools.cpp \
	freq_analyser.cpp

#libcryptaffinity_la_SOURCES += cryptaffinity_errors.hh \
#	cryptaffinity_global.hh \
#	cryptaffinity.hh \
#	cryptaffinity_iface.hh \
#	cryptaffinity_proto.hh \
#	XSock.hh

libcryptaffinity_la_CFLAGS = -DTRACE -static
libcryptaffinity_la_LDFLAGS = -version-info 3:12:1

#INCLUDES=  	SQLITE3_CFLAGS@ \
#			LIBXMLPP_CFLAGS@ \
#			-I./

#libcryptaffinity_a_LDFLAGS= @LDFLAGS@ 

#SQLITE3_LIBS@ LIBPCRE_LIBS@


