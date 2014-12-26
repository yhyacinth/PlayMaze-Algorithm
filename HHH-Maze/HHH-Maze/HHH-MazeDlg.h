
// HHH-MazeDlg.h : ��� ����
//

#pragma once


namespace Dest
{
	enum Enum { UP, DOWN, LEFT, RIGHT };
}


// CHHHMazeDlg ��ȭ ����
class CHHHMazeDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CHHHMazeDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HHHMAZE_DIALOG };

private:
	enum { 
		BASE_POS_X = 30,
		BASE_POS_Y = 60,
		BOARD_SIZE = 510
	};
	enum { MAZE_X = 25, MAZE_Y = 25 };

	BOOL m_bMasked;
	int m_mapData[MAZE_X][MAZE_Y];
	std::vector<CPoint> m_vCursor;
	HICON m_hIcon;

	void DrawBackground(CDC* dc);
	void MakeMaze();
	void ResetMaze();
	void LoadMask();
	void InitData();
	void SetData();
	
	// �����Դϴ�.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	DECLARE_MESSAGE_MAP()
};
