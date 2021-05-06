#pragma once

#include "quantum.h"

#define LAYOUT( \
	K00 \
) { \
	{ K00}  \
}

enum encoder_modes {
  ENC_MODE_MIN,
  ENC_MODE_MAX,
};