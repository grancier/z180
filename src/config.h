#define WIN32 1
#define Z88DK_EXPAND_STRING(X) Z88DK_STRING(X)
#define Z88DK_STRING(X) #X
#define Z88DK_VERSION "MSC." Z88DK_EXPAND_STRING(_MSC_FULL_VER) " " __DATE__
