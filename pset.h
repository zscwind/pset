#include <stdlib.h>
typedef void *__pset_pointer ;

struct __pset
{
    unsigned alloc_step;
    __pset_pointer *ptrs;
    unsigned max;
    unsigned count;
};

typedef struct __pset *pset_h;

pset_h pset_create( unsigned alloc_start, unsigned alloc_step);
void pset_destroy( pset_h pset);
void pset_delete( pset_h pset, const __pset_pointer);
__pset_pointer pset_add( pset_h pset, const __pset_pointer);

#define pset_remove( pset, ptr)      pset_delete(pset, (__pset_pointer)ptr)
#define pset_remove_index( pset, i)   \
    {                           \
        if (((unsigned)i) < (pset)->count)  \
            pset_delete( pset, (pset)->ptrs[(unsigned)(i)]) \
    }

#define pset_clear( pset )          (pset)->count = 0
#define pset_count( pset )          (pset)->count
#define pset_pointer( pset, i )     (pset)->ptrs[(unsigned)(i)]


