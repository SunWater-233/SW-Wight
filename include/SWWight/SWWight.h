#pragma once

#include "SWWight/Widget/button.h"
#include "SWWight/Widget/buttonGroup.h"
#include "SWWight/Widget/graph.h"
#include "SWWight/Widget/panel.h"
#include "SWWight/Widget/slider.h"

// define some functions that should be runned outside of the SWWight library
namespace SWWight {
extern void logic_runner();
extern void render_runner();
}  // namespace SWWight
