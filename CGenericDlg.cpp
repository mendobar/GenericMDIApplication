// File: CGenericDlg.cpp
// Author: Bill Hallahan

#include "stdafx.h"
#include "CGenericDlg.h"

CGenericDlg::CGenericDlg()
  : CDialogEx(CGenericDlg::IDD)
  , m_is_initialized(false)
{
}


CGenericDlg::~CGenericDlg()
{
}

//======================================================================
// Member Function: CGenericDlg::DoDataExchange
//======================================================================
void CGenericDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    if (m_is_initialized)
    {
        DDX_Control(pDX, IDC_EDIT_PERSON_NAME, m_PERSON_NAME_edit_ctrl);
        DDX_Text(pDX, IDC_EDIT_PERSON_NAME, m_PERSON_NAME);
    }
}

BEGIN_MESSAGE_MAP(CGenericDlg, CDialogEx)
    ON_EN_CHANGE(IDC_EDIT_HOME_ADDRESS, &CGenericDlg::OnEnChangeEditHomeAddress)
END_MESSAGE_MAP()


BOOL CGenericDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    m_PERSON_NAME_edit_ctrl.Create(this, CRect(14, 42, 193, 65), IDC_EDIT_PERSON_NAME);

    m_PERSON_NAME_edit_ctrl.ShowWindow(SW_SHOWNORMAL);
    m_PERSON_NAME_edit_ctrl.BringWindowToTop();

    m_is_initialized = true;

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}


void CGenericDlg::OnEnChangeEditHomeAddress()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CDialogEx::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}
