#include "static-functions.h"
int positive(int x)
{
	if(x > 0)
		return x ;
	
	return -x ;
}

int negative(int x)
{
	if(x > 0)
		return -x ;
	
	return x ;
}

int setDir(int magnitude ,int direction)
{
	if(direction > 0)
		return positive(magnitude) ;
	
	return negative(magnitude) ;
}