//==============================================================================
//File name:    "menus.h"
//Purpose:      Menu text literals
//Version:      1.00
//Copyright:    (c) 2024, ZMT  E-mail: ztomlinson7@gmail.com
//==============================================================================

#ifndef MENUS_H
#define MENUS_H

#define VERSION "1.1.0"

/* Returns the GIT version */
// No version.c file generated for LPCXpresso builds, fall back to this
__attribute__((weak)) inline const char* Menus_GetGitVersion(void) {
    return VERSION;
}

static char* about_banner = "T-962a - (%s) ";

static char* help_text = "\n about                   Show about + debug info\n" \
                         " bake <setpoint>         Enter Bake mode with <setpoint>\n" \
                         " bake <setpoint> <time>  Enter Bake mode with <setpoint> for <time> seconds\n" \
                         " help                    Help menu\n" \
                         " list profiles           List available reflow profiles\n" \
                         " list settings           List machine settings\n" \
                         " quiet                   No logging in standby mode\n" \
                         " reflow                  Start reflow with selected profile\n" \
                         " setting <id> <value>    Set setting id to value\n" \
                         " select profile <id>     Select reflow profile by id\n" \
                         " stop                    Exit reflow or bake mode\n" \
                         " values                  Dump currently measured values\n" \
                         "\n";

void m_printf(const char* format, ...);

#endif //MENUS_H
