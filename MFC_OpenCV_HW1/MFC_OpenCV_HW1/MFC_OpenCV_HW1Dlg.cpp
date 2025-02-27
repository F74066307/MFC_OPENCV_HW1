
// MFC_OpenCV_HW1Dlg.cpp : 實作檔
//


#include "stdafx.h"
#include "MFC_OpenCV_HW1.h"
#include "MFC_OpenCV_HW1Dlg.h"
#include "afxdialogex.h"
#include  "opencv/cv.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_OpenCV_HW1Dlg 對話方塊



CMFC_OpenCV_HW1Dlg::CMFC_OpenCV_HW1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_OPENCV_HW1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_OpenCV_HW1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_OpenCV_HW1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton11)
	ON_EN_CHANGE(IDC_EDIT1, &CMFC_OpenCV_HW1Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFC_OpenCV_HW1Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFC_OpenCV_HW1Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CMFC_OpenCV_HW1Dlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFC_OpenCV_HW1Dlg::OnBnClickedButton12)
END_MESSAGE_MAP()


// CMFC_OpenCV_HW1Dlg 訊息處理常式

BOOL CMFC_OpenCV_HW1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
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

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定
	AllocConsole();
	FILE *fDummy;
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMFC_OpenCV_HW1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMFC_OpenCV_HW1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMFC_OpenCV_HW1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CMFC_OpenCV_HW1Dlg::OnBnClickedButton1()
{
	cvNamedWindow("hw1_1");
	IplImage* img1 = cvLoadImage("./res/Q1_Image/Uncle_Roger.jpg");
	printf("Height = %d\n", img1->height);
	printf("Width = %d\n", img1->width);
	cvShowImage("hw1_1", img1);
	cvWaitKey(0);
	cvReleaseImage(&img1);
	cvDestroyWindow("hw1_1");
	
}


void CMFC_OpenCV_HW1Dlg::OnBnClickedButton2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	
	IplImage* img1 = cvLoadImage("./res/Q1_Image/Flower.jpg", CV_LOAD_IMAGE_COLOR);
	
	
	IplImage *red = cvCreateImage(cvSize(img1->width,img1->height),img1->depth,3);
	IplImage *green = cvCreateImage(cvSize(img1->width, img1->height), img1->depth, 3);
	IplImage *blue = cvCreateImage(cvSize(img1->width, img1->height), img1->depth, 3);

	uchar *pImg = (uchar*)img1->imageData;
	uchar *pRed = (uchar*)red->imageData;
	uchar *pGreen = (uchar*)green->imageData;
	uchar *pBlue = (uchar*)blue->imageData;

	int i, j;
	for (i = 0; i < img1->height; i++) {
		for (j = 0; j<img1->width; j++) {
			pRed[i*img1->widthStep + j*img1->nChannels + 2] = pImg[i*img1->widthStep + j*img1->nChannels + 2];
			pRed[i*img1->widthStep + j*img1->nChannels + 1] = 0;
			pRed[i*img1->widthStep + j*img1->nChannels + 0] = 0;

			pGreen[i*img1->widthStep + j*img1->nChannels + 1] = pImg[i*img1->widthStep + j*img1->nChannels + 1];
			pGreen[i*img1->widthStep + j*img1->nChannels + 2] = 0;
			pGreen[i*img1->widthStep + j*img1->nChannels + 0] = 0;

			pBlue[i*img1->widthStep + j*img1->nChannels + 0] = pImg[i*img1->widthStep + j*img1->nChannels + 0];
			pBlue[i*img1->widthStep + j*img1->nChannels + 1] = 0;
			pBlue[i*img1->widthStep + j*img1->nChannels + 2] = 0;
		}
	}

	cvShowImage("hw1_2", img1);

	cvNamedWindow("hw1_2_R");
	cvShowImage("hw1_2_R", red);
	cvNamedWindow("hw1_2_G");
	cvShowImage("hw1_2_G", green);
	cvNamedWindow("hw1_2_B");
	cvShowImage("hw1_2_B", blue);


	
}


void CMFC_OpenCV_HW1Dlg::OnBnClickedButton3()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	cvNamedWindow("hw1_3");
	IplImage* img1 = cvLoadImage("./res/Q1_Image/Uncle_Roger.jpg");
	cvShowImage("hw1_3", img1);
	cvFlip(img1,0,1);
	cvNamedWindow("hw1_3_2");
	cvShowImage("hw1_3_2", img1);
}


const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;
Mat src1;
Mat src2;
Mat dst;

static void on_trackbar(int, void*)
{
	alpha = (double)alpha_slider / alpha_slider_max;
	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);
	imshow("Linear Blend", dst);
}



void CMFC_OpenCV_HW1Dlg::OnBnClickedButton4()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	src1 = imread("./res/Q1_Image/Uncle_Roger.jpg");
	
	flip(src1,src2,1);
	alpha_slider = 0;
	namedWindow("Linear Blend");
	char TrackbarName[50];
	
	createTrackbar("tracker", "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar);
	on_trackbar(alpha_slider, 0);
	waitKey(0);
}


void CMFC_OpenCV_HW1Dlg::OnBnClickedButton5()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src = imread("./res/Q2_Image/Cat.png");
	namedWindow("Result");
	Mat dst;
	medianBlur(src, dst, 7);
	imshow("Result",dst);
	waitKey(0);
}


void CMFC_OpenCV_HW1Dlg::OnBnClickedButton6()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src = imread("./res/Q2_Image/Cat.png");
	namedWindow("Result");
	Mat dst;
	GaussianBlur(src, dst, Size(3, 3), 0, 0);
	imshow("Result", dst);
	waitKey(0);
	
}


void CMFC_OpenCV_HW1Dlg::OnBnClickedButton7()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src = imread("./res/Q2_Image/Cat.png");
	namedWindow("Result");
	Mat dst;
	bilateralFilter(src, dst, 9,90,90);
	imshow("Result", dst);
	waitKey(0);
}

uchar cal_gauss_value(uchar *src,int row,int col,int width,int height) {
	double result = 0;
	double kernel[3][3] = {
		0.045,0.122,0.045,
		0.122,0.332,0.122,
		0.045,0.122,0.045
	};
	int i, j;
	uchar p;
	for (i = -1;i<=1;i++) {
		for (j = -1;j<=1;j++) {
			if (row+i<0||row+i>=height||col+j<0||col+j>=width) {
				p = 0;
			}
			else {
				p = src[col+j+(row+i)*width];
			}
			result = result + p*kernel[i+1][j+1];
		}
	}
	return (uchar)result;
}

void gauss(Mat src,Mat dst,int width,int height) {
	float x[9] = {-1,0,1,-1,0,1,-1,0,1};
	float y[9] = { -1,-1,-1,0,0,0,1,1,1 };
	int i,j;
	float c = 0;
	float all = 0;
	float s = 0.3*((3 - 1)*0.5 - 1) + 0.8;
	//s = 0.5;
	s = pow(s, 2);
	
	vector<float>g;
	for (i = 0;i<9;i++) {
		c = (exp((-1/(2*s))*(pow(x[i],2)+ pow(y[i], 2)))) / (2*CV_PI*s);
		g.push_back(c);
		all += c;
	}
	for (i = 0; i<3; i++) {
		for (j = 0;j<3;j++) {
			g[i * 3 + j] /= all;
			//printf("%f ",g[i*3+j]);
		}
		//printf("\n");
	}

	filter2D(src,dst,-1, Matx33f(g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8]));
	//filter2D(src, dst, -1, Matx33f(0.045, 0.122, 0.045, 0.122, 0.332, 0.122, 0.045, 0.122, 0.045));
}

void CMFC_OpenCV_HW1Dlg::OnBnClickedButton8()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src= imread("./res/Q3_Image/Chihiro.jpg");
	Mat gray;
	Mat result;
	cvtColor(src, gray, CV_BGR2GRAY);
	cvtColor(src, result, CV_BGR2GRAY);
	gauss(gray,result,gray.cols,gray.rows);
	namedWindow("Result");
	imshow("Result", result);
	
	
}

double sobel_max=0;
double sobel_min=255;
double sobel_avg = 0;
double cal_sobel_value(uchar *src, int row, int col, int width, int height) {
	double result = 0;
	int kernel[3][3] = {
		-1,0,1,
		-2,0,2,
		-1,0,1
	};
	int i, j;
	uchar p;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (row + i<0 || row + i >= height || col + j<0 || col + j >= width) {
				p = 0;
			}
			else {
				p = src[col + j + (row + i)*width];
			}
			result = result + p*kernel[i + 1][j + 1];
			
		}
		
	}
	if (sobel_max<result) {
		sobel_max = result;
	}
	if (sobel_min>result) {
		sobel_min =result;
	}
	if (result>255) {
		result = 255;
	}
	if (result<0) {
		result = 0;
	}
	sobel_avg += result;
	

	return result;
}

void norm_uchar(double *src, int size) {
	int i;
	sobel_avg = sobel_avg / size;
	for (i = 0; i<size; i++) {
		src[i] = (src[i] - sobel_min) / (sobel_max - sobel_min);
		src[i] = src[i]*255;
	}
}

void sobelx(uchar* src, uchar* dst, int width, int height) {
	int i, j;
	double *r = (double*)malloc(sizeof(double)*width*height);
	vector<double>r2;
	for (i = 0; i<height; i++) {
		for (j = 0; j<width; j++) {
			r[i*width + j] = cal_sobel_value(src, i, j, width, height);
			r2.push_back(cal_sobel_value(src, i, j, width, height));
		}
	}
	//norm_uchar(r, width*height);
	//normalize(r2,r2, 0, 255, NORM_MINMAX);
	for (int i = 0;i<width*height;i++) {
		dst[i] = (uchar)r[i];
	}
}

double cal_sobel_value_y(uchar *src, int row, int col, int width, int height) {
	double result = 0;
	double kernel[3][3] = {
		1,2,1,
		0,0,0,
		-1,-2,-1
	};
	int i, j;
	uchar p;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (row + i<0 || row + i >= height || col + j<0 || col + j >= width) {
				p = 0;
			}
			else {
				p = src[col + j + (row + i)*width];
			}
			result = result + p*kernel[i + 1][j + 1];
		}
	}
	if (sobel_max<result) {
		sobel_max = result;
	}
	if (sobel_min>result) {
		sobel_min = result;
	}

	if (result>255) {
		result = 255;
	}
	if (result<0) {
		result = 0;
	}

	return result;
}

void sobely(uchar* src, uchar* dst, int width, int height) {
	int i, j;
	double *r = (double*)malloc(sizeof(double)*width*height);
	for (i = 0; i<height; i++) {
		for (j = 0; j<width; j++) {
			r[i*width + j] = cal_sobel_value_y(src, i, j, width, height);
		}
	}
	//norm_uchar(r, width*height);
	for (int i = 0; i<width*height; i++) {
		dst[i] = (uchar)r[i];
	}
}



void CMFC_OpenCV_HW1Dlg::OnBnClickedButton9()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src = imread("./res/Q3_Image/Chihiro.jpg");
	Mat gray;
	Mat result;
	Mat result_sobelx;
	cvtColor(src, gray, CV_BGR2GRAY);
	cvtColor(src, result, CV_BGR2GRAY);
	cvtColor(src, result_sobelx, CV_BGR2GRAY);
	gauss(gray, result, gray.cols, gray.rows);
	//GaussianBlur(gray, result, Size(3, 3), 0, 0);
	int kernel[3][3] = {
		-1,0,1,
		-2,0,2,
		-1,0,1
	};
	filter2D(result, result_sobelx,-1,Matx33f(-1,0,1,-2,0,2,-1,0,1));
	//sobelx(result.data, result_sobelx.data, gray.cols, gray.rows);
	//Sobel(result,result_sobelx, CV_8UC1, 1, 0, 3);
	namedWindow("Result");
	imshow("Result", result_sobelx);
	

}


void CMFC_OpenCV_HW1Dlg::OnBnClickedButton10()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src = imread("./res/Q3_Image/Chihiro.jpg");
	Mat gray;
	Mat result;
	Mat result_sobely;
	cvtColor(src, gray, CV_BGR2GRAY);
	cvtColor(src, result, CV_BGR2GRAY);
	cvtColor(src, result_sobely, CV_BGR2GRAY);
	gauss(gray, result, gray.cols, gray.rows);
	//GaussianBlur(gray, result, Size(3, 3), 0, 0);
	double kernel[3][3] = {
		1,2,1,
		0,0,0,
		-1,-2,-1
	};
	filter2D(result, result_sobely, -1, Matx33f(1, 2, 1, 0, 0, 0, -1, -2, -1));
	//sobely(result.data, result_sobelx.data, gray.cols, gray.rows);
	//Sobel(result,result_sobelx, CV_8UC1, 1, 0, 3);
	namedWindow("Result");
	imshow("Result", result_sobely);

}


void CMFC_OpenCV_HW1Dlg::OnBnClickedButton11()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	Mat src = imread("./res/Q3_Image/Chihiro.jpg");
	Mat gray;
	Mat result;
	Mat result_sobelx;
	Mat result_sobely;
	Mat result_mag;
	cvtColor(src, gray, CV_BGR2GRAY);
	cvtColor(src, result, CV_BGR2GRAY);
	cvtColor(src, result_sobelx, CV_BGR2GRAY);
	cvtColor(src, result_sobely, CV_BGR2GRAY);
	cvtColor(src, result_mag, CV_BGR2GRAY);

	gauss(gray, result, gray.cols, gray.rows);
	
	//sobelx(result.data, result_sobelx.data, gray.cols, gray.rows);
	filter2D(result, result_sobelx, -1, Matx33f(-1, 0, 1, -2, 0, 2, -1, 0, 1));
	filter2D(result, result_sobely, -1, Matx33f(1, 2, 1, 0, 0, 0, -1, -2, -1));
	//sobely(result.data, result_sobely.data, gray.cols, gray.rows);

	int i;
	for (i = 0;i<result.cols*result.rows;i++) {
		result_mag.data[i] = (uchar)sqrt(pow((double)result_sobelx.data[i],2)+pow((double)result_sobely.data[i], 2));
	}
	namedWindow("Result");
	imshow("Result", result_mag);
}

int rotation = 30;
double scaling = 0.9;
int tx = 200;
int ty = 300;

void CMFC_OpenCV_HW1Dlg::OnEnChangeEdit1()
{
	CEdit *wEdit;
	wEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString s;
	UpdateData(true);
	wEdit->GetWindowTextW(s);
	rotation= _tstoi(s);
	s.ReleaseBuffer();
}


void CMFC_OpenCV_HW1Dlg::OnEnChangeEdit2()
{
	CEdit *wEdit;
	wEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
	CString s;
	//UpdateData(true);
	wEdit->GetWindowTextW(s);
	scaling = _ttof(s);
	printf("%f\n", scaling);
	
}


void CMFC_OpenCV_HW1Dlg::OnEnChangeEdit3()
{
	CEdit *wEdit;
	wEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
	CString s;
	UpdateData(true);
	wEdit->GetWindowTextW(s);
	tx = _tstoi(s);
	s.ReleaseBuffer();
}


void CMFC_OpenCV_HW1Dlg::OnEnChangeEdit4()
{
	CEdit *wEdit;
	wEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
	CString s;
	UpdateData(true);
	wEdit->GetWindowTextW(s);
	ty = _tstoi(s);
	s.ReleaseBuffer();
}


void CMFC_OpenCV_HW1Dlg::OnBnClickedButton12()
{
	Mat src = imread("./res/Q4_Image/Parrot.png");
	Mat trans_r;
	Mat scaling_r;
	Mat rotate_r;
	Mat dst;
	namedWindow("Origin");
	imshow("Origin", src);
	resize(src, scaling_r, src.size(), scaling, scaling);
	warpAffine(scaling_r,trans_r,Matx23f(1,0,tx,0,1,ty),src.size());
	
	Mat rotation_mat= getRotationMatrix2D(Point2f(160+tx, 200+ty), rotation, 1);;
	warpAffine(trans_r, rotate_r, rotation_mat, src.size());
	namedWindow("Result");

	imshow("Result", rotate_r);
}
