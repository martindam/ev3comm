#ifndef EV3COMM_USBH
#define EV3COMM_USBH
#include "Connection.h"

namespace ev3comm {

	class USBConn : public Connection {
		public:
			USBConn();
			~USBConn();

			void send(unsigned char *buffer,unsigned int n);
			void receive(unsigned char *buffer, unsigned int length);
			void flush();
			Connection_type get_type();
	};
}
#endif
