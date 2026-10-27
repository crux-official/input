#ifndef CRUX_DYNAMIC_INPUT_H
#define CRUX_DYNAMIC_INPUT_H

#include "kernel_types.h"
#include "input_api.h"
#include "engine.h"
#include "kernel_types.h"

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// The dynamic rendering of the input contract: every call dispatches through
// the engine's registry channel - the input driver's served InputAPI,
// selected by the concern's stable dispatch id (DRIVER_INPUT,
// platform_types.h). crux_engine_api is the module-global pointer defined by
// the install TU the DYNAMIC dialect compiles in and installed by the
// target's Construct (the same pattern as the engine's own dynamic rendering).
static inline bool Input_PollEvent(CruxInputEvent *out) {
  return ((InputAPI *)crux_engine_api->GetExtensionAPI(DRIVER_INPUT))->PollEvent(out);
}
static inline bool Input_WaitEvent(CruxInputEvent *out, uint64_t timeoutNS) {
  return ((InputAPI *)crux_engine_api->GetExtensionAPI(DRIVER_INPUT))->WaitEvent(out, timeoutNS);
}
static inline bool Input_PeekEvent(uint64_t timeoutNS) {
  return ((InputAPI *)crux_engine_api->GetExtensionAPI(DRIVER_INPUT))->PeekEvent(timeoutNS);
}
static inline bool Input_PushEvent(const CruxInputEvent *event) {
  return ((InputAPI *)crux_engine_api->GetExtensionAPI(DRIVER_INPUT))->PushEvent(event);
}

#ifdef __cplusplus
}
#endif

#endif
