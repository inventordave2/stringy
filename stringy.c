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
static char** split( char*, char delim, unsigned );
static char* trim( char* );
long long find_first_of( char*, char );
long long find_next_of( char*, char );

long long find_first_of( char* str, char delim )	{
	
	unsigned x = 0;
	
	while( str[x] != '\0' )	{
		
		if( str[x]==delim )
			return x;
		
		x++;
	}
	
	return -1;
}

long long find_next_of( char* str, char delim )	{

	static unsigned y = 0;
	unsigned x = y;
	 
	 
	while( str[x] != '\0' )	{
		
		if( str[x]==delim )	{
			
			y = x+1;
			return y-1;
		}
		
		
		x++;
	}
	
	y = 0;
	
	return -1;
}


struct stringy_t* stringy;
static uint8_t stringy_activated = 0;


void InitStringy()	{

	if( stringy_activated==1 )
		return;
	
	struct stringy_t* _stringy = (struct stringy_t*)malloc( sizeof( struct stringy_t ) );
	_stringy->getstring	= getstring;
	_stringy->substring	= substring;
	_stringy->zalloc		= zalloc;
	//_stringy->ull2digitstr= ull2digitstr;
	_stringy->strlen		= strlen_;
	_stringy->flipstr	= flipstr;
	_stringy->trim		= trim;
	_stringy->split		= split;
	_stringy->find_first_of = find_first_of;

  	stringy = _stringy;
	
	stringy_activated = 1;
	return;
}

static char* trim( char* in )	{

	unsigned x = 0;
	
	loop:
	
	if( in[x]=='\t' ||
		in[x]==' '  ||
		in[x]=='\n' )	{

		x++;
		goto loop;
	}
	
	unsigned y = strlen( in );
	y -= 1;
	
	loop2:
	
	if( in[y]=='\t' ||
		in[y]==' '  ||
		in[y]=='\n' )	{

		y--;
		goto loop2;
	}
	
	return stringy->substring( in, x, y );
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
