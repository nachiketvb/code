#include <stdio.h>

int main()
{
	printf ("17 %% -15 = %d\n", 17 % -15);
	printf ("-17 %% 15 = %d\n", -17 % 15);
	/* Definition of % operator according to C standard is
	 * a % b = a - (a / b) * b
	 * Here a / b truncates towards zero even on the negative side.
	 * (This behavior was undefined before C99)
	 * 17 % -15 = 17 - (17 / -15) * (-15)
	 *          = 17 - (-1) * (-15)
	 *          = 2
	 * -17 % 15 = -17 - (-17 / 15) * 15
	 *          = -17 - (-1) * 15
	 *          = -2
	 */
	return 0;
}
