/*
 * motor-test.cpp
 *
 *  Created on: Feb 22, 2015
 *      Author: mdam
 */

#include <stdio.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ev3comm/EV3comm.h>
#include "MockConnection.h"

using namespace ev3comm;
using namespace ::testing;

class MotorTest : public Test {
protected:
	MotorTest() : conn() {

	}

	virtual void SetUp() {

	}

	MockConnection conn;
};


TEST_F(MotorTest, reset) {
	EXPECT_CALL(conn, send(_,10)).Times(1);

	unsigned char buf[10];
	conn.send(buf, 10);
}
