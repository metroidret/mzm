#include "event.h"
#include "constants/event.h"

/**
 * 608bc | 6c | Function used to manipulate the events
 * 
 * @param action Action to do with the event
 * @param event Event concerned
 * @return bool, event is set
 */
u32 EventFunction(EventAction action, Event event)
{
    u32* pEvent;
    u32 previous;
    u32 newEvent;
    u32 isSet;

    // Check is a valid event
    if (event == EVENT_NONE || event >= EVENT_COUNT)
        return FALSE;

    // Get event chunk
    pEvent = gEventsTriggered;
    pEvent += event / 32;

    // Get correct bit for the requested event
    newEvent = 1 << (event % 32);
    // Get previous event
    previous = *pEvent;

    // Check is set
    isSet = previous & newEvent;
    if (isSet)
        isSet = TRUE; // Not 0, then set

    // Apply action
    switch (action)
    {
        case EVENT_ACTION_CLEAR:
            // Remove
            *pEvent = previous & ~newEvent;
            break;

        case EVENT_ACTION_SET:
            // Add
            *pEvent = previous | newEvent;
            isSet ^= TRUE;
            break;

        case EVENT_ACTION_TOGGLE:
            // Toggle
            *pEvent = previous ^ newEvent;
            isSet ^= TRUE;
            break;
    }

    return isSet;
}
