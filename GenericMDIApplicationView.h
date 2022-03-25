
// GenericMDIApplicationView.h : interface of the CGenericMDIApplicationView class
//

#pragma once


class CGenericMDIApplicationView : public CView
{
protected: // create from serialization only
    CGenericMDIApplicationView() noexcept;
    DECLARE_DYNCREATE(CGenericMDIApplicationView)

// Attributes
public:
    CGenericMDIApplicationDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
    virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
    virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
    virtual ~CGenericMDIApplicationView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    afx_msg void OnFilePrintPreview();
    afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
    DECLARE_MESSAGE_MAP()
    virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
};

#ifndef _DEBUG  // debug version in GenericMDIApplicationView.cpp
inline CGenericMDIApplicationDoc* CGenericMDIApplicationView::GetDocument() const
   { return reinterpret_cast<CGenericMDIApplicationDoc*>(m_pDocument); }
#endif

