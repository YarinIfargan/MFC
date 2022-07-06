
// MFCPainterDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCPainter.h"
#include "MFCPainterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCPainterDlg dialog


CMFCPainterDlg::CMFCPainterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPAINTER_DIALOG, pParent)
	, Bold(false)
{
	isPressed = false;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

BEGIN_MESSAGE_MAP(CMFCPainterDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CMFCPainterDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CMFCPainterDlg::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CMFCPainterDlg::OnNMCustomdrawSlider3)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCPainterDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCPainterDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCPainterDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCPainterDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCPainterDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCPainterDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCPainterDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCPainterDlg::OnBnClickedButton3)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCPainterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCPainterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIODIAMOND, &CMFCPainterDlg::OnBnClickedRadiodiamond)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCPainterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCPainterDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_RADIO8, &CMFCPainterDlg::OnBnClickedRadio8)
	ON_WM_CTLCOLOR()
//ON_BN_CLICKED(IDC_BUTTON6, &CMFCPainterDlg::OnBnClickedButton6)
	ON_COMMAND(ID_FILE_OPEN32771, &CMFCPainterDlg::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE32772, &CMFCPainterDlg::OnFileSave)
	ON_COMMAND(ID_HELLO, &CMFCPainterDlg::OnHello)
	ON_COMMAND(ID_NOTEPAD, &CMFCPainterDlg::OnNotepad)
	ON_BN_CLICKED(IDC_OK, &CMFCPainterDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO7, &CMFCPainterDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO9, &CMFCPainterDlg::OnBnClickedRadio9)
END_MESSAGE_MAP()


// CMFCPainterDlg message handlers

BOOL CMFCPainterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	r.left = 180;
	r.top = 570;
	r.right = 1080;
	r.bottom = 35;
  
	M_Brush.CreateSolidBrush(RGB(23, 211, 240)); // background Color

	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RADIO1, IDC_RADIO3, IDC_RADIO1); // radio1 default

	m_red.SetRangeMax(255); // Fill colors
	m_red.SetRangeMin(0);
	m_green.SetRangeMax(255);
	m_green.SetRangeMin(0);
	m_blue.SetRangeMax(255);
	m_blue.SetRangeMin(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CMFCPainterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);

		dc.Rectangle(180, 570, 1080, 35); // white rectangle for paint
		CBrush border(RGB(255, 255, 255));
		CBrush *oldBorder = dc.SelectObject(&border);
		dc.SelectObject(&oldBorder);
		
		for (int i = 0; i < figs.GetSize(); i++) // the colosrs we selected on the sliders
			figs[i]->Draw(&dc);

		CBrush brush(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
		CBrush *oldBrush = dc.SelectObject(&brush);
		
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCPainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCPainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_red);
	DDX_Control(pDX, IDC_SLIDER2, m_green);
	DDX_Control(pDX, IDC_SLIDER3, m_blue);
	DDX_Check(pDX, IDC_CHECK1, Bold);
}


void CMFCPainterDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	isPressed = true;
	start = point;

	MoveIndex = -1;
		for (int i = (figs.GetSize() - 1); i >= 0; i--) {
			if (figs[i]->isInside(point)) {
				MoveIndex = i;
				break;
			}
		}

		if (MoveIndex == -1) {
			Figure *n = NULL;

			switch (futureFigureKind)
			{
			case 1:
				n = new Segment(start, start, Bold); // for Clear, Undo and Redo
				break;
			case 2:
				n = new Square(start, start, Bold); // for Clear, Undo and Redo
				break;
			case 3:
				n = new RectangleM(start, start, Bold); // for Clear, Undo and Redo
				break;
			case 4:
				n = new EllipseM(start, start, Bold); // for Clear, Undo and Redo
				break;
			case 5:
				n = new Circle(start, start, Bold); // for Clear, Undo and Redo
				break;
			case 6:
				n = new Triangle(start, start, Bold); // for Clear, Undo and Redo
				break;
			case 7:
				n = new Trapeze(start, start, Bold); // for Clear, Undo and Redo
				break;
			case 8:
				n = new RTriangle(start, start, Bold); // for Clear, Undo and Redo
				break;
			case 9:
				n = new RTrapeze(start, start, Bold); // for Clear, Undo and Redo
				break;
			case 10:
				n = new Hexagonal(start, start, Bold); // for Clear, Undo and Redo
				break;
			}

		figs.Add(n);

		n->setMBg(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
	
	}


	InvalidateRect(&r);

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCPainterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		end = point;
		if (MoveIndex == -1)
			figs[figs.GetSize() - 1]->Redefine(start, end);
		if (MoveIndex != -1)
		{
			CPoint c = figs[MoveIndex]->getP1();
			figs[MoveIndex]->Shift(point, c);
		}

		InvalidateRect(&r); //simulates the WM_PAINT message to redraw window
	}


	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCPainterDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		end = point;
		isPressed = false;
		if (MoveIndex == -1)
			figs[figs.GetSize() - 1]->Redefine(start, end);
	}

	MoveIndex = -1;
	InvalidateRect(&r); //simulates the WM_PAINT message to redraw window

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCPainterDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	*pResult = 0;
}


void CMFCPainterDlg::OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	*pResult = 0;
}


void CMFCPainterDlg::OnNMCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	*pResult = 0;
}


void CMFCPainterDlg::OnBnClickedRadio1()
{
	futureFigureKind = 1;
}


void CMFCPainterDlg::OnBnClickedRadio2()
{
	futureFigureKind = 2;
}


void CMFCPainterDlg::OnBnClickedRadio3()
{
	futureFigureKind = 3;
}


void CMFCPainterDlg::OnBnClickedRadio4()
{
	futureFigureKind = 4;
}


void CMFCPainterDlg::OnBnClickedRadio5()
{
	futureFigureKind = 5;
}


void CMFCPainterDlg::OnBnClickedRadio6()
{
	futureFigureKind = 6;
}


void CMFCPainterDlg::OnBnClickedRadiodiamond()
{
	futureFigureKind = 7;
}

void CMFCPainterDlg::OnBnClickedRadio7()
{
	futureFigureKind = 9;
}

void CMFCPainterDlg::OnBnClickedRadio8()
{
	futureFigureKind = 8;
}

void CMFCPainterDlg::OnBnClickedRadio9()
{
	futureFigureKind = 10;
}

void CMFCPainterDlg::OnBnClickedCheck1()
{
	UpdateData(true);
}

void CMFCPainterDlg::OnBnClickedButton3() // clear
{
	figs.RemoveAll();

	while (!undo.empty())
		undo.pop();
	InvalidateRect(&r);
}


void CMFCPainterDlg::OnBnClickedButton2() // save
{
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CMFCPainterDlg::OnBnClickedButton1() // load
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();

		InvalidateRect(&r);
	}
}


void CMFCPainterDlg::OnBnClickedButton4() // undo
{
	if (figs.GetSize() >= 1) {
		Figure *figure = figs[figs.GetSize() - 1];
		figs.RemoveAt(figs.GetSize() - 1, 1);
		undo.push(figure);

		InvalidateRect(&r);
	}
}


void CMFCPainterDlg::OnBnClickedButton5() // redo
{
	if (!undo.empty()){
		Figure *figure = undo.top();
		figs.Add(figure);
		undo.pop();

		InvalidateRect(&r);
	}
}

HBRUSH CMFCPainterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) // background color
{
	// TODO:  Change any attributes of the DC here
	return M_Brush;
}


//void CMFCPainterDlg::OnBnClickedButton6()
//{
//	CColorDialog dcolor;
//	if (dcolor.DoModal() == IDOK)
//	{
//		bgColor = dcolor.GetColor();
//	}
//}


void CMFCPainterDlg::OnLButtonDblClk(UINT nFlags, CPoint point) // useless
{
	CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CMFCPainterDlg::OnFileOpen()
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||")); // TRUE to Open
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CMFCPainterDlg::OnFileSave()
{
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||")); // FALSE to Save
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CMFCPainterDlg::OnNotepad()
{
	WinExec("notepad.exe", SW_SHOW);
}


void CMFCPainterDlg::OnHello()
{
	AfxMessageBox(L"Hello dear user!  \nThanks for using our app :)");
}


void CMFCPainterDlg::OnBnClickedOk()
{
	int message = AfxMessageBox(L"?Are you sure", MB_YESNO | MB_ICONINFORMATION | MB_RTLREADING); // another features: | MB_ICONERROR | MB_RTLREADING
	if (message == IDYES)
		CDialogEx::OnOK();
}
