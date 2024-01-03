#ifndef __BACKPORT_LINUX_REFCOUNT_H
#define __BACKPORT_LINUX_REFCOUNT_H

#include <linux/atomic.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>
#include <linux/kernel.h>

/**
 * refcount_t - variant of atomic_t specialized for reference counts
 * @refs: atomic_t counter field
 *
 * The counter saturates at UINT_MAX and will not move once
 * there. This avoids wrapping the counter and causing 'spurious'
 * use-after-free bugs.
 */
typedef struct refcount_struct {
    atomic_t refs;
} refcount_t;

#define REFCOUNT_INIT(n) { .refs = ATOMIC_INIT(n), }

/**
 * refcount_set - set a refcount's value
 * @r: the refcount
 * @n: value to which the refcount will be set
 */
static inline void refcount_set(refcount_t *r, unsigned int n)
{
    atomic_set(&r->refs, n);
}

static inline void refcount_inc(refcount_t *r)
{
    atomic_inc(&r->refs);
}

static inline __must_check bool refcount_dec_and_test(refcount_t *r)
{
    return atomic_dec_and_test(&r->refs);
}

#endif /* __BACKPORT_LINUX_REFCOUNT_H */

