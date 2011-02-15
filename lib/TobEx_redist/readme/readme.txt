Throne of Bhaal Extender (TobEx)
Redistributable Package - For Modders
Author: Ascension64


Summary
-------
TobEx (Throne of Bhaal Extender) is a dynamic link library (DLL) written in C++ that fixes game engine bugs and extends the game engine by modifying the virtual image of the Throne of Bhaal BGMain.exe in memory.

This technique allows greater flexibility compared to hard-coding changes into the BGMain.exe file.

The redistributable package contains the core TobEx files available for modders to use within their modifications.


Requirements
------------
Baldur's Gate II: Throne of Bhaal version 26498 is required.

This utility will not install on other versions of Throne of Bhaal.
This utility will not work on Macintosh systems.


Usage
-----
You are free to include this redistributable package in your modifications. Please give credit where it is due.

In order to install TobEx as part of your modification:
1. Place the entire ./TobEx_redist directory within your mod directory.
2. Insert the following code into your mod's main .tp2 file. Replace <your mod directory> with the directory that your mod uses. Please note that TOBEX_ is used as a prefix to make the variable unique. It should not point to the TobEx mod directory, but to your mod's directory.

OUTER_SPRINT TOBEX_MOD_DIRECTORY "./<your mod directory>"
LOAD_TRA "%TOBEX_MOD_DIRECTORY%/TobEx_redist/TobEx.tra"
ACTION_INCLUDE "%TOBEX_MOD_DIRECTORY%/TobEx_redist/TobEx.tpa"

3. Once installed, existing tweak settings are kept and all new tweak settings are disabled by default. In order to activate tweaks, use REPLACE_TEXTUALLY on TobEx_ini/TobExTweak.ini. For example,

COPY "TobEx_ini/TobExTweak.ini" "TobEx_ini/TobExTweak.ini"
  REPLACE_TEXTUALLY "A Tweak=0" "A Tweak=1"
BUT_ONLY_IF_IT_CHANGES

4. In order to support translations to other languages, translators should translate TobEx.tra. Then, modify the LOAD_TRA tp2 action to point to the language-specific .tra file. For example:

LOAD_TRA "%TOBEX_MOD_DIRECTORY%/language/%LANGUAGE%/TobEx.tra"


Notes
-----
1. If another mod has installed TobEx_redist, the installation will check the user's current TobEx_redist version and update accordingly if required. There is no need to manually check the user's current TobEx_redist version.
2. Core tweak settings are not kept - if your mod installs a new version of TobEx_redist, the existing settings in TobEx_ini/TobExCore.ini are overwritten.
3. Existing tweak settings are kept - if your mod installs a new version of TobEx_redist, the existing settings in TobEx_ini/TobExTweak.ini are kept.
4. There is no need to, although you can, install TobEx_redist as a separate component in your modification. If required, check for the presence of an existing TobEx_redist version by using FILE_EXISTS "TobEx_ini/TobExVer.txt".
5. TobEx translation strings occupy references starting from @-10000 and going lower (more negative). Avoid using these strings in your modification because TobEx will overwrite them.


Troubleshooting
---------------
First, make sure that TobEx is actually the issue.
You can forcefully disable TobEx from running by renaming TobEx.dll in your game directory.

For more debugging information:
1. Open TobEx_ini/TobExCore.ini in a simple text editor.
2. Under the [Debug] section, set all values of 0 to 1.
3. Try to reproduce your error in-game. TobEx may sometimes reports some extra information about the error.
4. Report any errors you find on the Spellhold Studios forums. Expect to be asked to attach a .zip of your saved game folder, WeiDU.log, 
TobEx.log, TobExCore.ini, and TobExTweak.ini.


Compatibility
-------------
It is recommended that TobEx be installed as the first modification in a multi-modification installation.

TobEx may have compatibility issues with mods that directly modify the executable.

Please apply the troubleshooting tips above if you are having trouble and believe you may be experiencing compatibility issues with other 
modifications.

Modifications that modify the executable (in alphabetical order):
-1PP Extended Palette Entries
-1PP Female Dwarves
-1PP Thieves Galore
-A6CharmPatch
-A6XPPatch
-Aurora's Shoes and Boots
-Fishing For Trouble
-Baldur's Gate Trilogy-WeiDU (BGT-WeiDU)
-Infinity Animations
-Sword Coast Stratagems (SCS)
-Sword Coast Stratagems II (SCSII)
-Spell Revisions
-tb#tweaks
-tob_hacks
-tob_inject
-Widescreen mod
-Various experience cap patches


Executable space used
---------------------
0x639573-0x63957C
0x66F0F5-0x66F0FB
0x66F115-0x66F11C
0x66F135-0x66F13E


Revision History
----------------
See revisions.txt.


Credits
-------
-BioWare for creating the Infinity Engine and its games
-Contributors to the Infinity Engine Structure Description Project (IESDP) for data structure information
-GemRB developers for providing further data structure information
-Taimon for ToB_hacks and his research
-The Infinity Engine modding community for their support