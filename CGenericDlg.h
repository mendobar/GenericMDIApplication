// File: CGenericDlg.h
// Author: Bill Hallahan

#include "resource.h"
#include <afxdialogex.h>
#include "CCustomEdit.h"

class CGenericDlg :
    public CDialogEx
{
public:
    CGenericDlg();
    virtual ~CGenericDlg();

    // Dialog Data
    enum { IDD = IDD_GENERIC };

protected:

    CString m_PERSON_NAME;

    CCustomEdit m_PERSON_NAME_edit_ctrl;

    bool m_is_initialized;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
    DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnEnChangeEditHomeAddress();
};
