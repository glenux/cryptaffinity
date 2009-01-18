#AM_YFLAGS = -d  -v

SUBDIRS = .

bin_PROGRAMS = break_afinity


break_afinity_SOURCES = 	main.cpp ba_cmd.cpp ba_config.cpp file_loader.cpp ba_vigenere.cpp ba_afine.cpp

#	ftp_client.cpp \
#	ftp_client_cmd.cpp \
#	ftp_client_data.cpp \
#	miniftp.cpp \
#	server_msg.cpp

break_afinity_SOURCES += ba_cmd.hh breakafinity.hh breakafinity_global.hh breakafinity_iface.hh breakafinity_proto.hh file_loader.hh

#	ftp_config.hh \
#	miniftp_global.hh \
#	miniftp.hh \
#	miniftp_iface.hh \
#	miniftp_proto.hh \
#	server_msg.hh

INCLUDES= 	-I../lib/ -I./ @GLIB2_CFLAGS@ @TARGET_READLINE_INC@

#BUILT_SOURCES = source_parser.h source_lexer.cc

		
# LEXLIB@ 
#			libyalag.la
# miniftpc_INCLUDE = a 

break_afinity_LDADD = -lcryptafinity @GLIB2_LIBS@ 
break_afinity_LDFLAGS = 	@LDFLAGS@ -L../lib -L../lib/.libs 

