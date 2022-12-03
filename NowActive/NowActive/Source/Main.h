#pragma once

#include <iostream>
#include "console.h"
#include "listat.h"
#include "color.h"

// properties()
// To Set Applicateion Properties
void properties()
{
	WindowTitle("NowActive");
	Console_MoveTo(325, 225);
	Console_ToSize(600, 500);
}

void choose_software();

static int kernal = 0;

// runActivate
// To activateWindows
void runActivate(const char* productKey)
{
	clear();
	WindowTitle("NowActivate -> Activateing");

	system(productKey);

	std::cout << dye::light_red_on_black(" productKey Installed Successfully \n\n");

	system("slmgr /kms8.msguides.com");
	system("slmgr /ato");

	std::cout << dye::light_green_on_black(" Almost there, Windows is activated!! \n\n");

	std::cout << dye::light_green_on_black(" You need to reboot [ PC ] \n\n");

	Listat* list = new Listat;
	list->properties(0, 2, 1, 0);
	std::string listMenu[2] = { "Reboot Now","Nuh, Later" };

	while (true)
	{
		list->vertical_Sort(listMenu, 0);
		list->Input(true);
		switch (list->theChar())
		{
		case 'e':case 'E':
			switch (list->Current())
			{
			case 0:
				system("Shutdown -r");
				break;

			case 1:
				exit(0);
				break;

			default:break;
			}
			break;

		default:break;
		}
	}

}

// *** Im stuck here ***
// _windows10()
void _windows10()
{
	WindowTitle("NowActive -> Windows10 Properties Selector");
	// windows 10 productKeys
	const char* productKeys[10] = {
	"slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99","slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM", "slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH","slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR","slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX","slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9","slmgr /ipk NW6C2-QMPVW-D7KKK-3GKT6-VCFB2", "slmgr /ipk 2WH4N-8QGBV-H22JP-CT43Q-MDWWJ","slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9", "slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4" };

	NewListat* list = new NewListat;

	const int chooselistSize = 3;
	Listat chooseList[chooselistSize];

	const int kernalSelector = 0;
	const int distroSelector = 1;
	const int activateSelector = 2;

	chooseList[kernalSelector].properties(1, 3, 2, 1);
	chooseList[distroSelector].properties(1, 11, 2, 1);
	chooseList[activateSelector].properties(1, 3, 2, 1);

	list->listProperties(0, chooselistSize, 1, 0);

	std::string chooselistTitle[3] = { "Kernal","Destro","Checkk" };
	std::string chooselistStock[3][99] = {
		{"None","x64","x86"},
		{"None","Windows Home","Windows HomeN","HomeSingleLanguage","HomeCountrySpecific","Professional","ProfessionalN","Education","EducationN","Enterprise","EnterpriseN"},
		{"None","Activate","../ Back"}
	};

	std::string kernal = chooselistStock[kernalSelector][chooseList[kernalSelector].Current()];

	while (true) {
		list->horizontal_Sort(chooselistTitle, chooselistStock, chooseList);
		list->nasatedInput(&chooseList[list->Currentlist()]);

		switch (list->theChar())
		{
		case 'e':case'E':
			if (list->Currentlist() == activateSelector)
			{
				if (chooseList[activateSelector].Current() == 1)
				{
					const char* productKey = productKeys[chooseList[distroSelector].Current() - 1];
					if ((kernal == "x64" || kernal == "x86") && (chooseList[distroSelector].Current() != 0))
					{
						runActivate(productKey);
					}
				}
				if (chooseList[activateSelector].Current() == 2)
				{
					choose_software();
				}
			}
			break;

		case 'q':case 'Q':
			for (int counter = 0; counter < chooselistSize; counter++)
			{
				chooseList[counter].Current(chooseList[counter].Def());
			}
			break;

		default:break;
		}
	}
}

// info
void info()
{
	clear();
	std::cout << dye::black_on_light_yellow("                                        \n");
	std::cout << dye::black_on_light_yellow(" How To Use ?                           \n");
	std::cout << dye::black_on_light_yellow(" go gp 'W' || go down 'S' || choose 'E' \n");
	std::cout << dye::black_on_light_yellow("                                        \n");
	pause();
}

// choose_software()
// to choose witch distro you wanna activate
void choose_software()
{
	WindowTitle("NowActive");
	// createing list from [class] Listat 
	Listat* list = new Listat;

	// [string][array] for list titles
	std::string ltitle[5] = {
		"Windows 7" , "Windows 8.1" , "Windows 10" , "info" , "Quit"
	};

	// setting list properties
	list->properties(0, 5, 1, 0);

	while (true)
	{
		list->vertical_Sort(ltitle, 0);
		list->Input(true);

		switch (list->theChar())
		{
		case 'e':case 'E':
			switch (list->Current())
			{
			case 0:
				break;
			
			case 1:
				break;
			
			case 2:
				_windows10();
				break;
			
			case 3:
				info();
				break;

			case 4:
				exit(0);
				break;

			default:break;
			}
			break;

		default:break;
		}
	}
}
