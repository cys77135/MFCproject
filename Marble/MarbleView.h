
// MarbleView.h : CMarbleView 클래스의 인터페이스
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
	CString Name = _T(""); // 이름
	int Color; // Nothing=0, Purple=1, Skyblue=2, Pink=3, Orange=4, Red=5, Yellow=6, Green=7, Blue = 8
	int Price; // 가격
	int Owner = 0; // No One else = 0, Player1 = 1, Player2 = 2
	BOOL DesertIsland; //무인도인가?
	BOOL GoldKey;
};

struct Player {
	int Money = 293; // 보유 금액
	struct Color; //건물 지을 수 있는지 확인하기 위한
};


class CMarbleView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMarbleView();
	DECLARE_DYNCREATE(CMarbleView)

// 특성입니다.
public:
	CMarbleDoc* GetDocument() const;
	CStatic m_Player1;
	CStatic m_Player2;
	CStatic m_explain1;	//p1의 국가
	CStatic m_explain2;	//p2의 국가
	CStatic m_explain3;	//p1의 황금열쇠
	CStatic m_explain4;	//p2의 황금열쇠
	CStatic m_p1Money;	//p1의 보유 금액
	CStatic m_p2Money;	//p2의 보유 금액

	CBitmapButton m_Dice;		//주사위 버튼
	CListBox m_p1NationList;	//p1의 보유 나라 리스트
	CListBox m_p2NationList;	//p2의 보유 나라 리스트
	CListBox m_p1GoldKeyList;	//p1의 보유 황금 열쇠 리스트
	CListBox m_p2GoldKeyList;	//p2의 보유 황금 열쇠 리스트

	Player player1;
	Player player2;
	Country Country[36];  //나라

	CString str1, str2;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMarbleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();
	void OnButtonClicked();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

};

#ifndef _DEBUG  // MarbleView.cpp의 디버그 버전
inline CMarbleDoc* CMarbleView::GetDocument() const
   { return reinterpret_cast<CMarbleDoc*>(m_pDocument); }
#endif

