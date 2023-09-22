#include "stdafx.h"

int strtoi(char arr[]) {
	char* p = arr;
	bool isd = true;
	if (*p == '-')
		p++;
	while (*p)
		if (!isdigit(*p++))
		{
			isd = false;
			break;
		}
	if (isd)
		return atoi(arr);
	else
		return -0;
}
