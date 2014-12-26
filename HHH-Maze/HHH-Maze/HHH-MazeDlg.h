
// HHH-MazeDlg.h : ��� ����
//

#pragma once


namespace Dest
{
	enum Enum { UP, DOWN, LEFT, RIGHT };
}

enum PPP { UP, DOWN, LEFT, RIGHT };


// CHHHMazeDlg ��ȭ ����
class CHHHMazeDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CHHHMazeDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HHHMAZE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	enum { MAZE_X = 50, MAZE_Y = 50 };

	BOOL m_bMasked;
	int m_mapData[MAZE_X][MAZE_Y];
	std::vector<CPoint> m_vCursor;

	// ������ �޽��� �� �Լ�
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
