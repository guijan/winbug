#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* null_handler: Windows invalid parameter handler that does nothing. */
static void
null_handler(wchar_t const* const unused0, wchar_t const* const unused1,
    wchar_t const* const unused2, unsigned int const unused3, uintptr_t unused4)
{
	(void)unused0;
	(void)unused1;
	(void)unused2;
	(void)unused3;
	(void)unused4;
}

int
main(void)
{
	_set_invalid_parameter_handler(null_handler);

	/*
	 * Setting the stdio limit over Windows' maximum causes the the program
	 * to hang. As of Windows 10 and Windows Server 2022, this limit is
	 * 8192.
	 */
	_setmaxstdio(10000);
	return 0;
}
