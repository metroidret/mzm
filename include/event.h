#ifndef EVENT_H
#define EVENT_H

#include "types.h"

#include "constants/event.h"

#define CLEAR_EVENT(event) EventFunction(EVENT_ACTION_CLEAR, event)
#define SET_EVENT(event) EventFunction(EVENT_ACTION_SET, event)
#define TOGGLE_EVENT(event) EventFunction(EVENT_ACTION_TOGGLE, event)
#define CHECK_EVENT(event) EventFunction(EVENT_ACTION_CHECK, event)

extern u32 gEventsTriggered[8];

u32 EventFunction(EventAction action, Event event);

#endif /* EVENT_H */
