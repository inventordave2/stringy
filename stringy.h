/* STRINGY_H */

#ifndef DAVELIB_STRINGY_H
#define DAVELIB_STRINGY_H


typedef struct stringy_t	{
	
	unsigned long long 	(*strlen)			( char* ); 
	char* 				(*getstring) 		( char* );
	char* 				(*zalloc)			( unsigned long long );
	char* 				(*ull2digitstr)		( unsigned long long );
	
	char*				(*safecat)			( char*, char* );

} stringy_t;

extern const struct stringy_t stringy;
extern void InitStringy();

#endif
