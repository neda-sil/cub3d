#include "libft.h"

double	ft_abs_double(double src)
{
	if (src < 0)
		src = src * -1;
	return (src);
}