#ifndef CRUX_INPUT_API_H
#define CRUX_INPUT_API_H

#include "kernel_types.h"

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// The input concern's contract: the one struct of function pointers the input
// driver fills and serves - the neutral event stream. The concern is
// dispatched through the engine's registry channel: the driver's served
// InputAPI, selected by the concern's stable dispatch id. PushEvent is the
// injection point (a display
// driver or a test harness pushes; a pushed event polls like any OS-sourced
// one). PeekEvent is the NON-consuming timed wait - true when an event is
// pending, the head is not popped (the boot's frame pacing blocks on it
// without stealing an event). Every API struct in this project leads with its
// version.
typedef struct InputAPI {
  PackageVersion version;
  bool (*PollEvent)(CruxInputEvent *out);
  bool (*WaitEvent)(CruxInputEvent *out, uint64_t timeoutNS);
  bool (*PeekEvent)(uint64_t timeoutNS);
  bool (*PushEvent)(const CruxInputEvent *event);
} InputAPI;

#ifdef __cplusplus
}
#endif

#endif
