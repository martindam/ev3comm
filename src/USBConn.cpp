#include <ev3comm/USBConn.h>
#include <stdio.h>

using namespace ev3comm;

USBConn::USBConn() {

}

USBConn::~USBConn() {

}

void USBConn::send(unsigned char *buffer,unsigned int n) {

}
void USBConn::receive(unsigned char *buffer, unsigned int length) {

}
void USBConn::flush() {

}

Connection_type USBConn::get_type() {
	return Connection_type::USB;
}
