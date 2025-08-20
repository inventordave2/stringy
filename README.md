# stringy v0.1

typedef struct Stringy	{
	 
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
	
	// regex: test,extract
	// typedef struct regex_value { uint64_t numMatches; char** matches; uint64_t** offset_from_start_of_IN_string; };
	
	
	void 				(*nl)				();
	
	FILE*				(*writeToFile)		( FILE*, char*, uint8_t );
	
	// With the writeToFile feature, the OUT string might need pre-processing to embed file format control codes for presentation (HTML5, or SVG, or any provided presentation formats that are renderable to serialized files (typically, these are files on the computer harddrive, in the filing system).h
	// An opt object might have "<div><id=[$1]><css=[$2]>:[$3]", $1 = someIdGenerator, $2 = "csssnippet.css", $3 = "<img src=... />In this sample div, you see residing, this text.<input type="button"... >". XML+XSTL can generate the HTML5/CSS strings based on an input opt object presented in XML. 	
	
	// This basically means the declaration vocabulary would be an XML syntax. This declaration vocabulary for declaring HTML5 structures in an XML definition, to be transformed by XML+XSTL into the DOM HTML5 target tagset.
	
	// Strings are buffers. Buffers are storage regions for structured (or unstructured) data.
	// A user may wish to Transform an INput string through some given transformer to an OUTput string that is botth distinct from the INput string, and has either lexical, syntactical (grammatical), or behavioural (dynamical) validity. This means some requirements may be to be successfully lexable by a tokenizer, to be validated against pattern constraints (grammar), pehaps to successfully pass a semantic (modal) validator. In thought of the UNIX philosophy "Everything is a FILE", a FILE can be conceptualised as a buffer, and a transformed (OUT) string may be passed to a seperate output buffer,file,whatever, or perhaps under user-defined constraints, written back into the source buffer that the INput string is located. One example of a string transformer might be to process a REQ message in a given communication protocol to an associated valid RESP message, to send back as a response.
	
	
	Sample:
	
	REQ <- "/products/listing.html?access_token=[some given access token for OAuth2 access, for example]+category=food_stores"
	RESP <- [whatever the .HTML output string would be if handling this sample domain request]
	
	This example is what you might expect to be happening inside a web server, or any network responder. If the Stringy library sends a string to a formatting subsystem, for the processing of tags (such as [brightmagenta] in ANSIVT, or <div> in HTML5), it needs to know which tags to insert, at what offsets within the INput string, but often the user providing the IN string will know what they are, and insert them into the string before passing it as an IN string to Stringy.
	
	
	Example:
	
	in:		"<num>2</num>*<num>3.14159</num>"
	out:	"<span style=\"style_file.css\">2 &nbsp;<img src=\"star_operator.bmp" alt=\"MULTIPLY\" />&nbsp;3.14159 &nbsp;<img src=\"equals_sym.bmp\"> alt=\"EQUALS\" />&nbsp; 6.28318</span>"
	
	Having computed the input equation through ALGAE, and receiving the result (assumed here to be 6.28318), then generating the output HTML fragment 

} Stringy;

TODO: Integration with regex, so having the stringy API in-process gives the user regex test/extract/replace functions.

