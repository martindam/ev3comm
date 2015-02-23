#ifndef EV3COMM_MOTORH
#define EV3COMM_MOTORH

#include <stdint.h>

namespace ev3comm {

	/**
	* Motor port enumeration
	* @see Motor
	*/
	enum MotorPort {
	  OUT_A = 0x01,
	  OUT_B = 0x02,
	  OUT_C = 0x04,
	  OUT_D = 0x08
	};

	/**
	 * The state of the motor since last reset
	 * @see Motor
	 */
	struct MotorState {
		int8_t speed;
		int32_t steps;
	};

	class Motor {
		Motor(MotorPort motor, Connection *conn);
		~Motor();

		/**
		 * Reset position (POS=0)
		 */
		void reset();

		/**
		 * Stop outputs (brake or coast)
		 * @param brake True = Brake, False = Coast
		 */
		void stop(bool brake);

		/**
		 * Set power (suspend regulation and positioning)
		 * @param power Power of the motor (-100 to 100%)
		 */
		void setPower(int8_t power);

		/**
		 * Set speed (relative to polarity - enables regulation if tacho)
		 * @param speed Speed of the motor (-100 to 100%)
		 */
		void setSpeed(int8_t speed);

		/**
		 * Starts outputs from present values
		 */
		void start();

		/**
		 * Set polarity
		 * @param pol The polarity. -1, +1 or 0=toggle
		 */
		void setPolarity(int8_t pol);

		/**
		 * Read actual speed and steps from last reset
		 */
		MotorState getState();

		/**
		 * Check if output is busy
		 * @return Output busy flag (false = ready, true = Busy)
		 */
		bool isBusy();

		/**
		 * Wait for action completed or overruled
		 */
		void wait();

		/**
		 * Set position (absolute from last reset)
		 * @param position The position the motor should go to
		 */
		void setPosition(int position);

		/**
		 * Combined function to run a set steps with the given power
		 * Set all parameters, start if not started and power != 0
		 * @param power The power the engine should use (-100 to 100%)
		 * @param stepAcc Steps used to ramp up (0-MAX)
		 * @param stepConst Steps used for constant speed (0-MAX)
		 * @param stepDeAcc Steps used to ramp down (0-MAX)
		 * @param brake Brake (true) or coast (false) at end
		 */
		void stepPower(int8_t power, int stepAcc, int stepConst, int stepDeAcc, bool brake);

		/**
		 * Combined function to run for time with the given power
		 * Set all parameters, start if not started and power != 0
		 * @param power The power the engine should use (-100 to 100%)
		 * @param timeAcc Time [mS] to ramp up
		 * @param timeConst Time [mS] for constant speed
		 * @param timeDeAcc Time [mS] to ramp down
		 * @param brake Brake (true) or coast (false) at end
		 */
		void timePower(int8_t power, int timeAcc, int timeConst, int timeDeAcc, bool brake);

		/**
		 * Combined function to run a set steps with the given speed
		 * Set all parameters, start if not started and power != 0
		 * @param speed The speed the engine should use (-100 to 100%)
		 * @param stepAcc Steps used to ramp up (0-MAX)
		 * @param stepConst Steps used for constant speed (0-MAX)
		 * @param stepDeAcc Steps used to ramp down (0-MAX)
		 * @param brake Brake (true) or coast (false) at end
		 */
		void stepSpeed(int8_t speed, int stepAcc, int stepConst, int stepDeAcc, bool brake);

		/**
		 * Combined function to run for time with the given speed
		 * Set all parameters, start if not started and power != 0
		 * @param speed The speed the engine should use (-100 to 100%)
		 * @param timeAcc Time [mS] to ramp up
		 * @param timeConst Time [mS] for constant speed
		 * @param timeDeAcc Time [mS] to ramp down
		 * @param brake Brake (true) or coast (false) at end
		 */
		void timeSpeed(int8_t speed, int timeAcc, int timeConst, int timeDeAcc, bool brake);

	};
}
#endif
