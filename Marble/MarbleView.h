
// MarbleView.h : CMarbleView Ŭ������ �������̽�
//

#pragma once
struct Color {
	int Purple = 0; 
	int Skyblue = 0;
	int Pink = 0;
	int Orange = 0;
	int Red = 0;
	int Yellow = 0;
	int Green = 0;
	int Blue = 0;
};
struct Country {
	CString Name = _T(""); // �̸�
	int Color; // Nothing=0, Purple=1, Skyblue=2, Pink=3, Orange=4, Red=5, Yellow=6, Green=7, Blue = 8
	int Price; // ����
	int Owner = 0; // No One else = 0, Player1 = 1, Player2 = 2
	BOOL DesertIsland; //���ε��ΰ�?
	BOOL GoldKey;
};

struct Player {
	int Money = 293; // ���� �ݾ�
	struct Color; //�ǹ� ���� �� �ִ��� Ȯ���ϱ� ����
};


class CMarbleView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMarbleView();
	DECLARE_DYNCREATE(CMarbleView)

// Ư���Դϴ�.
public:
	CMarbleDoc* GetDocument() const;
	CStatic m_Player1;
	CStatic m_Player2;
	CStatic m_explain1;	//p1�� ����
	CStatic m_explain2;	//p2�� ����
	CStatic m_explain3;	//p1�� Ȳ�ݿ���
	CStatic m_explain4;	//p2�� Ȳ�ݿ���
	CStatic m_p1Money;	//p1�� ���� �ݾ�
	CStatic m_p2Money;	//p2�� ���� �ݾ�

	CBitmapButton m_Dice;		//�ֻ��� ��ư
	CListBox m_p1NationList;	//p1�� ���� ���� ����Ʈ
	CListBox m_p2NationList;	//p2�� ���� ���� ����Ʈ
	CListBox m_p1GoldKeyList;	//p1�� ���� Ȳ�� ���� ����Ʈ
	CListBox m_p2GoldKeyList;	//p2�� ���� Ȳ�� ���� ����Ʈ

	Player player1;
	Player player2;
	Country Country[36];  //����

	CString str1, str2;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMarbleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();
	void OnButtonClicked();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

};

#ifndef _DEBUG  // MarbleView.cpp�� ����� ����
inline CMarbleDoc* CMarbleView::GetDocument() const
   { return reinterpret_cast<CMarbleDoc*>(m_pDocument); }
#endif

