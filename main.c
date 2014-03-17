#include "pset.h"

struct test{
    int val;
    char *name;
};

struct foo{
    struct test t;
    float f;
};

int main(){
    struct test t = { 1, "hello" } ;
    pset_h table = pset_create( 0, 0 );
    pset_add (table, &t ) ;

    struct test *p = pset_pointer( table, 0);
    printf("val = %d, name = %s\n", p->val, p->name) ;

    struct foo foo = {
        { 2, "What a sunny day!" },
        3.0
    };
    
    pset_add (table, &foo );
    struct foo *q = pset_pointer( table, 1);
    printf("val = %d, name = %s, msg = %f\n", q->t.val, q->t.name, q->f) ;
	pset_destroy(table) ;

    return 0 ;    
}
