/* STRINGY_H */

#ifndef DAVELIB_STRINGY_H
#define DAVELIB_STRINGY_H

#ifdef _cplusplus_
extern "C"	{
#endif

#include <stdint.h>
#include <stdio.h>

typedef struct Stringy	{

	uint64_t 			(*strlen)			( char* ); 
	char* 				(*getstring) 		( char* );
	char* 				(*substring)		( char*, unsigned long long, unsigned long long );
	char*				(*concat)			( char*,char* );
	char* 				(*zalloc)			( unsigned long long );
	char* 				(*ull2digitstr)		( unsigned long long );
	void				(*flipstr)			(char * in, char * out);
	char*				(*safecat)			( char*, char* );
	char* 				(*trim)				( char* );
	char**				(*split)			( char*, char );
	uint64_t			(*find_first_of)	( char*, char );
	int					(*free)				( char* );
	char*				(*fmt)				( char* );
	char**				(*split2)			( char*, char );

	char*				(*stub)				( char* );
	void 				(*nl)				();

	FILE*				(*writeToFile)		( FILE*, char*, uint8_t );

	const char* desc;


} Stringy;

extern struct Stringy* stringy;
extern void InitStringy();
extern void DeInitStringy();

#ifdef _cplusplus_
}
#endif

#endif
