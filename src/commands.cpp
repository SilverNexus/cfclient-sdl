/**
 * commands.cpp
 *
 * Copyright (C) 2022 SilverNexus and nek0d3r
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA 
 */

#include <map>
#include <cstddef>

// Enumeration borrowed from the GTK code since it also fits exactly what we need.
enum CmdFormat {
   ASCII,
   SHORT_ARRAY,
   INT_ARRAY,
   SHORT_INT, /* one short, one int */
   MIXED, /* weird ones like magic map */
   STATS, /* stat id, then value */
   NODATA
};

// Borrowing the command handler structure from the GTK2 code -- it does what we want.
struct CmdMapping {
    const char *cmdname;                    // Command's name FIXME: Redundant?
    void (*cmdproc)(unsigned char *, int ); // Function pointer to handler
    CmdFormat cmdformat;               // Parameter Type Specifier
};

std::map<const char *, CmdMapping> initialize_command_map() {
    // Use a sorted map so that we can quickly search commands as they come in.
    std::map<const char *, CmdMapping> commands;
    // TODO: Implement the commands
    commands.insert(std::pair<const char *, CmdMapping>("map2",            { "map2",            NULL, SHORT_ARRAY }));
    commands.insert(std::pair<const char *, CmdMapping>("map_scroll",      { "map_scroll",      NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("magicmap",        { "magicmap",        NULL, MIXED }));   /* ASCII, then binary params */
    commands.insert(std::pair<const char *, CmdMapping>("newmap",          { "newmap",          NULL, NODATA }));
    commands.insert(std::pair<const char *, CmdMapping>("mapextended",     { "mapextended",     NULL, MIXED })); /* chars, then SHORT_ARRAY */
    commands.insert(std::pair<const char *, CmdMapping>("item2",           { "item2",           NULL, MIXED }));
    commands.insert(std::pair<const char *, CmdMapping>("upditem",         { "upditem",         NULL, MIXED }));
    commands.insert(std::pair<const char *, CmdMapping>("delitem",         { "delitem",         NULL, INT_ARRAY }));
    commands.insert(std::pair<const char *, CmdMapping>("delinv",          { "delinv",          NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("addspell",        { "addspell",        NULL, MIXED }));
    commands.insert(std::pair<const char *, CmdMapping>("updspell",        { "updspell",        NULL, MIXED }));
    commands.insert(std::pair<const char *, CmdMapping>("delspell",        { "delspell",        NULL, INT_ARRAY }));
    commands.insert(std::pair<const char *, CmdMapping>("drawinfo",        { "drawinfo",        NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("drawextinfo",     { "drawextinfo",     NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("stats",           { "stats",           NULL, STATS }));
    commands.insert(std::pair<const char *, CmdMapping>("image2",          { "image2",          NULL, MIXED })); /* int, int8, int, PNG */
    commands.insert(std::pair<const char *, CmdMapping>("face2",           { "face2",           NULL, MIXED })); /* int16, int8, int32, string */
    commands.insert(std::pair<const char *, CmdMapping>("tick",            { "tick",            NULL, INT_ARRAY })); /* uint32 */
    commands.insert(std::pair<const char *, CmdMapping>("music",           { "music",           NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("sound2",          { "sound2",          NULL, MIXED })); /* int8, int8, int8,  int8,
                                                                                        * int8, int8, chars, int8,
                                                                                        * chars */
    commands.insert(std::pair<const char *, CmdMapping>("anim",            { "anim",            NULL, SHORT_ARRAY }));
    commands.insert(std::pair<const char *, CmdMapping>("smooth",          { "smooth",          NULL, SHORT_ARRAY }));
    commands.insert(std::pair<const char *, CmdMapping>("player",          { "player",          NULL, MIXED })); /* 3 ints, int8, str */
    commands.insert(std::pair<const char *, CmdMapping>("comc",            { "comc",            NULL, SHORT_INT }));
    commands.insert(std::pair<const char *, CmdMapping>("addme_failed",    { "addme_failed",    NULL, NODATA }));
    commands.insert(std::pair<const char *, CmdMapping>("addme_success",   { "addme_success",   NULL, NODATA }));
    commands.insert(std::pair<const char *, CmdMapping>("version",         { "version",         NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("goodbye",         { "goodbye",         NULL, NODATA }));
    commands.insert(std::pair<const char *, CmdMapping>("setup",           { "setup",           NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("failure",         { "failure",         NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("accountplayers",  { "accountplayers",  NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("query",           { "query",           NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("replyinfo",       { "replyinfo",       NULL, ASCII }));
    commands.insert(std::pair<const char *, CmdMapping>("ExtendedTextSet", { "ExtendedTextSet", NULL, NODATA }));
    commands.insert(std::pair<const char *, CmdMapping>("ExtendedInfoSet", { "ExtendedInfoSet", NULL, NODATA }));
    commands.insert(std::pair<const char *, CmdMapping>("pickup",          { "pickup",          NULL, INT_ARRAY }));

    return commands;
}