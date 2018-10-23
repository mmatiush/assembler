#include "libft.h"
#include "asm.h"

static char *error_text[] =
{
	"Wrong number of parameters\n\tUsage: ./asm <filenme.s>", // 0
	"Wrong file extension\n\tUsage: ./asm <filenme.s>",
	"Failed file opening",
	"Extra [ \" ]", // 3
	"Couldn't allocate memory",
	"Syntax error", // 5
	"Missing .name",
	"Missing .comment", // 7
	"Program name is too long",
	"Program comment is too long",
	"Wrong parameters", // 10
	"Couldn't allocate memory", // 11
	"Lexical error",
	"Operation syntax error", // 13
	"Invalid instruction", // 14
	"Wrond parameter type for the instruction",
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

int		print_err_line_param(const int error_num, const int line, char *name)
{
	ft_printf("Error:\nLine #%d, parameter #<%s> - %s\n", \
			line, name, error_text[error_num]);
	return (-1);
}
