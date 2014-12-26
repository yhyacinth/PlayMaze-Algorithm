
// HHH-MazeDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "HHH-Maze.h"
#include "HHH-MazeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHHHMazeDlg 대화 상자



CHHHMazeDlg::CHHHMazeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHHHMazeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHHHMazeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHHHMazeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHHHMazeDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHHHMazeDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CHHHMazeDlg 메시지 처리기

BOOL CHHHMazeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// 여기에 추가 초기화 작업을 추가합니다.
	// 컨트롤 설정
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);

	InitData();
	//DrawBackground();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CHHHMazeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CHHHMazeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		DrawBackground(&dc);
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CHHHMazeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CHHHMazeDlg::DrawBackground(CDC* dc)
{
	// Draw Background
	CPen pen(PS_SOLID, 1, RGB(150, 150, 150));
	CPen* oldPen;
	CBrush brush(RGB(0, 0, 0));
	CBrush* oldBrush;

	oldPen = dc->SelectObject(&pen);
	oldBrush = dc->SelectObject(&brush);
	dc->Rectangle(50, 50, 555, 555);
	dc->SelectObject(oldPen);
	dc->SelectObject(oldBrush);
}

void CHHHMazeDlg::SetData()
{
	// Set Random Data
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAZE_X; ++i)	
	{
		for (int j = 0; j < MAZE_Y; ++j)
		{
			if (m_mapData[i][j] != INT_MAX)
				m_mapData[i][j] = rand() % 100;
			// Debug print maze point
#if 0
			CString str;
			str.Format(L"%d", m_mapData[i][j]);

			CClientDC dc(this);

			CFont font;
			font.CreateFont(8,0,0,0,FW_BOLD,0,0,0,0,0,0,2,0,_T("Gulim"));
			dc.SelectObject(&font);

			dc.TextOutW(51 + i * 10, 51 + j * 10, str);
#endif
		}
	}
	m_mapData[0][0] = UINT_MAX; // Start Position
}

void CHHHMazeDlg::MakeMaze()
{
	// Prim's algorithm
	// Draw maze 
	CClientDC dc(this);
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen* oldPen;
	CBrush brush(RGB(255, 255, 255));
	CBrush* oldBrush;

	oldPen = dc.SelectObject(&pen);
	oldBrush = dc.SelectObject(&brush);

	// Init
	int i = 27;
	int j = 0;
	int cnt = 0;
	CPoint pt;
	pt.x = i;
	pt.y = j;
	m_vCursor.push_back(pt); // Set default end point

	// Run
	while (1)
	{
		Dest::Enum dest = Dest::UP;
		int dest_pt = INT_MAX;
		BOOL erase_prev = FALSE;

		// Round current end points
		for (auto iter = m_vCursor.begin(); iter != m_vCursor.end();)
		{
			if (iter->x > 0 && m_mapData[iter->x - 1][iter->y] < dest_pt)
			{
				dest = Dest::LEFT;
				dest_pt = m_mapData[iter->x - 1][iter->y];
				pt.x = iter->x - 1;
				pt.y = iter->y;
				i = iter->x;
				j = iter->y;
			}

			if (iter->y > 0 && m_mapData[iter->x][iter->y - 1] < dest_pt)
			{
				dest = Dest::UP;
				dest_pt = m_mapData[iter->x][iter->y - 1];
				pt.x = iter->x;
				pt.y = iter->y - 1;
				i = iter->x;
				j = iter->y;
			}

			if (iter->x < MAZE_X - 1 && m_mapData[iter->x + 1][iter->y] < dest_pt)
			{
				dest = Dest::RIGHT;
				dest_pt = m_mapData[iter->x + 1][iter->y];
				pt.x = iter->x + 1;
				pt.y = iter->y;
				i = iter->x;
				j = iter->y;
			}

			if (iter->y < MAZE_Y - 1 && m_mapData[iter->x][iter->y + 1] < dest_pt)
			{
				dest = Dest::DOWN;
				dest_pt = m_mapData[iter->x][iter->y + 1];
				pt.x = iter->x;
				pt.y = iter->y + 1;
				i = iter->x;
				j = iter->y;
			}
			
			// Check clear end-point
			if (iter->x > 0 && m_mapData[iter->x - 1][iter->y] == INT_MAX &&
				iter->y > 0 && m_mapData[iter->x][iter->y - 1] == INT_MAX &&
				iter->x < MAZE_X - 1 && m_mapData[iter->x + 1][iter->y] == INT_MAX &&
				iter->y < MAZE_Y - 1 && m_mapData[iter->x][iter->y + 1] == INT_MAX)
				iter = m_vCursor.erase(iter);
			else
				++iter;
		}
		// Round End

		m_mapData[pt.x][pt.y] = INT_MAX; // Used Mark
		m_vCursor.push_back(pt); // Save end-point

		// Exit condition
		if (dest_pt == INT_MAX) break;

		// Draw Graph
		//int base_x = 55 + i * 20;
		//int base_y = 55 + j * 20;
		//int width = 10;
		int base_x = 55 + i * 10;
		int base_y = 55 + j * 10;
		int width = 5;
		dc.Rectangle(base_x, base_y, base_x + width, base_y + width); // Current position
		// Direction
		switch (dest)
		{
		case Dest::UP:
			--j;
			dc.Rectangle(base_x, base_y - width * 2, base_x + width, base_y + width);
			break;
		case Dest::DOWN:
			++j;
			dc.Rectangle(base_x, base_y, base_x + width, base_y + width * 3);
			break;
		case Dest::LEFT:
			--i;
			dc.Rectangle(base_x - width * 2, base_y, base_x + width, base_y + width);
			break;
		case Dest::RIGHT:
			++i;
			dc.Rectangle(base_x, base_y, base_x + width * 3, base_y + width);
			break;
		default:
			break;
		}
		//Sleep(50);
	}
	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);

	for (auto iter = m_vCursor.begin(); iter != m_vCursor.end(); ++iter)
	{
		CString str;
		str.Format(L"%d; %d", iter->x, iter->y);
		OutputDebugString(str);
	}
}

void CHHHMazeDlg::InitData()
{
	CClientDC dc(this);
	DrawBackground(&dc);

	for (int i = 0; i < MAZE_X; ++i)	
	{
		for (int j = 0; j < MAZE_Y; ++j)
		{
			m_mapData[i][j] = 0;
		}
	}

	m_vCursor.clear();
}

void CHHHMazeDlg::OnBnClickedButton1()
{
	if (!m_bMasked)
		InitData();
	else
		m_vCursor.clear();
	SetData();
	MakeMaze();
}

void CHHHMazeDlg::LoadMask()
{
	CFileDialog dlg(TRUE, _T("*.*"), _T("*.bmp;*.png;*.jpg;*.gif"));
	int result = dlg.DoModal();
	if (result == IDOK)
	{
		CImage image;
		HRESULT hResult = image.Load(dlg.GetPathName());
		if (FAILED(hResult))
		{
			AfxMessageBox(_T("Failed to load image file"));
			return;
		}

		// Set Mask
		CBitmap bitmap;
		bitmap.Attach(image.Detach());
		BITMAP bm_info;
		bitmap.GetBitmap(&bm_info);

		int bm_bps = bm_info.bmBitsPixel / 8;
		int bm_size = bm_info.bmWidth * bm_info.bmHeight * bm_bps;
		BYTE *p_bit_pattern = new BYTE[bm_size];
		bitmap.GetBitmapBits(bm_size, p_bit_pattern);
		bitmap.Detach();

		int i = 0;
		int j = 0;
		for (int pos = 0; pos < bm_size; pos += bm_bps)
		{
			int red = p_bit_pattern[2 + pos];
			int green = p_bit_pattern[1 + pos];
			int blue = p_bit_pattern[pos];

			if (red == 0 &&
				green == 0 &&
				blue == 0)
			{
				m_mapData[i][j] = INT_MAX;
			}

			if (++i >= MAZE_Y)
			{
				i = 0;
				++j;
			}
			if (j >= MAZE_X)
				break;
		}
		m_bMasked = TRUE;

		delete[] p_bit_pattern;
	}
}

void CHHHMazeDlg::OnBnClickedButton2()
{
	LoadMask();
}
