include ../common.mak

CFLAGS += -Os -Wall $(EXTRACFLAGS) -fPIC
CFLAGS += -I. -I$(TOP)/shared -I$(TOP)/nvram$(BCMEX) -I$(SRCBASE)/include -I$(TOP)/httpd
CFLAGS += -I$(TOP)/util-linux/include
CFLAGS += -idirafter$(LINUXDIR)/arch/arm/include -idirafter$(LINUXDIR)/include

LDFLAGS += $(EXTRALDFLAGS2)

ifeq ($(RTCONFIG_QTN),y)
LDFLAGS += -L$(TOP)/libqcsapi_client -lqcsapi_client
PBDIR = prebuilt_qtn
else
PBDIR = prebuilt
endif

# ASUSWRT
OBJS += iqos.o wrs.o stat.o dpi.o web_history.o wrs_app.o data_collect.o tools.o

# TrendMicro
OBJS += usr_ioctl.o conf_app.o

ifeq ($(RTCONFIG_BCMARM),y)
vpath %.c $(SRCBASE)/shared
endif

ifeq ($(wildcard $(SRCBASE)/router/bwdpi/*.c),)
all:
	-cp -f $(PBDIR)/libbwdpi.so libbwdpi.so
	-cp -f $(PBDIR)/wrs wrs
	-cp -f $(PBDIR)/bwdpi.h bwdpi.h
else
all: libbwdpi.so wrs
endif

libbwdpi.so: $(OBJS)
	@echo " [bwdpi] LD $@"
	@$(LD) $(LDFLAGS) -shared -o $@ $^

wrs: wrs_main.o libbwdpi.so
	$(CC) $(CFLAGS) $(LDFLAGS) -L. -lbwdpi -lgcc_s -o $@ $^

install: all
	@echo "[bwdpi] Installing..."
	@install -d $(INSTALLDIR)/usr/lib
	@install -m 755 libbwdpi.so $(INSTALLDIR)/usr/lib
	@$(STRIP) $(INSTALLDIR)/usr/lib/libbwdpi.so
	@install -d $(INSTALLDIR)/usr/sbin
	@install -m 755 wrs $(INSTALLDIR)/usr/sbin
	@$(STRIP) $(INSTALLDIR)/usr/sbin/wrs

%.o: %.c
	@echo " [bwdpi] CC $@"
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.so *.o wrs
