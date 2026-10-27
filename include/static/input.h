#ifndef CRUX_STATIC_INPUT_H
#define CRUX_STATIC_INPUT_H

#include "kernel_types.h"
#include "input_api.h"

#ifdef __cplusplus
extern "C" {
#endif

// The static rendering of the input contract: plain externs, defined by the
// input driver and linked into the binary. A static consumer pays zero
// indirection and cannot accidentally dispatch - the same shape as the
// platform's static rendering.
extern bool Input_PollEvent(CruxInputEvent *out);
extern bool Input_WaitEvent(CruxInputEvent *out, uint64_t timeoutNS);
extern bool Input_PeekEvent(uint64_t timeoutNS);
extern bool Input_PushEvent(const CruxInputEvent *event);

#ifdef __cplusplus
}
#endif

#endif
