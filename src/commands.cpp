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
    commands.insert(std::pair("map2",            { "map2",            NULL, SHORT_ARRAY }));
    commands.insert(std::pair("map_scroll",      { "map_scroll",      NULL, ASCII }));
    commands.insert(std::pair("magicmap",        { "magicmap",        NULL, MIXED }));   /* ASCII, then binary params */
    commands.insert(std::pair("newmap",          { "newmap",          NULL, NODATA }));
    commands.insert(std::pair("mapextended",     { "mapextended",     NULL, MIXED })); /* chars, then SHORT_ARRAY */
    commands.insert(std::pair("item2",           { "item2",           NULL, MIXED }));
    commands.insert(std::pair("upditem",         { "upditem",         NULL, MIXED }));
    commands.insert(std::pair("delitem",         { "delitem",         NULL, INT_ARRAY }));
    commands.insert(std::pair("delinv",          { "delinv",          NULL, ASCII }));
    commands.insert(std::pair("addspell",        { "addspell",        NULL, MIXED }));
    commands.insert(std::pair("updspell",        { "updspell",        NULL, MIXED }));
    commands.insert(std::pair("delspell",        { "delspell",        NULL, INT_ARRAY }));
    commands.insert(std::pair("drawinfo",        { "drawinfo",        NULL, ASCII }));
    commands.insert(std::pair("drawextinfo",     { "drawextinfo",     NULL, ASCII }));
    commands.insert(std::pair("stats",           { "stats",           NULL, STATS }));
    commands.insert(std::pair("image2",          { "image2",          NULL, MIXED })); /* int, int8, int, PNG */
    commands.insert(std::pair("face2",           { "face2",           NULL, MIXED })); /* int16, int8, int32, string */
    commands.insert(std::pair("tick",            { "tick",            NULL, INT_ARRAY })); /* uint32 */
    commands.insert(std::pair("music",           { "music",           NULL, ASCII }));
    commands.insert(std::pair("sound2",          { "sound2",          NULL, MIXED })); /* int8, int8, int8,  int8,
                                                                                        * int8, int8, chars, int8,
                                                                                        * chars */
    commands.insert(std::pair("anim",            { "anim",            NULL, SHORT_ARRAY }));
    commands.insert(std::pair("smooth",          { "smooth",          NULL, SHORT_ARRAY }));
    commands.insert(std::pair("player",          { "player",          NULL, MIXED })); /* 3 ints, int8, str */
    commands.insert(std::pair("comc",            { "comc",            NULL, SHORT_INT }));
    commands.insert(std::pair("addme_failed",    { "addme_failed",    NULL, NODATA }));
    commands.insert(std::pair("addme_success",   { "addme_success",   NULL, NODATA }));
    commands.insert(std::pair("version",         { "version",         NULL, ASCII }));
    commands.insert(std::pair("goodbye",         { "goodbye",         NULL, NODATA }));
    commands.insert(std::pair("setup",           { "setup",           NULL, ASCII }));
    commands.insert(std::pair("failure",         { "failure",         NULL, ASCII }));
    commands.insert(std::pair("accountplayers",  { "accountplayers",  NULL, ASCII }));
    commands.insert(std::pair("query",           { "query",           NULL, ASCII }));
    commands.insert(std::pair("replyinfo",       { "replyinfo",       NULL, ASCII }));
    commands.insert(std::pair("ExtendedTextSet", { "ExtendedTextSet", NULL, NODATA }));
    commands.insert(std::pair("ExtendedInfoSet", { "ExtendedInfoSet", NULL, NODATA }));
    commands.insert(std::pair("pickup",          { "pickup",          NULL, INT_ARRAY }));

    return commands;
}