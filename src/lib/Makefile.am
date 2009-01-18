SUBDIRS = .

lib_LTLIBRARIES = libcryptafinity.la

#bin_PROGRAMS = libulm.o

libcryptafinity_la_SOURCES = 	alphabet.cpp \
	key.cpp \
	text.cpp \
	codec.cpp \
	letter.cpp \
	codec_afine.cpp \
	codec_vigenere.cpp \
	key_afine.cpp \
	key_vigenere.cpp \
	word_list.cpp \
	math_tools.cpp \
	freq_analyser.cpp

#libcryptafinity_la_SOURCES += cryptafinity_errors.hh \
#	cryptafinity_global.hh \
#	cryptafinity.hh \
#	cryptafinity_iface.hh \
#	cryptafinity_proto.hh \
#	XSock.hh

libcryptafinity_la_CFLAGS = -DTRACE -static
libcryptafinity_la_LDFLAGS = -version-info 3:12:1

#INCLUDES=  	SQLITE3_CFLAGS@ \
#			LIBXMLPP_CFLAGS@ \
#			-I./

#libcryptafinity_a_LDFLAGS= @LDFLAGS@ 

#SQLITE3_LIBS@ LIBPCRE_LIBS@


