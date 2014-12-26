
// HHH-MazeDlg.h : 헤더 파일
//

#pragma once


namespace Dest
{
	enum Enum { UP, DOWN, LEFT, RIGHT };
}

enum PPP { UP, DOWN, LEFT, RIGHT };


// CHHHMazeDlg 대화 상자
class CHHHMazeDlg : public CDialogEx
{
// 생성입니다.
public:
	CHHHMazeDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HHHMAZE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	enum { MAZE_X = 50, MAZE_Y = 50 };

	BOOL m_bMasked;
	int m_mapData[MAZE_X][MAZE_Y];
	std::vector<CPoint> m_vCursor;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void DrawBackground(CDC* dc);
	void MakeMaze();
	void InitData();
	void SetData();
	afx_msg void OnBnClickedButton2();
	void LoadMask();
};
