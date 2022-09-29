#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
main(int argc, char *argv[])
{
	_invalid_parameter_handler handler;
	int new_max;
	handler = _set_invalid_parameter_handler(null_handler);

	/* If the program was given exactly one argument and the argument
	 * matches the string "hang", try to set the fd limit to 10000.
	 * Otherwise, set it to 2048. 10000 triggers a Windows bug and causes
	 * the program to hang, 2048 doesn't.
	 */
	new_max = (argc == 2 && strcmp(argv[1], "hang") == 0) ? 10000 : 2048;
	_setmaxstdio(new_max);
	return 0;
}
