
// GenericMDIApplication.h : main header file for the GenericMDIApplication application
//
#pragma once

#ifndef __AFXWIN_H__
    #error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGenericMDIApplicationApp:
// See GenericMDIApplication.cpp for the implementation of this class
//

class CGenericMDIApplicationApp : public CWinAppEx
{
public:
    CGenericMDIApplicationApp() noexcept;


// Overrides
public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();

// Implementation
    UINT  m_nAppLook;
    BOOL  m_bHiColorIcons;

    virtual void PreLoadState();
    virtual void LoadCustomState();
    virtual void SaveCustomState();

    afx_msg void OnAppAbout();
    DECLARE_MESSAGE_MAP()
};

extern CGenericMDIApplicationApp theApp;
