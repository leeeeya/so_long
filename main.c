#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return 0;

	check_map(argv[1], &map);
//	printf("%d\n", map.x);
	return 0;
}
