
// GenericMDIApplicationView.cpp : implementation of the CGenericMDIApplicationView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GenericMDIApplication.h"
#endif

#include "GenericMDIApplicationDoc.h"
#include "GenericMDIApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGenericMDIApplicationView

IMPLEMENT_DYNCREATE(CGenericMDIApplicationView, CView)

BEGIN_MESSAGE_MAP(CGenericMDIApplicationView, CView)
    // Standard printing commands
    ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGenericMDIApplicationView::OnFilePrintPreview)
    ON_WM_CONTEXTMENU()
    ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGenericMDIApplicationView construction/destruction

CGenericMDIApplicationView::CGenericMDIApplicationView() noexcept
{
    // TODO: add construction code here

}

CGenericMDIApplicationView::~CGenericMDIApplicationView()
{
}

BOOL CGenericMDIApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return CView::PreCreateWindow(cs);
}

// CGenericMDIApplicationView drawing

void CGenericMDIApplicationView::OnDraw(CDC* /*pDC*/)
{
    CGenericMDIApplicationDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO: add draw code for native data here
}


// CGenericMDIApplicationView printing


void CGenericMDIApplicationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
    AFXPrintPreview(this);
#endif
}

#define PRINT_MIN_PAGE (1)
#define PRINT_MAX_PAGE (2)

BOOL CGenericMDIApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
    // Set the page range.
    pInfo->SetMinPage(PRINT_MIN_PAGE);
    pInfo->SetMaxPage(PRINT_MAX_PAGE);

    // default preparation
    return DoPreparePrinting(pInfo);
}

void CGenericMDIApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add extra initialization before printing
}

void CGenericMDIApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add cleanup after printing
}

void CGenericMDIApplicationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
    ClientToScreen(&point);
    OnContextMenu(this, point);
}

void CGenericMDIApplicationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
    theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGenericMDIApplicationView diagnostics

#ifdef _DEBUG
void CGenericMDIApplicationView::AssertValid() const
{
    CView::AssertValid();
}

void CGenericMDIApplicationView::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

CGenericMDIApplicationDoc* CGenericMDIApplicationView::GetDocument() const // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGenericMDIApplicationDoc)));
    return (CGenericMDIApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CGenericMDIApplicationView message handlers

void CGenericMDIApplicationView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
    CView::OnPrint(pDC, pInfo);
}
