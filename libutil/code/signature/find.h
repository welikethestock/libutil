#ifndef __LIBUTIL_CODE_SIGNATURE_FIND__
#define __LIBUTIL_CODE_SIGNATURE_FIND__

#include "../../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
void *LibUtil_Signature_FindInSection(const void *Module, const char *Signature, const char *Section);

LIBUTIL_API LIBUTIL_IMPORT
void *LibUtil_Signature_FindInImage(const void *Module, const char *Signature);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    #define lu_signature_findinsection  LibUtil_Signature_FindInImage
    #define lu_signature_findinimage    LibUtil_Signature_FindInImage
#endif

#ifdef __cplusplus
extern "C++"
{
    namespace LibUtil
    {
        namespace Code
        {
            namespace Signature
            {
                template< typename _T = void * > LIBUTIL_FORCE_INLINE
                _T FindInSection(const void *Module, const char *Signature, const char *Section)
                {
                    return (_T)(LibUtil_Signature_FindInSection(Module, Signature, Section));
                }

                template< typename _T = void * > LIBUTIL_FORCE_INLINE
                _T FindInImage(const void *Module, const char *Signature)
                {
                    return (_T)(LibUtil_Signature_FindInImage(Module, Signature));
                }

                template< typename _T = void * > LIBUTIL_FORCE_INLINE
                _T Find(const void *Module, const char *Signature, const char *Section = NULL)
                {
                    return (Section != NULL) ? FindInSection(Module, Signature, Section) : FindInImage(Module, Signature);
                }
            }
        }
    }
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
