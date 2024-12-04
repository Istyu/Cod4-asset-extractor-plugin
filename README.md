# Cod4-asset-extractor-plugin
<p align="center">
  <img src="CoD4x_Server/ded_console.png?raw=true" />
</p>

Enable extractor commands without developer mode.

## What is this
Enables extractor commands without setting the developer parameter to 2.

## How to use
- Just write to your server.cfg `loadplugin ext`.
- Now `extract` and `assets` commands are available.

## How to compile
First of all, you require to install the following tools:

- [NASM](http://www.nasm.us/pub/nasm/releasebuilds/?C=M;O=D)
- [MinGW](http://www.mingw.org/): 'gcc' and 'mingw32-make'

- Open commandline
- Navigate to the plugin folder. cd ...CoD4x_Server\plugins\forExtractor
- Now compile the plugin by running `mingw32-make`.

Eg.: 
```
...\CoD4x_Server\plugins\forExtractor>mingw32-make
```

## Requires cod4xdedrun version
- version: 1.8
- subversion: 17.5
- build: 2055

- Download the [cod4x_server-windows_17.5.zip](https://github.com/Istyu/Cod4-asset-extractor/releases/download/IW3-Extarctor-commands/cod4x_server-windows_17.5.zip).

## Usage extractor
- 1 Start the server (cod4x18_dedrun).
- 2 Type the console "extract mod all" and press enter.
- 3 Wait for the extract to run.
- 4 You can exit to the server console.
- 5 Navigate your cod4 main directory where you ran this server, and here you can find the raw extracted files.
-
- ff - Name of fastfile to look into, without extension.
- type - Type of asset. Must be one of:
- all
- menufile
- localizedstring
- rawfile
- stringtable

Examples:
- `extract mod all              ` Extracts everything available
- `extract mod menufile         ` Extracts .menu files
- `extract mod localizedstring  ` Extracts localized string files
- `extract mod rawfile          ` Extracts raw files (gsc)
- `extract mod stringtable      ` Extract stringtables

## Why is it good to load this plugin
- The extractor mode only then it works if you `set developer 2`
- E.g.: +set fs_game mods/[your mod name] +exec server.cfg +set dedicated 0 +set developer 2
- If you load this plugin, you don't need to set the developer to 2
