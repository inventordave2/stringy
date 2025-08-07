/* STRINGY_H */

#ifndef DAVELIB_STRINGY_H
#define DAVELIB_STRINGY_H

#include <stdio.h>

typedef struct stringy_t	{
	
	unsigned long long 	(*strlen)			( char* ); 
	char* 				(*getstring) 		( char* );
	char* 				(*substring)		( char*, unsigned long long, unsigned long long );
	char*				(*concat)			( char*,char* );
	char* 				(*zalloc)			( unsigned long long );
	char* 				(*ull2digitstr)		( unsigned long long );
	void				(*flipstr)			(char * in, char * out);
	char*				(*safecat)			( char*, char* );
	char* 				(*trim)				( char* );
	char**				(*split)			( char*, char, unsigned max );
	long long			(*find_first_of)	( char*, char );
	void				(*free)				( char* );
	
	void 				(*nl)				();
	
	FILE*				(*writeToFile)		( FILE*, char*, uint8_t );

} stringy_t;

extern struct stringy_t* stringy;
extern void InitStringy();

#endif

