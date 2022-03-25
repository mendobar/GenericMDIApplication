#include "stdafx.h"
#include "CCustomEdit.h"

BEGIN_MESSAGE_MAP(CCustomEdit, CEdit)
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_CTLCOLOR()
    ON_CONTROL_REFLECT(EN_CHANGE, &CCustomEdit::OnEnChange)
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()
    ON_WM_DRAWITEM()
END_MESSAGE_MAP()

//======================================================================
// Constructor: CCustomEdit::CCustomEdit
//======================================================================
CCustomEdit::CCustomEdit()
  : m_brush_ptr(NULL)
  , m_number_valid(true)
{
    CCustomEdit::RegisterWindowClass();
}

//======================================================================
// Destructor: CCustomEdit::~CCustomEdit
//======================================================================
CCustomEdit::~CCustomEdit()
{
}

//======================================================================
// Static Member Function: CCustomEdit::RegisterWindowClass
//======================================================================
BOOL CCustomEdit::RegisterWindowClass()
{
    WNDCLASS wnd_class;
    HINSTANCE hinstance = AfxGetInstanceHandle();

    if (!(::GetClassInfo(hinstance, CUSTOM_EDIT_CTRL_CLASSNAME, &wnd_class)))
    {
        // Register a new class
        wnd_class.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
        wnd_class.lpfnWndProc = ::DefWindowProc;
        wnd_class.cbClsExtra = wnd_class.cbWndExtra = 0;
        wnd_class.hInstance = hinstance;
        wnd_class.hIcon = NULL;
        wnd_class.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
        wnd_class.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
        wnd_class.lpszMenuName = NULL;
        wnd_class.lpszClassName = CUSTOM_EDIT_CTRL_CLASSNAME;

        if (!AfxRegisterClass(&wnd_class))
        {
            AfxThrowResourceException();
            return FALSE;
        }
    }

    return TRUE;
}

//======================================================================
// Member Function: CCustomEdit::Create
//======================================================================
BOOL CCustomEdit::Create(CWnd * parent_wnd_ptr,
                        const RECT & rect,
                        UINT id,
                        DWORD style)
{
    return CWnd::Create(CUSTOM_EDIT_CTRL_CLASSNAME,
                        _T(""),
                        style,
                        rect,
                        parent_wnd_ptr,
                        id);
}

//======================================================================
// Member Function: CCustomEdit::ValidateEditControlString
//======================================================================
void CCustomEdit::ValidateEditControlString()
{
    m_number_valid = true;

    CString text_string;
    this->GetWindowText(text_string);

    int text_string_length = text_string.GetLength();

    // Do text validation here. For this generic example, just
    // assume that all text is valid.
    m_number_valid = true;

    if (!m_number_valid)
    {
        text_string = text_string.Left(text_string_length - 1);
        this->SetWindowText(text_string);
        this->SetSel(text_string_length - 1, text_string_length - 1);
    }
}

//======================================================================
// Member Function: CCustomEdit::OnCreate
//======================================================================
int CCustomEdit::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CEdit::OnCreate(lpCreateStruct) == -1)
        return -1;

    m_brush_ptr = new CBrush(RGB(0, 0, 0));

    return 0;
}

//======================================================================
// Member Function: CCustomEdit::OnDestroy
//======================================================================
void CCustomEdit::OnDestroy()
{
    CEdit::OnDestroy();

    delete m_brush_ptr;
}


//======================================================================
// Member Function: CCustomEdit::PreSubclassWindow
//======================================================================
void CCustomEdit::PreSubclassWindow()
{
    CEdit::PreSubclassWindow();

    // Uncomment the following line to cause OnDrawItem to be called.
    //ModifyStyle(0, BS_OWNERDRAW);
}


//======================================================================
// Member Function: CCustomEdit::OnCtlColor
//======================================================================
HBRUSH CCustomEdit::OnCtlColor(CDC * dc_ptr, CWnd * wnd_ptr, UINT nctl_color)
{
    HBRUSH hbr = CEdit::OnCtlColor(dc_ptr, wnd_ptr, nctl_color);

    if (m_number_valid)
    {
        dc_ptr->SetTextColor(RGB(0, 0, 0));
        dc_ptr->SetBkColor(RGB(255, 255, 255));
        hbr = (HBRUSH)(m_brush_ptr->GetSafeHandle());
    }
    else
    {
        dc_ptr->SetTextColor(RGB(255, 0, 0));
        dc_ptr->SetBkColor(RGB(0, 0, 0));
        hbr = (HBRUSH)(m_brush_ptr->GetSafeHandle());
    }

    return hbr;
}


//======================================================================
// Member Function: CCustomEdit::OnEnChange
//======================================================================
void CCustomEdit::OnEnChange()
{
    ValidateEditControlString();
}


//======================================================================
// Member Function: CCustomEdit::OnEraseBkgnd
//======================================================================
BOOL CCustomEdit::OnEraseBkgnd(CDC* pDC)
{
    // TODO: Add your message handler code here and/or call default

    return CEdit::OnEraseBkgnd(pDC);
}


//======================================================================
// Member Function: CCustomEdit::OnPaint
//======================================================================
void CCustomEdit::OnPaint()
{
    CPaintDC dc(this); // device context for painting
                       // TODO: Add your message handler code here
                       // Do not call CEdit::OnPaint() for painting messages
}

#if 0
//======================================================================
// Member Function: CCustomEdit::OnDrawItem
//======================================================================
void CCustomEdit::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect = lpDrawItemStruct->rcItem;
    UINT state = lpDrawItemStruct->itemState;

    CString strText;
    GetWindowText(strText);

    // draw the control edges (DrawFrameControl is handy!)
    if (state & ODS_SELECTED)
    {
        pDC->DrawFrameControl(rect, DFC_BUTTON, DFCS_BUTTONPUSH | DFCS_PUSHED);
    }
    else
    {
        pDC->DrawFrameControl(rect, DFC_BUTTON, DFCS_BUTTONPUSH);
    }

    // Deflate the drawing rect by the size of the button's edges
    rect.DeflateRect(CSize(GetSystemMetrics(SM_CXEDGE), GetSystemMetrics(SM_CYEDGE)));

    // Fill the interior color if necessary
    //if (m_bOverControl)
        pDC->FillSolidRect(rect, RGB(255, 255, 0)); // yellow

    // Draw the text
    if (!strText.IsEmpty())
    {
        CSize Extent = pDC->GetTextExtent(strText);
        CPoint pt(rect.CenterPoint().x - Extent.cx / 2,
                  rect.CenterPoint().y - Extent.cy / 2);

        if (state & ODS_SELECTED)
        {
            pt.Offset(1, 1);
        }

        int nMode = pDC->SetBkMode(TRANSPARENT);

        if (state & ODS_DISABLED)
        {
            pDC->DrawState(pt, Extent, strText, DSS_DISABLED, TRUE, 0, (HBRUSH)NULL);
        }
        else
        {
            pDC->TextOut(pt.x, pt.y, strText);
        }

        pDC->SetBkMode(nMode);
    }

    //CEdit::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
#endif
