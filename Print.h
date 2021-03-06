#pragma once

#include "resource.h"


void PageGDICalls(HDC hdcPrn, int cxPage, int cyPage)
{
	static TCHAR szTextStr[] = TEXT("Hello, Printer!");
	Rectangle(hdcPrn, 0, 0, cxPage, cyPage);
	MoveToEx(hdcPrn, 0, 0, NULL);
	LineTo(hdcPrn, cxPage, cyPage);
	MoveToEx(hdcPrn, cxPage, 0, NULL);
	LineTo(hdcPrn, 0, cyPage);

	SaveDC(hdcPrn);

	SetMapMode(hdcPrn, MM_ISOTROPIC);
	SetWindowExtEx(hdcPrn, 1000, 1000, NULL);
	SetViewportExtEx(hdcPrn, cxPage / 2, -cyPage / 2, NULL);
	SetViewportOrgEx(hdcPrn, cxPage / 2, cyPage / 2, NULL);

	Ellipse(hdcPrn, -500, 500, 500, -500);
	SetTextAlign(hdcPrn, TA_BASELINE | TA_CENTER);
	TextOut(hdcPrn, 0, 0, szTextStr, lstrlen(szTextStr));
	RestoreDC(hdcPrn, -1);
}
