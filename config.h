#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

/* Feature definitions for MSVC build */

#define VERSION_MAJOR 4
#define VERSION_MINOR 1
#define VERSION_POINT 0
#define VERSION "4.1.0"
#define CODE_STATUS "stable"

/* Features */
#define FEATURE_ACL 1
#define FEATURE_CGI_EDIT_ACTIONS 1
#define FEATURE_FAST_REDIRECTS 1
#define FEATURE_FORCE_LOAD 1
#define FEATURE_IMAGE_BLOCKING 1
#define FEATURE_CONNECTION_KEEP_ALIVE 1
#define FEATURE_CONNECTION_SHARING 1
#define FEATURE_CLIENT_TAGS 1
/* #undef FEATURE_PTHREAD */
#define FEATURE_STATISTICS 1
#define FEATURE_TOGGLE 1

#define FEATURE_HTTPS_INSPECTION 1
#define FEATURE_HTTPS_INSPECTION_OPENSSL 1
#define FEATURE_ZLIB 1

#define HAVE_CALLOC 1
#define SIZEOF_LONG_LONG 8
#define HAVE_GETADDRINFO 1
#define HAVE_GETNAMEINFO 1

#ifdef _MSC_VER
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#define strdup _strdup
#define timegm _mkgmtime
#ifndef inline
#define inline __inline
#endif
#endif

#define _REENTRANT 1

/* Types */
#ifndef socklen_t
#define socklen_t int
#endif

/* PCRE2 */
#define PCRE2_CODE_UNIT_WIDTH 8
#define STATIC_PCRE 1
#define HAVE_PCRE2 1
#define HAVE_PCRE2POSIX 1



#endif /* CONFIG_H_INCLUDED */
