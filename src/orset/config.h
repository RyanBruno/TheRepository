#ifndef CONFIG_H
#define CONFIG_H
/* General Configuration */

/* This defines how big the node id should
 * be. Your only reasonable choices are
 * uint16_t or uint8_t.
 * uint8_t => max value = 256
 * uint16_t => max value = 65,536
 */
#define node_t uint8_t

/* RPC configuration points */

/* Passed directly to svc_register and
 * clnt_create.
 */
#define VERSION_NUMBER 1

/* The timeout for a single merge request */
//time_t MERGE_TIMEOUT = 20;
#define MERGE_TIMEOUT 20

#ifdef CONCREATE
#include "node.h"

/* We achieve "plugin-like" modularity by
 * adding thread functions to this array.
 * Theses threads are creates on startup.
 */
void *(*threads[]) (void*) = {
    client_thread_fn,
    NULL,
};

/* Client thread configuration points */

/* The amount of time between merge
 * requests.
 */
unsigned int MERGE_RATE = 1;

/* Describes the network of peers. This
 * array contains the current node_id.
 * The client thread skips it.
 */
struct peer_node peers[] = {
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100600L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100601L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100602L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100603L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100604L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100605L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100606L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100607L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100608L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100609L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100610L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100611L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100612L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100613L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100614L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100615L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100616L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100617L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100618L },
    { .peer_id = 0, .peer_host = "127.0.0.1", .peer_prognum = 100619L },
};
int PEERS_LEN = 4;
#endif /* CONCREATE */
#endif /* CONFIG_H */
