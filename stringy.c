/* STRINGY_C */

#include <stdlib.h>

#include "./../colour/colour.h"
#include "./stringy.h"

static char* getstring( char* );
static char* substring( char*, unsigned long long start, unsigned long long end );
static char* zalloc( unsigned long long );
static unsigned long long strlen_( char* str );
#define strlen strlen_
static char* ull2digitstr( unsigned long long );

void InitStringy()	{

	stringy.getstring	= getstring;
	stringy.substring	= substring;
	stringy.zalloc		= zalloc;
	stringy.strlen		= strlen_;
	stringy.ull2digitstr= ull2digitstr;
	stringy.strlen		= strlen_;

}


static unsigned long long strlen_( char* str )	{

	unsigned long long i = 0;
	
	while( *(str++) != 0 )
		i++;
	
	return i;
}

static char* zalloc( unsigned long long size )	{
	
	char* r = (char*) malloc( size+1 );
	unsigned long long i = 0;
	
	while( size-- )
		r[i++] = '0';
	
	r[i] = 0;
	
	return r;
}

static char* getstring( char* str )	{

	unsigned long long strlen_str = strlen( str );
	char* r = (char*) malloc( strlen_str+1 );
	char* _ = r;
	
	unsigned long long i = 0;
	for( i; i < strlen_str; i++ )
		*_++ = *str++;

	*_ = (char)0;
	
	return r;
}

static char* substring( char* str, unsigned long long start, unsigned long long end )	{
	
	unsigned long long count = 0;
	
	if( end<start )
		count = end, end = start, start = count, count = 0;
	
	if( ((str + start) - str) > strlen( str ) )
		return (char*)NULL;
	
	
	unsigned long long dist = end - start;
	
	char* r = (char*) malloc( 1 + dist );
	char* _ = r;
	
	str += start;
	
	while( 1 )	{

		if( count==dist )
			break;
		
		*_ = *str;
		
		if( *_ == 0 )
			break;
		
		count++;
		_++;
		str++;

	}
	
	*_ = 0;
	
	return r;
}

