CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
ARFLAGS = rvs

OBJS =		src/Connection.o src/Error.o src/Lightsensor.o src/Motor.o src/Sensor.o src/USB.o src/EV3bytecode.o

LIBS =

TARGET =	ev3comm-lib

$(TARGET):	$(OBJS)
	$(AR) $(ARFLAGS) $(TARGET).a $(OBJS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
