// SetRes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>


static void setSize(int width, int height)
{
    DEVMODE dm;
    DWORD flags = 0;
    LONG result;

    // Clear memory
    memset(&dm, 0, sizeof(dm));

    dm.dmSize = sizeof(dm);
    dm.dmDriverExtra = 0;
    dm.dmPelsWidth = width;
    dm.dmPelsHeight = height;
    dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;


    result = ChangeDisplaySettings(&dm, flags);

    switch (result)
    {
    case DISP_CHANGE_SUCCESSFUL: printf("The settings change was successful.\n"); break;
    case DISP_CHANGE_RESTART: printf(" The computer must be restarted in order for the graphics mode to work.\n"); break;
    case DISP_CHANGE_BADFLAGS: printf(" An invalid set of flags was passed in.\n");  break;
    case DISP_CHANGE_BADPARAM: printf(" An invalid parameter was passed in. This can include an invalid flag or combination of flags. \n");  break;
    case DISP_CHANGE_FAILED: printf(" The display driver failed the specified graphics mode. \n");  break;
    case DISP_CHANGE_BADMODE: printf(" The graphics mode is not supported. \n");  break;
    case DISP_CHANGE_NOTUPDATED: printf(" Windows NT/ 2000: Unable to write settings to the registry. \n");  break;
    default: printf("Unknown error: %ld\n", result);
    }
}

static void setReset()
{
    ChangeDisplaySettings(NULL, 0);
}

static void printUsage()
{
    printf("Usage:\n"
           "    SetRes 800      -   set to 800x600\n"
           " or\n"
           "    SetRes 1024     -   set to 1024x768\n"
           " or\n"
           "    SetRes reset    -   back to default resolution\n\n");
}



int main(int argc, char* argv[])
{
#if 0
    setSize(800, 600);
#else
    if (argc != 2)
    {
        printUsage();
        return 1;
    }

    if (strcmp(argv[1], "800") == 0)
    {
        setSize(800, 600);
    }
    else if (strcmp(argv[1], "1024") == 0)
    {
        setSize(1024, 768);
    }
    else if (strcmp(argv[1], "1152") == 0)
    {
        setSize(1152, 864);
    }
    else if (strcmp(argv[1], "reset") == 0)
    {
        setReset();
    }
    else
    {
        printUsage();
        return 2;
    }
#endif
	return 0;
}

