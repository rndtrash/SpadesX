// Copyright SpadesX team 2022
#ifndef EVENTS_H
#define EVENTS_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "Util/Log.h"
#include "Util/Utlist.h"

enum
{
    EVENT_CONTINUE,
    EVENT_BREAK
};

enum
{
    EVENT_FIRST,
    EVENT_LAST
};

#define EVENT(event, ...) \
    typedef int (*event ## Callback)(__VA_ARGS__); \
    typedef struct event ## Listener {int (*callback)(__VA_ARGS__); struct event ## Listener *next;} event ## Listener; \
    extern struct event ## Listener *g_ ## event ## Listeners; \
    void event ## Subscribe(event ## Callback callback, int position); \
    void event ## Unsubscribe(event ## Callback callback); \
    void event ## Run(__VA_ARGS__);

#define EVENT_DEFINITION(event, argumentNames, ...) \
    struct event ## Listener *g_ ## event ## Listeners = NULL; \
    void event ## Subscribe(event ## Callback callback, int position) { \
        struct event ## Listener *el; el = malloc(sizeof *el); if (!el) {LOG_ERROR("Out of memory. Oh well."); return;} \
        el->callback = callback; if (position == EVENT_LAST) LL_APPEND(g_ ## event ## Listeners, el); else LL_PREPEND(g_ ## event ## Listeners, el);} \
    void event ## Unsubscribe(event ## Callback callback) { \
        struct event ## Listener *el; LL_SEARCH_SCALAR(g_ ## event ## Listeners, el, callback, callback); if (!el) return; \
        LL_DELETE(g_ ## event ## Listeners, el); free(el);} \
    void event ## Run(__VA_ARGS__) { \
        struct event ## Listener *el; el = g_ ## event ## Listeners; \
        while (el && el->callback argumentNames != EVENT_BREAK) el = el->next;}

EVENT(PlayerDisconnect, uint8_t ID)

#endif
