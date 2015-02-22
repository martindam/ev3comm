/*
 * USBcomm-test.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: Martin Dam
 */

#include <stdio.h>
#include <ev3comm/EV3comm.h>

using namespace ev3comm;

int main(int argc, char* argv[]) {
	Connection *conn = new USBConn();

	unsigned char buf[10];
	conn->send(buf, 10);
	return 0;
}
