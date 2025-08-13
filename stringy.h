/* STRINGY_H */

#ifndef DAVELIB_STRINGY_H
#define DAVELIB_STRINGY_H

#ifdef _cplusplus_
extern "C"	{
#endif

#include <stdint.h>
#include <stdio.h>

typedef struct StringyI	{
	
	uint64_t 	(*strlen)			( char* ); 
	char* 				(*getstring) 		( char* );
	char* 				(*substring)		( char*, unsigned long long, unsigned long long );
	char*				(*concat)			( char*,char* );
	char* 				(*zalloc)			( unsigned long long );
	char* 				(*ull2digitstr)		( unsigned long long );
	void				(*flipstr)			(char * in, char * out);
	char*				(*safecat)			( char*, char* );
	char* 				(*trim)				( char* );
	char**				(*split)			( char*, char, unsigned max );
	uint64_t			(*find_first_of)	( char*, char );
	void				(*free)				( char* );
	char*				(*fmt)				( char* );
	
	void 				(*nl)				();
	
	FILE*				(*writeToFile)		( FILE*, char*, uint8_t );

} StringyI;

extern struct StringyI* stringy;
extern void InitStringy();

#ifdef _cplusplus_
}
#endif

#endif
