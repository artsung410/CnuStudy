#pragma once

#define SafeFree(p) { free(p); p = NULL; }
#define SetCoord(coord, x, y) { (coord).X = x; (coord).Y = y; }