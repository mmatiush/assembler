#include "libft.h"
#include "asm.h"

static char *error_text[] =
{
	"Wrong number of parameters\n\tUsage: ./asm <filenme.s>",
	"Wrong file extension\n\tUsage: ./asm <filenme.s>",
	"Failed file opening",
	"Extra [ \" ]",
	"Couldn't allocate memory for a new node in the add_to_list() function", // 4
	""
};

int		print_error(const int error_num)
{
	ft_printf("Error: %s\n", error_text[error_num]);
	return (-1);
}

int		print_error_line(const int error_num, const int line)
{
	ft_printf("Error:\nLine #%d - %s\n", line, error_text[error_num]);
	return (-1);
}

