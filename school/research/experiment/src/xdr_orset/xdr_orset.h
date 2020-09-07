#include "../orset/orset.h"
#include "../node.h"
#include <rpc/xdr.h>
#include <stdio.h>

/* OrSet items encode and decode to an
 * unsigned long key then a string as data.
 * Strings are held using buffers created by
 * malloc on decode. Tombstones are encoded
 * by a zero length string.
 */
bool_t xdr_orset_item(XDR *xdr, void* os);

/* OrSets encode to and decode from  an
 * unsigned long representing the node is 
 * then an array of xdr_orset_items (see
 * above).
 */
bool_t xdr_orset(XDR *xdr, void* os);
