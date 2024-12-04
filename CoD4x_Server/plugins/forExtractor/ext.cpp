/*
  ____________________________________________________________________________________________________________
//____________________________________________________________________________________________________________\\
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||==========|||==========|||==========|||||||||====|||||||||==|||||||||||||==========|||==||||||||==||||||||
||||||==||||||==|||||||==|||||||==||||||||||||||||==||==||||||||==|||||||||||||||||==|||||||==||||||||==||||||||
||||||==|||||||||||||||==|||||||==|||||||||||||||==||||==|||||||==|||||||||||||||||==|||||||==||||||||==||||||||
||||||==========|||||||==|||||||=======|||||||||==||||||==||||||==|||||||||||||||||==|||||||============||||||||
||||||||||||||==|||||||==|||||||==|||||||||||||============|||||==|||||||||||||||||==|||||||==||||||||==||||||||
||||||==||||||==|||||||==|||||||==||||||||||||==||||||||||==||||==|||||||||||||||||==|||||||==||||||||==||||||||
||||||==========|||||||==|||||||==========|||==||||||||||||==|||============|||||||==|||||||==||||||||==||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||____________________________________________________________________________________________________________||
||          Script ext.cpp    2024.12.01.                                                                     ||
||          Author: Stealth                                                                                   ||
||                                                                                                            ||
||          project: Asset extractor                                                                          ||
||          website: None                                                                                     ||
||                                                                                                            ||
||          Description                                                                                       ||
||             This plugin able to allow extractor commands.                                                  ||
||             Ez a beépülő modul engedélyezi a extractor parancsokat.                                        ||
||             Version: 1.0                                                                                   ||
||                                       [Do not modify this file!]                                           ||
||                                      [Ne változtasd meg a fájlt!]                                          ||
\\____________________________________________________________________________________________________________//

*/


/*
============================
    Plugin INClude file
  This contains plugin lib
 This file must be included
============================
*/

#include "../pinc.h"

/*
==================
  Other includes
==================
*/
#include <cstring>
#include <string>

/*
===========================
     OnInit callback
 This is a function called
  right after the plugin
        is loaded.
===========================
*/

#define AddExtractorCmds 0x144062BE

void __cdecl AddExtractorCmds_wrapper()
{
    auto function = reinterpret_cast<void(__cdecl*)()>(AddExtractorCmds);
    function();
}

PCL int OnInit()
{
    Plugin_Printf("- Extractor plugin: \n");
    AddExtractorCmds_wrapper();
    Plugin_Printf("\tServer must be running in order to extract assets.\n \t'extract' and 'assets' commands are available\n");
    Plugin_Printf("- Extractor plugin -\n");
	return 0;
}


PCL void OnInfoRequest(pluginInfo_t *info)
{	// Function used to obtain information about the plugin
    // Memory pointed by info is allocated by the server binary, just fill in the fields

    // =====  MANDATORY FIELDS  =====
    info->handlerVersion.major = PLUGIN_HANDLER_VERSION_MAJOR;
    info->handlerVersion.minor = PLUGIN_HANDLER_VERSION_MINOR;	// Requested handler version, we request the version compatible with this plugin lib

    // =====  OPTIONAL  FIELDS  =====
    info->pluginVersion.major = 1;
    info->pluginVersion.minor = 0;	// Plugin version
    strncpy(info->fullName,"Cod4x extract assets 2024.",sizeof(info->fullName)); //Full plugin name
    strncpy(info->shortDescription,"This plugin able to allow extractor commands. Made by Stealth ",sizeof(info->shortDescription)); // Short plugin description
    strncpy(info->longDescription,"Enables extractor commands without setting the developer parameter to 2.",sizeof(info->longDescription));
}
