#pragma once
#include <stack>
#include "Figure.h"
#include "Segment.h"
#include "Rectangle.h"
#include "Square.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Triangle.h"
#include "RTriangle.h"
#include "Trapeze.h"
#include "RTrapeze.h"
#include "Hexagonal.h"
using namespace std;

// CMFCPainterDlg dialog
class CMFCPainterDlg : public CDialogEx
{
// Construction
public:
	CMFCPainterDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPAINTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CBrush M_Brush;

public:
	CSliderCtrl m_red;
	CSliderCtrl m_green;
	CSliderCtrl m_blue;
	BOOL Bold;
	COLORREF bg;
	RECT r;
	CPoint start, end;
	bool isPressed = false;
	int MoveIndex = -1;
	int futureFigureKind = 1;
	CTypedPtrArray< CObArray, Figure*> figs;
	stack <Figure*> undo;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadiodiamond();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedRadio8();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnNotepad();
	afx_msg void OnHello();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio9();
};

