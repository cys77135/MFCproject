
// MarbleView.cpp : CMarbleView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Marble.h"
#endif

#include "MarbleDoc.h"
#include "MarbleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMarbleView

IMPLEMENT_DYNCREATE(CMarbleView, CView)

BEGIN_MESSAGE_MAP(CMarbleView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(101, OnButtonClicked)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMarbleView ����/�Ҹ�

CMarbleView::CMarbleView()
{
	
}

CMarbleView::~CMarbleView()
{
}

BOOL CMarbleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMarbleView �׸���

void CMarbleView::OnDraw(CDC* pDC)
{
	CClientDC dc(this);
	CMarbleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

		str1.Format(_T("������ �ݾ�: %d ����"), player1.Money);
		str2.Format(_T("������ �ݾ�: %d ����"), player2.Money);
		m_p1Money.SetWindowText(str1);
		m_p2Money.SetWindowText(str2);
		
	CString strImagePath1 = _T("C:\\Visual Studio Programming\\Marble\\WallPaper.png");
	CString strImagePath = _T("C:\\Visual Studio Programming\\Marble\\�ɺ��� ����.png");
	CImage Image;
	CImage Image1;
	
	HRESULT hResult = Image.Load(strImagePath);
	HRESULT hResult1 = Image1.Load(strImagePath1);
	
	if (FAILED(hResult))
	{
		CString strtmp = _T("ERROR : Failed to load");
		strtmp += strImagePath + _T("\n");
		TRACE(strtmp);
		return;
	}

	// ���� �̹���
	
	Image1.TransparentBlt(dc.m_hDC, 0, 0, Image1.GetWidth(), Image1.GetHeight(), RGB(255, 0, 0));
	Image1.BitBlt(dc.m_hDC, 0, 0);
	Image.TransparentBlt(dc.m_hDC, 0, 0, Image.GetWidth(), Image.GetHeight(), RGB(255, 0, 0));
	Image.BitBlt(dc.m_hDC, 0, 0);

	
	

}


// CMarbleView �μ�

BOOL CMarbleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMarbleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMarbleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMarbleView ����

#ifdef _DEBUG
void CMarbleView::AssertValid() const
{
	CView::AssertValid();
}

void CMarbleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMarbleDoc* CMarbleView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMarbleDoc)));
	return (CMarbleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMarbleView �޽��� ó����


int CMarbleView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	str1.Format(_T("������ �ݾ�: %d ����"), player1.Money);
	str2.Format(_T("������ �ݾ�: %d ����"), player2.Money);

	m_Player1.Create(_T("��Player 1"), WS_CHILD | WS_VISIBLE, CRect(860, 70, 930, 85), this, 102);  //102�� ID��
	m_Player2.Create(_T("��Player 2"), WS_CHILD | WS_VISIBLE, CRect(860, 330, 930, 345), this, 103);
	m_explain1.Create(_T("������ ����"), WS_CHILD | WS_VISIBLE, CRect(900, 100, 985, 115), this,104);
	m_explain2.Create(_T("������ ����"), WS_CHILD | WS_VISIBLE, CRect(900, 360, 985, 375), this, 105);
	m_explain3.Create(_T("������ Ȳ�ݿ���"), WS_CHILD | WS_VISIBLE, CRect(1100, 100, 1217, 115), this, 106);
	m_explain4.Create(_T("������ Ȳ�ݿ���"), WS_CHILD | WS_VISIBLE, CRect(1100, 360, 1217, 375), this, 107);
	m_p1Money.Create(str1, WS_CHILD | WS_VISIBLE, CRect(900, 270, 1040, 285), this, 108);
	m_p2Money.Create(str2, WS_CHILD | WS_VISIBLE, CRect(900, 530, 1040, 545), this, 109);

	m_p1NationList.Create(WS_CHILD | WS_VISIBLE | LBS_STANDARD | WS_HSCROLL, CRect(900, 120, 1060, 260), this, 200);
	m_p2NationList.Create(WS_CHILD | WS_VISIBLE | LBS_STANDARD | WS_HSCROLL, CRect(900, 380, 1060, 520), this, 201);
	m_p1GoldKeyList.Create(WS_CHILD | WS_VISIBLE | LBS_STANDARD | WS_HSCROLL, CRect(1100, 120, 1260, 260), this, 202);
	m_p2GoldKeyList.Create(WS_CHILD | WS_VISIBLE | LBS_STANDARD | WS_HSCROLL, CRect(1100, 380, 1260, 520), this, 203);
	
	m_Dice.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, CRect(1250, 520, 1350, 620), this, 101);
	m_Dice.LoadBitmaps(IDB_BITMAP1,IDB_BITMAP2, IDB_BITMAP2, IDB_BITMAP2);

	return 0;
}


void CMarbleView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	
	
}



void CMarbleView::OnButtonClicked() //�ֻ��� ��ư
{
	
	Invalidate();
}





void CMarbleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	player1.Money += 3;
	str1.Format(_T("������ �ݾ�: %d ����"), player1.Money);
	MessageBox(str1);
	
	
	CView::OnLButtonDown(nFlags, point);
}


