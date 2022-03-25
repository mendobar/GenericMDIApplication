
// GenericMDIApplicationDoc.cpp : implementation of the CGenericMDIApplicationDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GenericMDIApplication.h"
#endif

#include "GenericMDIApplicationDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGenericMDIApplicationDoc

IMPLEMENT_DYNCREATE(CGenericMDIApplicationDoc, CDocument)

BEGIN_MESSAGE_MAP(CGenericMDIApplicationDoc, CDocument)
END_MESSAGE_MAP()


// CGenericMDIApplicationDoc construction/destruction

CGenericMDIApplicationDoc::CGenericMDIApplicationDoc() noexcept
{
    // TODO: add one-time construction code here

}

CGenericMDIApplicationDoc::~CGenericMDIApplicationDoc()
{
}

BOOL CGenericMDIApplicationDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    // TODO: add reinitialization code here
    // (SDI documents will reuse this document)

    return TRUE;
}




// CGenericMDIApplicationDoc serialization

void CGenericMDIApplicationDoc::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        // TODO: add storing code here
    }
    else
    {
        // TODO: add loading code here
    }
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CGenericMDIApplicationDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
    // Modify this code to draw the document's data
    dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

    CString strText = _T("TODO: implement thumbnail drawing here");
    LOGFONT lf;

    CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
    pDefaultGUIFont->GetLogFont(&lf);
    lf.lfHeight = 36;

    CFont fontDraw;
    fontDraw.CreateFontIndirect(&lf);

    CFont* pOldFont = dc.SelectObject(&fontDraw);
    dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
    dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CGenericMDIApplicationDoc::InitializeSearchContent()
{
    CString strSearchContent;
    // Set search contents from document's data.
    // The content parts should be separated by ";"

    // For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
    SetSearchContent(strSearchContent);
}

void CGenericMDIApplicationDoc::SetSearchContent(const CString& value)
{
    if (value.IsEmpty())
    {
        RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
    }
    else
    {
        CMFCFilterChunkValueImpl *pChunk = nullptr;
        ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
        if (pChunk != nullptr)
        {
            pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
            SetChunkValue(pChunk);
        }
    }
}

#endif // SHARED_HANDLERS

// CGenericMDIApplicationDoc diagnostics

#ifdef _DEBUG
void CGenericMDIApplicationDoc::AssertValid() const
{
    CDocument::AssertValid();
}

void CGenericMDIApplicationDoc::Dump(CDumpContext& dc) const
{
    CDocument::Dump(dc);
}
#endif //_DEBUG


// CGenericMDIApplicationDoc commands
