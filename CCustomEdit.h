
#pragma once
#include <afxwin.h>

#define CUSTOM_EDIT_CTRL_CLASSNAME _T("EDITCUSTOM")

class CCustomEdit : public CEdit
{
private:

    CBrush * m_brush_ptr;
    bool m_number_valid;

public:

    CCustomEdit();

    virtual ~CCustomEdit();

    BOOL Create(CWnd * parent_wnd_ptr,
                const RECT & rect,
                UINT id,
                DWORD style = WS_VISIBLE);

protected:

    static BOOL RegisterWindowClass();

    void ValidateEditControlString();

public:
    virtual void PreSubclassWindow();

    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg HBRUSH OnCtlColor(CDC * dc_ptr, CWnd * wnd_ptr, UINT nctl_color);
    afx_msg void OnEnChange();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnPaint();
    //afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};

