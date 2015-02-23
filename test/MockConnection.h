/*
 * FakeConnection.h
 *
 *  Created on: Feb 22, 2015
 *      Author: mdam
 */

#ifndef TEST_MOCKCONNECTION_H_
#define TEST_MOCKCONNECTION_H_
#include <stdio.h>
#include <string>
#include <ev3comm/Connection.h>
#include <gmock/gmock.h>

using namespace ev3comm;
using namespace ::testing;

class FakeConnection : public Connection {
public:
	virtual void send(unsigned char *buffer,unsigned int n) {

	}

	virtual void receive(unsigned char *buffer, unsigned int length) {

	}

	virtual void flush() {

	}

	Connection_type get_type() {
		return Connection_type::SIM;
	}
};

class MockConnection : public FakeConnection {
public:
	MockConnection() { }
	~MockConnection() { }

	MOCK_METHOD2(send, void(unsigned char *buffer, unsigned int n));
	MOCK_METHOD2(receive, void(unsigned char *buffer, unsigned int length));
	MOCK_METHOD0(flush, void());
};

#endif /* TEST_MOCKCONNECTION_H_ */
