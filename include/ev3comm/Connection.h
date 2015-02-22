#ifndef EV3COMM_CONNECTIONH
#define EV3COMM_CONNECTIONH
#include <string>

namespace ev3comm {
	/**
	  * Connection type enumeration
	  * @see Connection#get_type
	*/
	enum Connection_type {
		/**
		* USB connection
		*/
		USB = 0x00,
	};

	/**
	  * Abstract class for connections
	*/
	class Connection {
	  public:
		virtual ~Connection(){};

		/**
		* Send a byte string
		* @param *buffer [bytes to be sent]
		* @param n [size of byte buffer]
		*/
		virtual void send(unsigned char *buffer,unsigned int n) = 0;

		/**
		* Receive a byte string
		* @param *buffer [a pointer to a buffer that can hold the received bytes]
		* @param length [the number of bytes to receive]
		*/
		virtual void receive(unsigned char *buffer, unsigned int length)=0;

		/**
		* Flush the input and output buffer
		*/
		virtual void flush() = 0;

		/**
		* Get the connection type
		* @return the connection type
		*/
		virtual ev3comm::Connection_type get_type() = 0;
	};
}
#endif
