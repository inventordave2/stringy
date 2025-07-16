/* STRINGY_C */

#include <stdlib.h>
#include <string.h>
#include "./stringy.h"
#include "./../colour/colour.h"

static char* substring( char*, unsigned long long start, unsigned long long end );
//static char* ull2digitstr( unsigned long long );
static char* getstring( char* str );
static char* zalloc( unsigned long long size );
static unsigned long long strlen_( char* str );
static void flipstr(char * in, char * out);

struct stringy_t* stringy;

void InitStringy()	{

	struct stringy_t _stringy;
	
	_stringy.getstring	= getstring;
	_stringy.substring	= substring;
	_stringy.zalloc		= zalloc;
	//_stringy.ull2digitstr= ull2digitstr;
	_stringy.strlen		= strlen_;
	_stringy.flipstr	= flipstr;

	struct stringy_t* temp_stringy_obj = (struct stringy_t*)malloc( sizeof( struct stringy_t ) );
	*temp_stringy_obj = _stringy;
  	stringy = temp_stringy_obj;
	
	return;
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

int cmp(char *a, char *b) { // returns true (1) if the 2 c-strings match, as it should...

	return (strcmp(a, b) == 0);
}

void rotate(unsigned int * argc, char * argv[] )	{

	for(int i = 0; i < (*argc - 1); i++)	{
		
		argv[i] = argv[i+1];
	}

	argv[*argc - 1] = '\0';
	*argc -= 1;
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

void flipstr(char * in, char * out)	{
	
	unsigned int len = strlen(in);
	
	for(signed int i = len - 1; i >= 0; i--)
		*(out++) = *(in+i);
	
	*out = '\0';
}
