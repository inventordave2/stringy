/* STRINGY_C */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./../regexp/regexp.h"
#include "./stringy.h"
#include "./str_concat.h"

#ifdef COLOURMODE
#include "./../colour/colour.h"
#endif

/*
Public.
*/

struct Stringy* stringy;
void InitStringy();
void DeInitStringy();
 
/*
Static.
*/
static int stringy_initialised = 0;
static void InitStringyI();
static void DeInitStringyI();

static void DeInitStringyI()	{

	if( stringy!= NULL )
		free( stringy );

	stringy_initialised = 0;
	return;
}

static char desc[] = "Dave's STRINGY library, a 'readme'-first, flexible, target-avoiding masterpiece, written with th 5d Warrior approach of an old-school, old-guard, coding legend, me. Generate, clip, manipulate, format using ANSIVT100 (with Stringy in COLOURMODE, thereby utilising Dave's COLOURLIB. Search strings, buffers, arrays...)\0";

static char* substring( char*, unsigned long long start, unsigned long long end );
//static char* ull2digitstr( unsigned long long );
static char* getstring( char* str );
static char* concat( char*,char* );
static char* zalloc( unsigned long long size );
static unsigned long long strlen_( char* str );
static void flipstr(char * in, char * out);
static char** split( char*, char delim );
static char** split2( char* line, char delim );
static char* trim( char* );
static char* safecat( char*,char* );
static uint64_t find_first_of( char*, char );
static uint64_t find_next_of( char*, char );
static int freestringy( char* ptr );
static void nl();
static FILE* writeToFile ( FILE*, char*, uint8_t );
static char* stub( char* );

static char* concat( char* lhs, char* rhs )	{
	
	uint64_t len = strlen(lhs)+strlen(rhs)+1;
	
	char* lvalue = (char*)malloc( len );
	
	strcpy( lvalue, lhs );
	strcat( lvalue, rhs );
	
	free( lhs );
	lhs = lvalue;
	
	return lhs;
	
}

static FILE* writeToFile( FILE* fp, char* str, uint8_t ft )	{

	FILE* f;
	uint8_t flag = 0;

	if( fp==NULL )
		flag = 1, f = fopen( "file1.txt", "w+" );
	else
		f = fp;
	
	fprintf( f, str );
	
	if( flag==1 )
		fclose(f);
	
	return f;
}		

static void nl()	{
	
	printf( "\n" );
	return;
}

static uint64_t find_first_of( char* str, char delim )	{
	
	unsigned x = 0;
	
	while( str[x] != '\0' )	{
		
		if( str[x]==delim )
			return x;
		
		x++;
	}
	
	return -1;
}

static uint64_t find_next_of( char* str, char delim )	{

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

void InitStringy()	{
	
	InitStringyI();
	return;
}

static char** split( char* line, char delim )	{

	char** cl = (char**)calloc( strlen(line) + 1,1 );
	char** _;

	char* t = (char*) malloc( strlen( line )+1 );
	
	int x, z = 0;
	for( x=0; x<strlen( line ); x++ )	{

		if( line[x] == delim )	{

			t[ z ] = '\0';
			*_++ = stringy->getstring( t );
			z = 0;
			
			continue;
		}

		t[ z++ ] = line[ x ];
	}

	if( z!=0 )
		t[ z ] = '\0';

	return cl;
}


static char** split2( char* line, char delim )	{

	char** cl = (char**)calloc( strlen(line) + 1,1 );
	char** _;

	char* t = (char*) malloc( strlen( line )+1 );
	
	int x, z = 0;
	for( x=0; x<strlen( line ); x++ )	{

		if( line[x] == delim )	{

			t[ z ] = '\0';
			*_++ = stringy->getstring( t );
			z = 0;
			
			continue;
		}

		t[ z++ ] = line[ x ];
	}

	if( z!=0 )
		t[ z ] = '\0';

	return cl;
}


static char* stub( char* str )	{
	
	return str;
}


static void InitStringyI()	{

	if( stringy_initialised==1 )
		return;

	stringy = (struct Stringy*)malloc( sizeof( struct Stringy ) );

	#ifdef COLOURMODE
	stringy->fmt = colour->fmt;
	#else
	stringy->fmt = stub;
	#endif

	stringy->getstring	= getstring;
	stringy->substring	= substring;
	stringy->zalloc		= zalloc;
	//stringy->ull2digitstr= ull2digitstr;
	stringy->strlen		= strlen_;
	stringy->flipstr	= flipstr;
	stringy->trim		= trim;
	stringy->split		= split;
	stringy->split2		= split2;
	stringy->find_first_of = find_first_of;
	stringy->safecat = safecat;
	stringy->free = freestringy;
  	stringy->nl = nl;
	stringy->concat = concat;
	stringy->stub = stub;
	stringy->desc = (const char*) getstring( (char*)desc );

	stringy_initialised = 1;
	return;
}

static int freestringy( char* ptr )	{

	if( ptr == NULL )
		return 0;
	
	free( ptr );
	ptr = NULL;
	return 1;
}

static char* safecat( char* head, char* tail )	{
	
	if(
		head==NULL ||
		strlen(head)==0 ||
		tail==NULL ||
		strlen(tail)==0
	  )
		return NULL;
	

	
	char* _ = (char*)malloc( strlen(head)+strlen(tail)+1 );
	if( _==NULL )
		return NULL;


	strcpy( _,head );
	strcat( _,tail );
	
	return _;
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
	
	return substring( in, x, y );
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

	if( str==NULL )
		return (char*)calloc( 1, sizeof(char*) );
	
	unsigned long long strlen_str = 0;
	strlen_str = strlen( str );
	char* r = (char*) calloc( strlen_str+1,1 );
	char* _ = r;
	
	unsigned long long i = 0;
	for( i; i < strlen_str; i++ )	{
		
		*_++ = *str++;
	}
	
	*_ = (char)0;
	
	return r;
}

static inline int cmp(char* a, char* b) { // returns true (1) if the 2 c-strings match, as it should...

	return (strcmp(a, b) == 0);
}

static void rotate(unsigned int* argc, char* argv[] )	{

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

static void flipstr(char * in, char * out)	{
	
	unsigned int len = strlen(in);
	
	for(signed int i = len - 1; i >= 0; i--)
		*(out++) = *(in+i);
	
	*out = '\0';
}

#include "./str_concat.c"
